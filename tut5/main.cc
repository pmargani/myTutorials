// pointers to pointers
#include <iostream>
using namespace std;

int main()
{
  
  char a;
  char * b;
  char ** c;

  a = 'z';
  b = &a;
  c = &b;
  /*
  a 0x10 z
  b 0x20 0x10
  c 0x30 0x20
  */

  cout << "a: " << a << " " << &a << endl;
  cout << "b: " << b << " " << &b << " " << *b << endl;
  cout << "c: " << c << " " << &c << " " << *c << " " << **c <<  endl;

  return 0;
}
