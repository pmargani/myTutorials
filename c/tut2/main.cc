// more pointers: with arrays
#include <iostream>
using namespace std;

/*
The identifier of an array is equivalent to a pointer.
an array is a CONSTANT pointer, in that it will always point to 
the first element of the array.
*/

int main ()
{
  int numbers[5];
  int * p;
  p = numbers;  
  cout << " now p should be equivalent to first numbers: " << endl;
  cout << "numbers[0] value: " << numbers[0] << " address: " << &numbers[0] << endl;
  cout << "p value: " << p << " address: " << &p << "value of value: " << *p << endl;

  /*
  numbers 0x10 0
  p       0x80 0x10
  */

  // this is equivalent to numbers[0] = 10
  *p = 10;
  cout << "*p=10 value: " << p << " address: " << &p << "value of value: " << *p << endl;
  /*
  numbers 0x10 10
  p       0x80 0x10
  */
  p++; 
  cout << "p++ value: " << p << " address: " << &p << "value of value: " << *p << endl;
  int t = 0;
  cout << "sizeof(int): " << sizeof(t) << endl;
  cout << "so value of p should have gone up by 4 bytes" << endl;
  /*
  numbers 0x10 10
  p       0x80 0x20
  */

  // this is equivalent to numbers[1] = 20
  *p = 20;
  cout << "*p=20 value: " << p << " address: " << &p << "value of value: " << *p << endl;
  /*
  numbers 0x10 10
  nums[1] 0x14 20
  p       0x80 0x14
  */

  // now our pointer points to the address of the 3rd element
  p = &numbers[2];
  // and we assign 30 to numbers[2]
  *p = 30;

  /*
  numbers 0x10 10
  nums[1] 0x14 20
  nums[2] 0x18 30
  p       0x80 0x18
  */

  // since numbers was equivalent to the orignal p,
  // this is like p++ three times, or p = p + 3
  p = numbers + 3;
  // equivalent to numbers[3] = 40;
  *p = 40;


  /*
  numbers 0x10 10
  nums[1] 0x14 20
  nums[2] 0x18 30
  nums[3] 0x1c 40
  p       0x80 0x1c
  */

  // reset the pointer to beginning of array
  p = numbers;
  // advance the pointer by 4 sizeof(int)'s and give value there of 50
  *(p+4) = 50;

  /*
  numbers 0x10 10
  nums[1] 0x14 20
  nums[2] 0x18 30
  nums[3] 0x1c 40
  nums[4] 0x1g 50
  p       0x80 0x1g
  */

  for (int n=0; n<5; n++)
    cout << numbers[n] << ", ";
  return 0;
}
