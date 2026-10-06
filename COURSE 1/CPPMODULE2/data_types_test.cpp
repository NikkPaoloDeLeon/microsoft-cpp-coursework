/// An activity to explore data type usage

/*
* Key Points

* Memory Efficiency: Different data types use different amounts of memory - choose the smallest type that can safely hold your data

* Type Limits: Every data type has a maximum and minimum value; exceeding these limits causes overflow or underflow

* Type Casting: Converting between types can result in data loss (like losing decimal places when casting double to int)

* Practical Applications: Understanding these concepts helps you choose appropriate data types for real-world applications like financial software or game development

* ❗ Common Mistakes to Avoid

* Using float for financial calculations where precision matters (use double instead)

* Not considering overflow when working with large numbers (consider long long for big values)

* Forgetting that type casting from larger to smaller types can lose information

* Using int for values that might exceed its range (like timestamps or large counts)  
*/

#include <iostream>
#include <climits>
#include <iomanip>
#include <string>

#pragma once

int main() {

    /// Define two variables
    short int variable1 {};
    long long int variable2  {};

    /// Declare variables of differnt data types
    int playerLevel {25};
    float itemPrice {10.99f};
    double precisionCalculation {3.14159265359};
    char playerRank {'A'};
    bool gameActive {true};

    // Display memory usage of each data type
    std::cout << std::string(5, '-') << "Memory Usage Analysis" << std::string(5, '-') << '\n';
    std::cout << std::left << std::setw(10) << "Int" << std::right << std::setw(10) << sizeof(int) << '\n';
    std::cout << std::left << std::setw(10) << "Float" << std::right << std::setw(10) << sizeof(float) << '\n';
    std::cout << std::left << std::setw(10) << "Doublle" << std::right << std::setw(10) <<sizeof(double) << '\n';
    std::cout << std::left << std::setw(10) << "Char" <<std::right <<std::setw(10) << sizeof(char) << '\n';
    std::cout << std::left << std::setw(10) << "Bool" << std::right << std::setw(10) << sizeof(bool) << '\n'; 
 
    
    // Print the size of each variablle in the console in the console
    std::cout << "The memory usage of variable1: " << sizeof(variable1) << '\n' << "The memoru usage of variable2 is: " << sizeof(variable2) << '\n';
    /// Time to test each data types limits
    std::cout << std::string(15, '=') << "Integer Limits and Overfllow" << std::string(15, '=') << '\n';
    std::cout << std::string(30, '-') << '\n';
    int maxValueInt {INT_MAX};
    std::cout << std::left << std::setw(10) << "Maximum Int Value" << std::right <<std::setw(15) << maxValueInt << '\n';
    std::cout << std::left << std::setw(10) << "What happens When we add 1?" << std::right << std::setw(15) << (maxValueInt + 1) << '\n';
    // Test type casting between different types
    std::cout << '\n' << std::string(10, '=') << "Type Casting Examples" << std::string(10, '=') << '\n';
    double precisePrice = 29.95;
    int roundPrice = static_cast<int>(precisePrice);
    // Print the output to the console to compare typecasting value of the original which is a doube
    std::cout << std::left << std::setw(10) << "Original Price (double):" << std::right << std::setw(15) << precisePrice << '\n';
    std::cout << std::left << std::setw(10) << "After casting to int:" <<std::right << std::setw(15) << roundPrice << '\n';

    /// Test character to Integer conversion
    std::cout << std::string(10, '-') << "Int to Char Conversion" << std::string(10, '-') << '\n';
    char letter {'C'};
    int letterValue {static_cast<int>(letter)};
    std::cout << std::left << std::setw(10) << "Character '" << letter << "' has ASCII value of: " << std::right << std::setw(15) << letterValue << '\n';
    
    return 0;
}