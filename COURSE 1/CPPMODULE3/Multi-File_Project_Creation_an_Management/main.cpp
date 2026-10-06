// Main program that uses our library

// Include header files
#include <iostream>
#include <string>
#include "basic_math.h"
#include "advance_math.h"
#include "geometry.h"
#include "statistics.h"

int main() {
    std::string numbers = " 5 + 3 = ";
    std::cout << std::string(5, '=') << "Math Library Demonstration" << std::string(5, '=') << '\n';
    std::cout << '\n' << std::string(3, '-') << " Basic Math " << std::string(3, '-') << '\n';
    std::cout << "Addition: 5 + 3 = " << add(5, 3) << '\n';
    std::cout << "Subtraction:" << numbers << subtract(5, 3) << '\n';
    std::cout << "Multiplication:" << numbers << multiply(5, 3) << '\n';
    std::cout << "Divide:" << numbers << divide(5, 3) << '\n';
    std::cout << '\n' << std::string(3, '-') << " Advance Math " << std::string(3, '-') << '\n';
    std::cout << "Power: 2 ^ 3 = " << power(2, 3);  
    std::cout << "Square Root of 16 = " << squareRoot(16) << '\n';
    std::cout << "Absoulte value of -7.5 = " << absolute(-7.5) << '\n';
    std::cout << '\n' << std::string(3, '-') << " Geometry " << std::string(3, '-') << '\n';
    double radius {5.0};
    std::cout << "Cricle with radius " << radius << ": " << '\n';
    std::cout << "\tArea = " << circleArea(radius) << '\n';
    std::cout << "\tPerimeter = " << circlePerimeter(radius) << '\n';
    double length {4.0}, width {6.0};
    std::cout << "Rectangle with length " << length << "and width " << width << ": " << '\n';
    std::cout << "\tArea = " << rectangleArea(length, width) << '\n';
    std::cout << "\tPerimeter = " << rectanglePerimeter(length, width) << '\n';
    
    std::cout << '\n' << std::string(3, '-') << " Newly Added Mathematical Functions " << std::string(3, '-') << '\n';
    std::cout << "Cube of 3 = " << cube(3) << '\n';

    const std::vector<double> data {4.2, 7.8, 3.1, 9.5, 2.6};
    std::size_t vectorSize = data.size();

    std::cout << '\n' << std::string(3, '-') << " Statistics " << std::string(3, '-') << '\n';
    std::cout << "Data set: ";
    for (int i = 0; i < static_cast<int>(vectorSize); i++) {
        if (i == static_cast<int>(vectorSize-1)) {
            std::cout << data[i] << '\n';
        } else {
            std::cout << data[i] << ", ";
        }
    }
    std::cout << '\n';
    std::cout << "Minumum: " << minimum(data) << '\n';
    std::cout << "Maximum: " << maximum(data) << '\n';
    std::cout << "Average: " << average(data, vectorSize);


    return 0;
}