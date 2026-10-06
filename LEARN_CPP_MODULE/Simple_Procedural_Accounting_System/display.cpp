/// This module is for the printing function of credit and debit balance

/// Include the header file for display
#include "display.h" 

/// Include I/O library
#include <iostream>

/// Include string library
#include <iomanip>

/// Include string library
#include <string>

void printWelcomeMessage() {
    std::cout << std::string(15, '-') << " Welcome Dear user! " << std::string(15, '-') << '\n';

}

void printCurrentBalance(double currentBalance) {
    /// Display Header of MyBank
    std::cout << std::string(40, '=') << '\n';
    std::cout << std::string(15, ' ') << "MyBank" << std::string(15, ' ') << '\n';
    std::cout << std::string(40, '=') << '\n';

    /// Table form the display of credit and debit
    std::cout << std::left << std::setw(15) << "User Account"  << std::right << std::setw(15) << "Existing Balance" << '\n'; 
    std::cout << std::left << std::setw(15) << "Jose P. Rizal" << std::right << std::setw(15) <<  currentBalance    << '\n';

}