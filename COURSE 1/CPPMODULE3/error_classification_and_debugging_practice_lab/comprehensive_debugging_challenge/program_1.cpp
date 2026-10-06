/*
 * Buggy Calculator
 * 
 * This program implements a simple calculator with several functions:
 * - Addition
 * - Subtraction
 * - Multiplication
 * - Division
 * - Power (exponentiation)
 * 
 * However, it contains various bugs that need to be fixed.
 */
#include <iostream>
#include <cmath>
using namespace std;
// Function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double base, int exponent);
void displayMenu();
int main() {
    cout << "=== Buggy Calculator ===" << endl;
    int choice;
    double num1, num2; // Bug: Missing semicolon
    char continueCalc = 'y';
    while (continueCalc == 'y') { // Bug: Assignment instead of comparison
        displayMenu();
        cin >> choice;  
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;    
        switch (choice) {
            case 1:
                cout << "Result: " << add(num1, num2) << endl;
                break;
            case 2:
                cout << "Result: " << subtract(num1, num2) << endl;
                break;
            case 3:
                cout << "Result: " << multiply(num1, num2) << endl;
                break;
            case 4:
                cout << "Result: " << divide(num1, num2) << endl;
                break;
            case 5:
                cout << "Result: " << power(num1, static_cast<int>(num2)) << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }   
        cout << "Continue? (y/n): ";
        cin >> continueCalc;
    }   
    cout << "Thank you for using the calculator!" << endl;
    return 0;
}
void displayMenu() {
    cout << "\nCalculator Menu:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Power" << endl;
    cout << "Enter your choice (1-5): ";
}
// Add two numbers
double add(double a, double b) {
    return a + b;
}
// Subtract two numbers
double subtract(double a, double b) {
    return a - b; // Bug: parameters are reversed
}
// Multiply two numbers
double multiply(double a, double b) {
    return a * b;
}
// Divide two numbers
double divide(double a, double b) {
    if (b == 0) {
        std::cout << "Error: Division by 0!" << '\n';
        return 1;
    }
    return a / b; // Bug: no check for division by zero
}
// Calculate base raised to exponent
double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 1; i <= exponent; i++) { // Bug: starts from 0 instead of 1
        result = base * result;
    }
    return result;
}