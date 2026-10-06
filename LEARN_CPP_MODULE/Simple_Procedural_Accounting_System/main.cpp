/// A simple procedural accounting system
/// Main.cpp handles the execution flow of the system
/// Manages the local state: variables for ledger balance 
/// Handles coordination of the display and logic modules

/// Add the header files for the display module
#include "display.h"
/// Add the header file for the logic module
#include "transactions.h"

/// Add the library for the I/O functions
#include <iostream>


int main() {
    /// Initialize the container for balance and the user inputted amount
    double ledgerBalance {0.0};
    double amountCredit {0.0};

    /// Call the function to priint the welcome message
    printWelcomeMessage();

    /// Ask for the user input for the amount to be deposited by the user
    std::cout << "Enter amount to be deposited: ";
    std::cin >> amountCredit;

    /// Call the function to do the addittion of the deposit to the existing balance
    /// Capturing the return value of the function processDeposit
    ledgerBalance = processDeposit(ledgerBalance, amountCredit);

    double amountDebit {0.0};
    /// Ask for the input for the amount to be spent on 
    std::cout << "Enter a business expense to debit" << '\n';
    std::cin  >>  amountDebit;

    /// Call function to do the substraction of the debit
    /// Capturing the return value of the function processDebit
    ledgerBalance = processDebit(ledgerBalance, amountDebit);
     



    /// Call the function to display the new balance
    printCurrentBalance(ledgerBalance);


    
    




    return 0;

}



