// pointer to functions
#include <iostream>
using namespace std;

int addition (int a, int b)
{ return (a+b); }

int subtraction (int a, int b)
{ return (a-b); }

// In order to declare a pointer to a function we have to declare it like the prototype of the function except that the name of the function is enclosed between parentheses () and an asterisk (*) is inserted before the name:
int operation (int x, int y, int (*functocall)(int,int))
{
  int g;
  g = (*functocall)(x,y);
  return (g);
}

int main ()
{
  int m,n;
  // In the example, minus is a pointer to a function that has two parameters of type int. It is immediately assigned to point to the function subtraction, all in a single line: 
  int (*minus)(int,int) = subtraction;

  cout << "addition: " << addition << endl;
  cout << "subtraction: " << subtraction << endl;

  m = operation (7, 5, addition);
  n = operation (20, m, minus);
  cout << "result: " << n << endl;
  return 0;
}
