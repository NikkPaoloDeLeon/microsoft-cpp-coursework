// This is a mini calculator program
/*
* Showcase formatting 
* SHowcase use of variables
* We will use iostream, string, iomanip
* 
*/

#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdint>  



int main() {
    // This is to format the screen of the calculator
    int32_t number1 = INT_MAX;

    std::cout << std::string(30, '=') << '\n';
    std::cout << '=' << std::right << std::setw(23) << '5' << " + " << "10" << '=' << '\n';
    std::cout << '=' << std::right << std::setw(25) << (5 + 10) << '=' << std::endl;

}

