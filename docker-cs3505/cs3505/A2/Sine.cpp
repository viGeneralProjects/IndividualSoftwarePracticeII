/*
Name: Vi Cao
Course: CS3505
Assignment: Making a Class
Description:
    Defines a Sine class that generates points along a sine curve using
    amplitude, wavelength (in degrees), and an angle increment (in degrees).
    It also supports ++ and <<.
*/

#include "Sine.h"
#include <cmath>
#include <iostream>

using std::cout;
using std::endl;

// Constructor
Sine::Sine(double amplitudeInitial, double wavelengthInitial, double angleIncrementInitial) {
    amplitude = amplitudeInitial;
    wavelength = wavelengthInitial;
    angleIncrement = angleIncrementInitial;
    angle = 0.0; // start at 0
}

// Getter for current angle (in degrees)
double Sine::currentAngle() {
    return angle;
}

// Getter for current height
// Formula: y = A * sin(2 * M_PI * angle / wavelength)
double Sine::currentHeight() {
    if (wavelength == 0.0) {
        return 0.0; // avoid division by zero
    }
    double phase = (2.0 * M_PI * angle) / wavelength;
    return amplitude * std::sin(phase);
}

// Prefix increment: ++sine
Sine& Sine::operator++() {
    angle += angleIncrement;
    return *this;
}

// Postfix increment: sine++
Sine Sine::operator++(int) {
    Sine temp = *this; // save old state
    angle += angleIncrement;
    return temp; // return previous value
}

// Insertion operator <<
// Format: "angle, height"
std::ostream& operator<<(std::ostream& os, Sine& s) {
    os << s.currentAngle() << ", " << s.currentHeight();
    return os;
}
