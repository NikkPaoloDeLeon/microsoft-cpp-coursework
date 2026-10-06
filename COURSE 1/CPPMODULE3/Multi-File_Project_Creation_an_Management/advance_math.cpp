// Implementation of power and root functions

// Include header file
#include "advance_math.h"
#include <cmath>

double power(double number, int exponent) {
    return std::pow(number, exponent);
}

double squareRoot(double number) {
    return std::sqrt(number);
}

double absolute(double number) {
    int intNumber = static_cast<int>(number);
    return std::abs(intNumber);
}

double cube(double nunmber) {
    return std::pow(nunmber, 3);
}