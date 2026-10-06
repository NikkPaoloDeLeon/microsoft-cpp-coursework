// Design a program that helps users calculate compound interest for savings accounts.
/* 
PSEUDO CODE: 

BEGIN BANKING CALCULATOR 
    INITIALIZE ANNUAL INTEREST RATE {0.0}, INITIAL DEPOSIT AMOUNT {0.0}, FINAL AMOUNT {0.0}, INTEREST EARNED {0.0}, DECIMAL RATE {0.0}
    INITIALIZE NUMBER OF YEARS {0}
    INITIALIZE BOOLEAN EXIT PROCESS {FALSE}

    WHILE (NOT EXIT PROCESS)
        PRINT "ENTER INITIAL DEPOSIT AMOUNT: "
        READ INITIAL DEPOSIT AMOUNT
        IF READ FAILS OR INITIAL DEPOSIT AMOUNT IS < 0 
            PRINT "ERROR: INVALID INPUT! INITIAL DEPOSIT AMOUNT SHOULD BE GREATER THAN 0."
            CLEAR READ
            CHECK FOR NUMBERIC LIMITS
            SKIP AND MOVE ON TO THE NEXT ITERATION
        END IF
        EXIT PROCESS = TRUE
    END WHILE

    EXIT PROCESS = FALSE

    WHILE (NOT EXIT PROCESS)
        PRINT "ENTER ANNUAL INTEREST RATE: "
        READ ANNUAL INTEREST RATE 
        IF READ FAILS OR ANNUAL INTEREST RATE <= 0 OR ANNUAL INTEREST RATE IS > 100
            PRINT "ERROR: INVALID INPUT! ANNUAL INTERATE RATE SHOULD BE BETWEEN 0 AND 100."
            CLEAR READ
            CHECK FOR NUMBERIC LIMITS
            SKIP AND MOVE ON TO THE NEXT ITERATION
        END IF
        EXIT PROCESS = TRUE
    END WHILE

    EXIT PROCESS = FALSE

    WHILE (NOT EXIT PROCESS)
        PRINT "ENTER NUMBER OF YEARS: " 
        READ NUMBER OF YEARS
        IF READ FAILS OR NUMBER OF YEARS <= 0 OR NUMBER OF YEARS > 100
            PRINT "ERROR: INVALID INPUT! NUMBER OF YEARS SHOULD BE BETWEEN 0 AND 100: "
            CLEAR READ
            CHECK FOR NUMBERIC LIMITS
            SKIP AND MOVE ON TO THE NEXT ITERATION
        END IF
        EXIT PROCESS = TRUE
    END WHILE

    DECIMAL RATE = ANNUAL INTEREST RATE / 100
    FINAL AMOUNT = INITIAL DEPOSIT AMOUNT * POWER((1 + DECIMAL RATE),CAST TO DOUBLE (NUMBER OF YEARS))
    INTEREST EARNED = FINAL AMOUNT - INITIAL DEPOSIT AMOUNT
    PRINT "FINAL AMOUNT: " FINAL AMOUNT "TOTAL INTEREST EARNED: " INTEREST EARNED
END BANKING CALCULATOR 
*/

#include <iostream>
#include <cmath>
#include <limits>



int main() {
    double annualInterestRate{0.0}, initialDeposit {0.0}, finalAmount {0.0}, interestEarned {0.0}, decimalRate {0.0};
    int numberOfYears {0};
    bool exitProcess {false};

    while (!exitProcess) {
        std::cout << "Enter initial deposit amount: ";
        std::cin >> initialDeposit;
        if (std::cin.fail() || initialDeposit < 0) {
            std::cout << "Error: Invalid input! initial deposit amount" << '\n';
            std::cout << "must be greater than." << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        exitProcess = true;
    }

    exitProcess = false;

    while (!exitProcess) {
        std::cout << "Enter annual interest: ";
        std::cin >> annualInterestRate;
        if (std::cin.fail() || annualInterestRate < 0 || annualInterestRate > 100) {
            std::cout << "Error: Invalid input! Annual interest rate must be between 0 and 100." << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
        exitProcess = true;
    }

    exitProcess = false;

    while (!exitProcess) {
        std::cout << "Enter number of years: ";
        std::cin >> numberOfYears;
        if (std::cin.fail() || numberOfYears < 0 || numberOfYears > 100) {
            std::cout << "Error: Invalid input! Number of years must be between 0 and 100." << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        exitProcess = true;
    }

    decimalRate = annualInterestRate / 100;
    finalAmount = initialDeposit * pow((1 + decimalRate), static_cast<double>(numberOfYears));
    interestEarned = finalAmount - initialDeposit;
    std::cout << "Final amount: " << finalAmount << ". " << "Interested earned: " << interestEarned << std::endl; 

    return 0;
}