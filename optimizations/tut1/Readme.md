#Tutorial1

[TOC]

##Introduction

This tutorial is supposed to illustrate how using certain optimizations changes how things are compiled.

##Steps

  * Build without optimization: g++ -I . -c -Wall -g MyClass.cc
  * Examine the object file:   objdump -dS MyClass.o.  Note the assembly by our multiplication:
      
              x[i] = x[i] * y[i];
        4c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
        50:	48 c1 e0 02          	shl    $0x2,%rax
        54:	48 03 45 e0          	add    -0x20(%rbp),%rax
        58:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
        5c:	48 c1 e2 02          	shl    $0x2,%rdx
        60:	48 03 55 e0          	add    -0x20(%rbp),%rdx
        64:	f3 0f 10 0a          	movss  (%rdx),%xmm1
        68:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
        6c:	48 c1 e2 02          	shl    $0x2,%rdx
        70:	48 03 55 d0          	add    -0x30(%rbp),%rdx
        74:	f3 0f 10 02          	movss  (%rdx),%xmm0
        78:	f3 0f 59 c1          	mulss  %xmm1,%xmm0
        7c:	f3 0f 11 00          	movss  %xmm0,(%rax)

  * Now build w/ optimization: g++ -I . -c -Wall -g -O3 MyClass.cc
  * Examine the object file:   objdump -dS MyClass.o.  Note that our multiplication now shows up 3 times.  We can see that we still call mulss, the scalar multiplication, but there is also a mulps, the vectorized multiplication in there as well.  Apparently, the scalar is in case it is not 16 byte-aligned, and the vector for when it is:

              x[i] = x[i] * y[i];
        3e:	0f 57 d2             	xorps  %xmm2,%xmm2
      
              x[i] = x[i] * y[i];
        50:	0f 28 c2             	movaps %xmm2,%xmm0
        53:	49 83 c1 01          	add    $0x1,%r9
        57:	0f 28 ca             	movaps %xmm2,%xmm1
        5a:	0f 12 07             	movlps (%rdi),%xmm0
        5d:	41 0f 12 08          	movlps (%r8),%xmm1
        61:	0f 16 47 08          	movhps 0x8(%rdi),%xmm0
        65:	41 0f 16 48 08       	movhps 0x8(%r8),%xmm1
        6a:	49 83 c0 10          	add    $0x10,%r8
        6e:	0f 59 c1             	mulps  %xmm1,%xmm0
        71:	0f 29 07             	movaps %xmm0,(%rdi)
        74:	48 83 c7 10          	add    $0x10,%rdi
        78:	4d 39 ca             	cmp    %r9,%r10
        7b:	77 d3                	ja     50 <_ZN7MyClass9normalizeEPfmS0_m+0x50>
        7d:	48 39 c2             	cmp    %rax,%rdx
        80:	74 56                	je     d8 <_ZN7MyClass9normalizeEPfmS0_m+0xd8>
        82:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
        88:	f3 0f 10 04 86       	movss  (%rsi,%rax,4),%xmm0
        8d:	f3 0f 59 04 81       	mulss  (%rcx,%rax,4),%xmm0
        92:	f3 0f 11 04 86       	movss  %xmm0,(%rsi,%rax,4)  

                x[i] = x[i] * y[i];
        c0:	f3 0f 10 04 86       	movss  (%rsi,%rax,4),%xmm0
        c5:	f3 0f 59 04 81       	mulss  (%rcx,%rax,4),%xmm0
        ca:	f3 0f 11 04 86       	movss  %xmm0,(%rsi,%rax,4)
 

 

  * What does the compiler say?  g++ -I . -c -Wall -g -O3 -ftree-vectorizer-verbose=5 MyClass.cc

      MyClass.cc:16: note:   Profitability threshold = 6
      MyClass.cc:16: note: Vectorization may not be profitable.
      MyClass.cc:16: note: create runtime check for data references *D.21273D.21273_13 and *D.21271D.21271_9
      MyClass.cc:16: note: created 1 versioning for alias checks.
      MyClass.cc:16: note: LOOP VECTORIZED.
      MyClass.cc:12: note: vectorized 1 loops in function.

  * MyClass.cc __restrict keyword has no affect on the build or the objdump

