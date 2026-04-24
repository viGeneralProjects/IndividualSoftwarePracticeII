/*
Name: Vi Cao
Course: CS3505
Assignment: Making a Class
*/

#include "Sine.h"
#include <iostream>
using std::cout;
using std::endl;

int main(){
    Sine sine(2.0, 222.0, 22.0);
    for (int i = 0; i < 361; i++)
    {
        cout << sine << endl;
        sine++;
    }
}