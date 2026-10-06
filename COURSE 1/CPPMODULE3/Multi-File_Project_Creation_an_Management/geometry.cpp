// Implementation of geometric calculations

// Include header file
#include "geometry.h"


double circleArea(double radius) {
    return M_PI * std::pow(radius, 2);
}

double circlePerimeter(double radius) {
    return 2 * M_PI * radius;
}

double rectangleArea(double length, double width) {
    return length * width;
}

double rectanglePerimeter(double length, double width) {
    return 2 * (length * width);
}