// Header for geometric calculations

// Header guard
#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Forward declaration for geometry.cpp
double circleArea(double radius);
double circlePerimeter(double radius);
double rectangleArea(double length, double width);
double rectanglePerimeter(double lenght, double width);


#endif