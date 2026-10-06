/*
PSEUDO CODE:

BEGIN
    REPEAT
        Display menu options
        Get user choice
        
        IF choice is valid THEN
            Get temperature value            
            IF choice is Celsius to Fahrenheit THEN
                result = (celsius * 9/5) + 32
                Display result
            ELSE IF choice is Fahrenheit to Celsius THEN
                result = (fahrenheit - 32) * 5/9
                Display result
            ELSE IF choice is exit THEN
                Exit program
            ELSE
                Display error message
            END IF            
        ELSE
            Display error message
        END IF        
        Ask if user wants to continue
        Get user response
    UNTIL user wants to exit
END
*/

// A temperature conversion system
// Header filles
#include <iostream>
#include <cmath>
#include <limits>
#include <string>
#include <iomanip>

// Forward declarations
void displayMenu();
int userChoice(const std::string& prompt);
double getValidDoubleTemperature(const std::string& prompt);
double celsiusToFahrenheitConversion(int celsius);
double fahrenheitToCelsiusConversion(int fahrenheit);
void routing(int choice);
void celsiusToFahrenheit();
void fahrenheitToCelsius();

int main() {
    bool exitProcess = false;
    do {
        int choice {0};
        displayMenu();
        choice = userChoice("Enter choice: ");
        routing(choice);
        if (choice == 3) {
            exitProcess = true;
        }
    } while (!exitProcess);
    return 0;
}

void displayMenu() {
    std::cout << '\n' << std::string(50, '=') << '\n';
    std::cout << std::string(15, ' ') << "TEMPERATURE CONVERTER" << '\n';
    std::cout << std::string(50, '=') << '\n';
    std::cout << "1. Celsius to Fahrenheit" << '\n';
    std::cout << "2. Fahrenheit to Celsius" << '\n';
    std::cout << "3. Exit" << '\n';
}

int userChoice(const std::string& prompt) {
    bool validInput {false};
    int value {0};
    do {
        std::cout << prompt;
        if (std::cin >> value && (value == 1 || value == 2 || value == 3) ) {
            validInput = true;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: Invalid input! Select only between 1 and 2." << '\n';
        }
    } while (!validInput);
    return value;
}

void routing(int userChoice) {
    switch (userChoice)
    {
    case 1:
        celsiusToFahrenheit();
        break;
    case 2:
        fahrenheitToCelsius();
        break;
    case 3:
        std::cout << "Thank you for using the convreter!" << '\n';
        exit;
        break;
    default:
        std::cout << "Error: Invalid Choice!" << '\n';
        break;
    }

}


void celsiusToFahrenheit() {
    double celsius {0.0}, fahrenheit {0.0};
    celsius = getValidDoubleTemperature("Enter temperature in celsius: ");
    fahrenheit = celsiusToFahrenheitConversion(celsius);
    std::cout << std::left << std::setw(20) << "Celsius" << std::right << std::setw(20) << "Fahrenheit" <<'\n';
    std::cout << std::left << std::setw(20) << celsius << std::right << std::setw(20) << fahrenheit <<'\n';
}
double celsiusToFahrenheitConversion(int celsius) {
    double result {0.0};
    result = (celsius * 9/5) + 32;
    return result;
}

double fahrenheitToCelsiusConversion(int fahrenheit) {
    double result {0.0};
    result = (fahrenheit - 32) * 5/9;
    return result;
}

void fahrenheitToCelsius() {
    double fahrenheit {0.0}, celsius {0.0};
    fahrenheit = getValidDoubleTemperature("Enter temperature in: ");
    celsius = fahrenheitToCelsiusConversion(fahrenheit);
    std::cout << std::left << std::setw(30) << "Fahrenheit" << std::right << std::setw(30) << "Celsius" <<'\n';
    std::cout << std::left << std::setw(30) << fahrenheit << std::right << std::setw(30) << celsius <<'\n';
}



double getValidDoubleTemperature(const std::string& prompt) {
    bool validInput {false};
    double value {0.0};
    do {
        std::cout << prompt;
        if (std::cin >> value) {
            validInput = true;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: Invalid input! Enter a number only" << '\n';
        }
    } while (!validInput);
    return value;
}