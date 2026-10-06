#include <iostream>

int main() {
    std::cout << "=== Simple Banking Calculator ===" << '\n';
    double balance = 1000.0;
    int choice;
    double amount;
    bool continueOperations = true;
    while (continueOperations) {
        std::cout << "\nCurrent Balance: $" << balance << '\n';
        std::cout << "1. Deposit" << '\n';
        std::cout << "2. Withdrawal" << '\n';
        std::cout << "3. Check balance" << '\n';
        std::cout << "4. Exit" << '\n';
        std::cout << "Choose an option: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "Enter deposit amount: $";
            std::cin >> amount;
            if (amount > 0) {
                balance = balance + amount;
                std::cout << "Deposite $" << amount << '\n';
            } else {
                std::cout << "Invalid amount!" << '\n';
            }
            break;
        case 2:
            std::cout << "Enter withdrawal amount: $";
            std::cin >> amount;
            if (amount > 0 && amount <= balance) {
                balance = balance - amount;
                std::cout << "Withdrew $" << amount << '\n';  
            } else if (amount > balance) {
                std::cout << "Insufficient funds!" << '\n';
            } else {
                std::cout << "Invalid amount!" << '\n';
            }
            break;
        case 3: 
            std::cout << "Current balance: $" << balance << '\n';
            break;  
        case 4:
            continueOperations = false;
            std::cout << "Thank you for banking with us!" << '\n';
            break;
        default:
            std::cout << "Invalid choice! choice please try again!" << '\n';
            break;
        }
        double annualInterest =  balance * 0.02;
        std::cout << "Annual Interest earnes: $"  << annualInterest << '\n';
    }
    return 0;
}