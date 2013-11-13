// void pointers
// strength: can point to any data type
// weakness: dereference operators can't be used with them, so can't access the data
#include <iostream>
using namespace std;

void increase (void* data, int psize)
{
  if ( psize == sizeof(char) )
  { 
    char* pchar;
    // typecast our void pointer
    pchar=(char*)data;
    // now we know how to use it
     ++(*pchar); 
  }
  else if (psize == sizeof(int) )
  { int* pint; pint=(int*)data; ++(*pint); }
}

int main ()
{
  char a = 'x';
  int b = 1602;
  cout << a << ", " << b << endl;
  increase (&a,sizeof(a));
  increase (&b,sizeof(b));
  cout << a << ", " << b << endl;

  // not to be confused with null pointers:
  int *p;
  p = 0; // null pointer
  return 0;
}
