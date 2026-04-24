/*
Name: Vi Cao
Course: CS3505
Assignment: Facades and Makefiles
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "hpdf.h"
#include "HaruPDF.h"
#include "Sine.h"
#include <iostream>
using std::cout;
using std::endl; 

int main (int argc, char **argv)
{
    if(argc > 2){
       cout << "Error. Please Enter Text" << endl;
       return 0;
    }

    HaruPDF textPDF;
    unsigned int i;
    Sine sine(124, 622, 22); 
    const char* sampleText = argv[1];
    
    textPDF.CreatePDF(argv[0]);
    for (i = 0; i < strlen (sampleText); i++) {
        float x = (float)sine.currentAngle();
        float y = (float)sine.currentHeight() + 222; // vertical offset to not have the text default at the bottom
        textPDF.charOntoPage(sampleText[i], x, y);
        sine++;
    }

    textPDF.end_page();
    return 0;
}