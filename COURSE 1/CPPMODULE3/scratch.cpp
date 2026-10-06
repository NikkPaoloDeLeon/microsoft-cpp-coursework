#include <iostream>
#include <limits>
#include <string>

int getValidIntNumber(const std::string& prompt);
double getValidDoubleNumber(const std::string& prompt);

int main() {
    while (true) {
        char userChoice;
        int number1 = getValidIntNumber("Enter an integer: ");
        double number2 = getValidDoubleNumber("Enter a double: ");
        std::cout << "Integer number: " << number1 << '\n';
        std::cout << "Double number: " << number2 << '\n';

        std::cout << "New transaction? (Y) Yes or (N) No: ";
        std::cin >> userChoice;
        switch (userChoice) {
        case 'Y':
        case 'y':
            break;
        case 'N':
        case 'n':
            std::cout << "Thankyou!" << '\n';
            return 0;
        default:
            break;
        }
        return 0;
    }
    
    
    
    return 0;
}

int getValidIntNumber(const std::string& prompt) {
    bool validInput {false};
    int intNumber {0};
    do {
        std::cout << prompt;
        std::cin >> intNumber;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: Invalid Input! Enter Integer Only." << '\n';
            continue;
        }
        validInput = true;
    } while (!validInput);
    return intNumber;
}

double getValidDoubleNumber(const std::string& prompt) {
    bool validInput {false};
    double doubleNumber {0.0};
    do {
        std::cout << prompt;
        std::cin >> doubleNumber;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: Invalid input! Please enter a number." << '\n';
            continue;
        }
        validInput = true;
    } while (!validInput);
    return doubleNumber;
}