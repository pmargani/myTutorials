// pointer arithmetic
#include <iostream>
using namespace std;

int main() 
{
  cout << "sizeof(char): " << sizeof(char) << endl;
  cout << "sizeof(int): " << sizeof(int) << endl;
  cout << "sizeof(long): " << sizeof(long) << endl;

  char *mychars = "hello";
  int myints[] = {1,2,3,4,5};
  long mylongs[] = {1,2,3,4,5};

  char *pc = mychars;
  int *pi = myints;
  long *pl = mylongs;

  cout << "pointers: " << pc << " " << pi << " " << pl << endl;
  // should be: 'h', 1, 1
  cout << "pointers point to values: " << *pc << " " << *pi << " " << *pl << endl;
 
  // increment, and watch address's change by 'sizeof'
  pc++; pi++; pl++;
  cout << "pointers: " << pc << " " << pi << " " << pl << endl;
  cout << "pointers point to values: " << *pc << " " << *pi << " " << *pl << endl;
  
  return 0;

}
