#include <iostream>
using namespace std;

  // http://www.cplusplus.com/doc/tutorial/pointers/
  // pointer: stores a reference to another variable
  // & means 'give me the address of this variable'
  // * means 'value pointed by', 'dereference operator'
  // a variable referenced with & can be dereferenced with *.

int main ()
{
  // Part I
  int andy = 25;
  int fred;
  int *ted;
  int beth;

  // fred gets value of 25
  fred = andy;
  // ted gets address of 25;
  ted = &andy;
  // now beth get value of andy
  beth =  *ted;
  cout << "andy: " << andy << " fred: " << fred << " ted: " << ted << " beth: " << beth << endl;

  // Part II
  // these are both pointer typesi (occupy the same space in memory), that point to *different* types
  // and don't confuse this compound specifier (int *) with the dereference operator (*)
  int *t1;
  char *t2;
  cout << "pointer sizes: " << sizeof(t1) << ", " << sizeof(t2) << endl;

  // Part III
  int firstvalue, secondvalue;
  // pointer: stores a reference to another variable
  int * mypointer;

  // & means 'give me the address of this variable'
  mypointer = &firstvalue;
  *mypointer = 10;
  mypointer = &secondvalue;
  *mypointer = 20;
  cout << "firstvalue is " << firstvalue << endl;
  cout << "secondvalue is " << secondvalue << endl;

  // Part IV
  firstvalue = 5;
  secondvalue = 15;
  int * p1, * p2;

  /*
  note: addresses are arbitrary
  var name: address: value
  firstvalue: 0x10 : 5
  secondvalue: 0x20 : 15 
  p1: 0x30 : null or random
  p2: 0x40 : null or random
  */

  cout << "At first, vars look like: " << endl;
  cout << "firstvalue value: " << firstvalue << " address: " << &firstvalue << endl;
  cout << "p1 value: " << p1 << " address: " << &p1 << endl;
  p1 = &firstvalue;  // p1 = address of firstvalue
  p2 = &secondvalue; // p2 = address of secondvalue
  cout << "now p1: " << endl;
  cout << "p1 value: " << p1 << " address: " << &p1 << endl;

  /*
  firstvalue: 0x10 : 5
  secondvalue: 0x20 : 15 
  p1: 0x30 : 0x10 
  p2: 0x40 : 0x20
  */
  *p1 = 10;          // value pointed by p1 = 10
  *p2 = *p1;         // value pointed by p2 = value pointed by p1

  cout << "now: " << endl;
  cout << "firstvalue value: " << firstvalue << " address: " << &firstvalue << endl;
  cout << "secondvalue value: " << secondvalue << " address: " << &secondvalue << endl;
  cout << "p1 value: " << p1 << " address: " << &p1 << endl;
  cout << "p2 value: " << p2 << " address: " << &p2 << endl;

  /*
  firstvalue: 0x10 : 10
  secondvalue: 0x20 : 10 
  p1: 0x30 : 0x10 
  p2: 0x40 : 0x20
  */

  p1 = p2;           // p1 = p2 (value of pointer is copied)
  *p1 = 20;          // value pointed by p1 = 20
  
  cout << "now: " << endl;
  cout << "firstvalue value: " << firstvalue << " address: " << &firstvalue << endl;
  cout << "secondvalue value: " << secondvalue << " address: " << &secondvalue << endl;
  cout << "p1 value: " << p1 << " address: " << &p1 << endl;
  cout << "p2 value: " << p2 << " address: " << &p2 << endl;

  /*
  firstvalue: 0x10 : 10
  secondvalue: 0x20 : 20 
  p1: 0x30 : 0x20 
  p2: 0x40 : 0x20
  */

  return 0;
}
