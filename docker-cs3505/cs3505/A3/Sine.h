/*
Name: Vi Cao
Course: CS3505
Assignment: Facades and Makefiles
*/

#include <cmath>
#include <iostream>
using std::cout;
using std::endl;

class Sine {
private:
    /// @brief Peak height of the sine wave
    double amplitude;

    /// @brief Wavelength in degrees (distance between peaks)
    double wavelength;

    /// @brief Angle increment in degrees per step
    double angleIncrement;

    /// @brief Current angle in degrees (starts at 0)
    double angle = 0.0;

public:
    /// @brief Makes a sine curve starting at angle 0
    /// @param amplitudeInitial Peak height of the sine wave
    /// @param wavelengthInitial Distance (in degrees) between peaks
    /// @param angleIncrementInitial How much the angle increases each step
    Sine(double amplitudeInitial, double wavelengthInitial, double angleIncrementInitial);

    /// @brief Gets the current angle in degrees
    /// @return The current angle value
    double currentAngle();

    /// @brief Gets the current sine height at this angle
    /// @return The y value on the curve
    double currentHeight();

    /// @brief Moves to the next angle (prefix ++)
    /// @return Updated sine object
    Sine& operator++();

    /// @brief Moves to the next angle (postfix ++)
    /// @param Unused int to tell postfix apart from prefix
    /// @return Copy of sine before increment
    Sine operator++(int);
};

/// @brief Prints the sine’s angle and height
/// @param os Output stream
/// @param s Sine object to print
/// @return The stream with data written
std::ostream& operator<<(std::ostream& os, Sine& s);
