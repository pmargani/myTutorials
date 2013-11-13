  // pointer initialization
#include <iostream>
using namespace std;

int main ()
{
  // pointer initialization
  int number = 5;
  int *p = &number;

  // is equivalent to
  int number2 = 6;
  int *p2;
  p2 = &number2;
  
  cout << "p1 and p2 point to values: " << *p << " " << *p2 << endl;

  const char *terry = "hello";

  cout << "terry[4] looks like: " << terry[4] << endl;
  cout << "*terry:  " << *terry << endl;
  cout << "*(terry+4):  " << *(terry+4) << endl;
  return 0;

}
