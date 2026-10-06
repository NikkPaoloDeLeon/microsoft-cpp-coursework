// A simple fully functional menu driven calculator that responds intelligently to user choices using conditional logic
// Declare iostream and cmath(sqrt and power functions)
#include <iostream>
#include <cmath>
#include <string>
#include <limits>

// Forward declarations
void displayWelcomeMessage();
void displayMainmenu();
int getUserChoice();
bool processMenuChoice(int userChoice);
double addition(double num1, double num2);
double subtraction(double num1, double num2);
double multiplication(double num1, double num2);
double division(double num1, double num2);
double squareRoot(double num1);
double remainder(double num1, double num2);
double exponentiation(double num1, double num2); 
double absoluteValue(double num1);
void displayAdditionProcess();
void displaySubtractionProcess();
void displayMultiplicationProcess();
void displayDivisionProcess();
void displaySquareRootProcess();
void displayExponentiationProcess();
void displayRemainderProcess();
void displayAbsoluteValueProcess();
double getValidDoubleInput(const std::string& prompt);


int main() {
    bool exitProgram {false};
    while (!exitProgram) {
        displayWelcomeMessage();
        displayMainmenu();
        int userChoice {getUserChoice()}; 
        exitProgram = processMenuChoice(userChoice);
    }
    return 0;
}

// Displays the header of the system
void displayWelcomeMessage() {
    std::cout << '\n' << std::string(40, '=') << '\n';
    std::cout << '\t' << "INTERACTIVE CALCULATOR" << '\n';
    std::cout << std::string(40, '=') << '\n';
    std::cout << "This calculator allows you to perform" << '\n';
    std::cout << "various mathematical operations" << '\n';
}

// Displays the mainmenu
void displayMainmenu() {
    std::cout << '\n' << "\nPlease select an operation:" << '\n';
    std::cout << "1. Addition" << '\n';
    std::cout << "2. Subtraction" << '\n';
    std::cout << "3. Multiplication" << '\n';
    std::cout << "4. Divison" << '\n';
    std::cout << "5. Square Root" << '\n';
    std::cout << "6. Exponentiation" << '\n';
    std::cout << "7. Remainder" << '\n';
    std::cout << "8. Absolute Value" << '\n';
    std::cout << "9. Exit" << '\n'; 
}

// gets the user choice on the main menu and returns it
int getUserChoice() {
    int choice;
    std::cout << "\nEnter user choice: ";
    while (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input";
        displayMainmenu();
        std::cout << "\nEnter user choice: ";
        std::cin >> choice;
    }
    return choice; 
}

// Process menu choice
/*
bool processMenuChoice (int userChoice) {
    if (userChoice == 1) {
        displayAdditionProcess();
    } else if (userChoice == 2) {
        displaySubtractionProcess();
    } else if (userChoice == 3) {
        displayMultiplicationProcess();
    } else if (userChoice == 4) {
        displayDivisionProcess();
    } else if (userChoice == 5) {
        displaySquareRootProcess();
    } else if (userChoice == 6) {
        displayExponentiationProcess();
    } else if (userChoice == 7) {
        displayRemainderProcess();
    } else if (userChoice == 8) {
        displayAbsoluteValueProcess();
    } else if (userChoice == 9) {
        return true;
    } else {
        std::cout << "Invalid Input! Choose numbers from (1-9)" << '\n';
    }
    return false; 
}
*/

// Switch statements are better for discrete values.
// Change the if else structure above to a switch statement.
bool processMenuChoice(int userChoice) {
    switch (userChoice)
    {
    case 1:
        displayAdditionProcess();
        break;
    case 2: 
        displaySubtractionProcess();
        break;
    case 3:
        displayMultiplicationProcess();
        break;
    case 4:
        displayDivisionProcess();
        break;
    case 5:
        displaySquareRootProcess();
        break;
    case 6:
        displayExponentiationProcess();
        break;
    case 7:
        displayRemainderProcess();
        break;
    case 8: 
        displayAbsoluteValueProcess();
        break;
    case 9: 
        exit;
        break;
    default:
        std::cout << "Invalid Input! Choose numbers from (1-9)" << '\n';
        break;
    }
    return false;
}

// Gets 2 number and applies addition to it
void displayAdditionProcess() {
    bool continueProcess = true;
    bool hasLastResult = false;
    double lastResult {0.0}; 
    while (continueProcess) {
        double num1, num2;
        if (hasLastResult) {
            int useLastResult;
            std::cout << "Previous result: " << lastResult << '\n';
            std::cout << "Would you like to use the previous result? (1 for yes, 2 for no): ";
            std::cin >> useLastResult;  
            if (useLastResult == 1) {
                num1 = lastResult;
            } else if (useLastResult == 2) {
                num1 = getValidDoubleInput("Enter first number: ");
            } else {
                std::cout << "Invalid Input" << '\n';
                hasLastResult = true;
            }
        } else {
            num1 = getValidDoubleInput("Enter first number: ");

        }
        num2 = getValidDoubleInput("Enter second number: ");
        double result = addition(num1, num2);
        std::cout << "Result: " << num1 << " + " << num2 << " = " << result << '\n';

        lastResult = result;
        hasLastResult = true;

        char choice;
        std::cout << "Do you still want to do another addition? Y for Yes or N for No: ";
        std::cin >> choice;
        switch (choice) {
            case 'Y':
            case 'y':
                break;
            case 'N':
            case 'n':
                continueProcess = false; 
                break;
            default:
                std::cout << "Error: Invalid Input! " << '\n'; 
                break;
        } 
    }
 
}

// Gets2 number and applies subtraction to it
void displaySubtractionProcess() {
    bool continueProcess = true;
    bool hasLastResult = false;
    double lastResult;
    while (continueProcess) {
        double num1, num2;
        if (hasLastResult) {
            int choice;
            std::cout << "Previous result: " << lastResult << '\n';
            std::cout << "Would you like to use the previous result? (1 for yes, 2 for no): ";
            std::cin >> choice;
            if (choice == 1) {
                num1 = lastResult;
            } else if (choice == 2) {
                num1 = getValidDoubleInput("Enter first number: ");
            } else {
                std::cout << "Error: Invalid input!" << '\n';
                hasLastResult = true;
            }
        } else {
            num1 = getValidDoubleInput("Enter first number: ");
        }
        num2 = getValidDoubleInput("Enter second number: ");
        double result = subtraction(num1, num2);
        std::cout << "Result: " << num1 << " - " << num2 << " = " << result << '\n';
        lastResult = result;
        hasLastResult = true;

        char choice;
        std::cout << "Do you still want to do another addition? Y for Yes or N for No: ";
        std::cin >> choice;
        switch (choice) {
        case 'Y':
        case 'y':
            break;
        case 'N':
        case 'n':
            continueProcess = false;
        default:
            std::cout << "Error: Invalid input!" << '\n';
            break;
        }

    } 
}

// Gets 2 number and applies mulltipication to it
void displayMultiplicationProcess() {
    bool continueProcess = true;
    bool lastResultAvailalable = false;
    double lastResult {0.0};
    while (continueProcess) {
        double num1, num2;
        if(lastResultAvailalable) {
            bool validChoice = false;
            while(!validChoice) {
                int choice;
                std::cout << "Last Result saved is " << lastResult << '\n';
                std::cout << "Would you like to use last result? 1 for Yes and 2 for No: "; 
                std::cin >> choice;
                if (std::cin.fail()) {
                    std::cout << "Error: Invalid input! Please enter a number.\n";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    continue;
                } else if (choice == 1) {
                    num1 = lastResult;
                    validChoice = true;
                } else if (choice == 2) {
                    num1 = getValidDoubleInput("Enter first Number: ");
                    validChoice = true;
                } else {
                    std::cout << "Error: Invalid input!" << '\n';
                }
            }
        } else {
            num1 = getValidDoubleInput("Enter first number: ");
        }
        num2 = getValidDoubleInput("Enter second number: ");
        double result {multiplication(num1, num2)};
        std::cout << "Result: " << num1 << " * " << num2 << " = " << result << '\n';
        lastResult = result;
        lastResultAvailalable = true;
        bool validChoice = false;
        while(!validChoice) {
            char choice;
            std::cout << "Do you still want to do another addition? Y for Yes or N for No: ";
            std::cin >> choice;
            switch (choice)  {
                case 'Y':
                case 'y':
                    continueProcess = true;
                    validChoice = true;
                    break;
                case 'N':
                case 'n':
                    continueProcess = false;
                    validChoice = true;
                    break;
            default:
                std::cout << "Error: Invalid input!" << '\n';
                validChoice = false;
                break;
            }
        }
    }
}

// Gets 2 number and applies division to it
void displayDivisionProcess() {
    // Guard clauses for validation
    bool lastResultAvailable = false;
    double lastResult {0.0};

    while (true) {
        double num1;
        if (!lastResultAvailable) {
            num1 = getValidDoubleInput("Enter first number: ");
        } else {
            while (true) {
                std::cout << "Last Result saved is " << lastResult << '\n';
                std::cout << "Would you like to use last result? 1 for Yes and 2 for No: ";
                int choice;
                std::cin >> choice;
                if (std::cin.fail()) {
                    std::cout << "Error: Invalid input! Please enter a number.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }

                if (choice != 1 && choice != 2) {
                    std::cout << "Error: Invalid input!" << '\n';
                    continue; 
                }
                num1 = (choice == 1) ? lastResult : getValidDoubleInput("Enter first number: ");
                break;
            }
            
        }
        while (true) {
            double num2 = getValidDoubleInput("Enter second number: ");
            if (num2 == 0) {
                std::cout << "Error: Cannot divide by zero!" << '\n';
                continue;
            } else {
                double result {division(num1, num2)};
                lastResult = result;
                std::cout << "Result: " << num1 << " / " << num2 << " = " << result << '\n';
                break;
            }
        }

        bool exitProcess = false;
        lastResultAvailable = true;

        while (true) {
            std::cout << "Do you still want to do another multiplication? Y for Yes or N for No: ";
            char choice;
            std::cin >> choice;

            if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
                std::cout << "Error: Invalid choice!" << '\n';
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            exitProcess = (choice == 'N' || choice == 'n');
            break;
        }
    if (exitProcess) {
        break;
    }    
        
    }

}

void displaySquareRootProcess() {
    bool continueProcess = true;
    bool hasLastResult = false;
    double lastResult {0.0};
    while (true) {
        double num1;
        if (!hasLastResult) {
            num1 = getValidDoubleInput("Enter a number to get its square root: ");
        } else {
            while (true) {
                std::cout << "Last Result saved is " << lastResult << '\n';
                std::cout << "Would you like to use last result? 1 for Yes and 2 for No: ";
                int choice;
                std::cin >> choice;

                if (std::cin.fail()) {
                    std::cout << "Error: Invalid input! Please enter only numbers 1 or 2" << '\n';
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                if (choice != 1 && choice != 2) {
                    std::cout << "Error: Invalid input!" << '\n';
                    continue;
                }
                if (num1 <= 0) {
                    std::cout << "Error: Cannot caculate square root of a negative number.";
                    continue;
                }

                num1 = (choice == 1) ? lastResult : getValidDoubleInput("Enter a number to get its square root: ");
                break;
            }
        }
        
        double result {squareRoot(num1)};
        std::cout << "Result: " << "Square root of " << num1 << " = " << result << '\n';
        lastResult = result;
        hasLastResult = true;

        bool exitProcess = false;

        while (true) {
            std::cout << "Do you still want to do another square root? Y for Yes or N for No: ";
            char choice;
            std::cin >> choice;

            if (std::cin.fail()) {
                std::cout << "Error: Invalid input!" << '\n';
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
                std::cout << "Error: Invalid input!" << '\n';
                continue;
            }
            
            exitProcess = (choice == 'N' || choice == 'n');
            break;
        }
        if (exitProcess) {
            break;
        }
        if (exitProcess) {
            break;
        }
    }
}

// Gets 2 number and applies mulltipication to it
void displayExponentiationProcess() {
    bool lastResultAvailable = false;
    bool continueProcess = true;
    double lastResult {0.0};
    while (true) {
        double num1, num2;
        if (!lastResultAvailable) {
            num1 = getValidDoubleInput("Enter the base: ");
        } else {
            while (true) {
                std::cout << "Last Result saved is " << lastResult << '\n';
                std::cout << "Would you like to use last result? 1 for Yes and 2 for No: ";
                int choice;

                if (std::cin.fail()) {
                    std::cout << "Error: Invalid input! Please enter a number.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                if (choice != 1 && choice != 2) {
                    std::cout << "Error: Invalid input!" << '\n';
                    continue;
                }

                num1 = (choice == 1) ? lastResult : getValidDoubleInput("Enter the base: ");
                break;
            }
        }
        lastResultAvailable = true;
        while (true) {
            num2 = getValidDoubleInput("Enter the power: ");
            if (num1 == 0 && num2 < 0) {
                std::cout << "Error: Zero Base with a Negative Exponent" << '\n';
                continue;
            } else if (num1 <= 0 && num2 < 0) {
                std::cout << "Error: Negative Base with a Fractional Exponent" <<'\n';
                continue;
            } 
            break;
        }            
        bool exitProcess = false;
        double result {exponentiation(num1, num2)};
        std::cout << "Result: " << num1 << "^" << num2 << " = " << result << '\n';

        while (true) {
            std::cout << "Do you still want to do another exponentiation? Y for Yes or N for No: ";
            char choice;
            std::cin >> choice;
            if (std::cin.fail()) {
                std::cout << "Error: Invalid input!" << '\n';
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
                std::cout << "Error: Invalid input!" << '\n';
                continue;
            }
            exitProcess = (choice == 'N' || choice == 'n');
            break;
        }
        if (exitProcess) {
            break;
        }
    }
}

// Get the remainder of two numbers
void displayRemainderProcess() {
    bool hasLastResultAvailable = false;
    double lastResult {0.0};
    while (true) {
        double num1, num2;
        if (!hasLastResultAvailable) {
            num1 = getValidDoubleInput("Enter the first number: ");
        } else {
            while (true) {
                // Display the previous result
                std::cout << "" << '\n';
                // Ask if youn want to use the previos result
                std::cout << "" << '\n';
                int choice;
                std::cin >> choice;
                // Guard clause to make sure the input is only an integer
                if (std::cin.fail()) {
                    std::cout << "Error: Invalid input! Select only from 1 or 2" << '\n';
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                // Guard clause for checkin if the input is only the choices
                if (choice != 1 && choice !=2 ) {
                    std::cout << "Error: Select only from 1 or 2" << '\n';
                    continue;
                }

                num1 = (choice == 1) ? lastResult : getValidDoubleInput("Enter the first number: ");
                break;
            }
            
            // Get the second number
            while (true) {
                num2 = getValidDoubleInput("Enter the second number: ");
                // Guard clause to check if the number is not zero;
                if (num2 == 0) {
                    std::cout << "Error: Invalid input! Division by 0 is not allowed" << '\n';
                    continue;
                }
                double result {remainder(num1, num2)};
                std::cout << "Result: " << num1 << " % " << num2 << " = " << static_cast<int>(result)<< '\n';
                lastResult = result;
                break;
            }
            bool exitProcess = false;
            // Ask if the user wants to do another process of remainder division
            while (true) {
                char choice;
                std::cout << "Do you still want to do another exponentiation? Y for Yes or N for No: " << '\n';
                std::cin >> choice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
                    std::cout << "Error: Invalid input!" << '\n';
                    continue;
                }
                
                exitProcess = (choice == 'Y' || choice == 'y');
                break;
            }
            if (exitProcess) {
                break;
            }
        }

    }
    

    double num1, num2;
    std::cout << "\n" << "Enter first number: ";
    std::cin >> num1; 
    std::cout << '\n' << "Enter second number";
    std::cin >> num2;
    while (num2 == 0) {
        std::cout << "Error: Division by 0 is not allowed" << '\n';
        std::cout << "change second number" << '\n';
        std::cout << '\n' << "Enter second number";
        std::cin >> num2;
    }
    double result {remainder(num1, num2)};
    std::cout << "Result: " << num1 << " % " << num2 << " = " << static_cast<int>(result)<< '\n';
}

void displayAbsoluteValueProcess() {
    while (true) {
        double num1, result;
        num1 = getValidDoubleInput("Enter the number you want its absoulte value: ");
        result = absoluteValue(num1);
        std::cout << "Result: " << "|" << num1 << "| " << " = " << result << '\n';
        bool exitProcess = false;
        while (true) {
            char choice;
            std::cout << "Do you still want to do another exponentiation? Y for Yes or N for No: " << '\n';
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
                std::cout << "Error: Invalid input!" << '\n';
                continue;
            }
            exitProcess = (choice == 'Y' || choice == 'y');
            break;
        }
        if (exitProcess) {
            break;
        }
    }
}

// To vallidate double user input
double getValidDoubleInput(const std::string& prompt) {
    double value; 
    bool validInput = false;
    do {
        std::cout << prompt;
        if (std::cin >> value) { 
            validInput = true;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a valid number." << std::endl;
        }
    } while (!validInput);
        return value;
    
}


double addition (double num1, double num2) {
    return num1 + num2; 
}

double subtraction (double num1, double num2) {
    return num1 - num2; 
}

double multiplication(double num1, double num2) {
    return num1 * num2;
}

double division(double num1, double num2) {
    return num1 / num2;
}
double squareRoot(double num1) {
    return std::sqrt(num1);
}

double exponentiation(double num1, double num2) {
    return std::pow(num1, num2);
}

double remainder(double num1, double num2) {
    return static_cast<int>(num1) % static_cast<int>(num2); 
}

double absoluteValue(double num1) {
    return std::abs(num1);
}


