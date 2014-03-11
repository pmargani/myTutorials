#include <iostream>

#include "MyClass.h"

using namespace std;

MyClass::MyClass() 
{
    cout << "MyClass::MyClass" << endl;
}

void MyClass::normalize(float *x, size_t xlen, float *y, size_t ylen) 
{
    //cout << "MyClass::normalize" << endl;

    for (size_t i = 0; i < xlen; i++ )
    {
        x[i] = x[i] * y[i];
    }

    /*
    int di = 0; 
    for (int i = 0; i < xlen; i++ )
    {
        float inverse_x = 1.0/x;
        for (int j = 0; i < jlen; i++ )
        {
            di = (i*numChans) + j;  
            y[di] = y[di]*inverse_x;
        }
       
    }
    */
}
