/// This module is for the implementation of the display using print functions

/// Includ the header file
#include "report_display.h"

/// Include the I/0 library
#include <iostream>

/// Include the table properties library
#include <iomanip>

/// Include the string libraries
#include <string>

/// Print the header 
void printSystemHeader() {
    std::cout << std::string(50, '=') << '\n';
    std::cout << std::string(10, ' ') << "OFFICIAL GRADE EVALUATION" << std::string(10, ' ') << '\n'; 
    std::cout << std::string(50, '=') << '\n';

}
/// Prints the breakdown of the total grade
void printComponentBreakdown(float weightPrelim, float weightMidterm, float weightFinal) {
    std::cout << std::string(20, '-') << "Total Grade Breakdown" << std::string(20, '-') << '\n';
    std::cout << std::left << std::setw(10) << "Term" << std::right << std::setw(10) << '\n';
    std::cout << std::left << std::setw(10) << "Prelim" << std::right << std::setw(10) << weightPrelim << '\n';
    std::cout << std::left << std::setw(10) << "Midterm" << std::right << std::setw(10) << weightMidterm << '\n';
    std::cout << std::left << std::setw(10) << "Final" << std::right << std::setw(10) << weightFinal << '\n';
}

/// Prints the final calculated grade
void printFinalScore(float finalScore) {
    std::cout << std::string(50, '-') << '\n';
    std::cout << std::left << std::setw(10) << "Final Score" << std::right << std::setw(10) << finalScore << '\n';
}

 

