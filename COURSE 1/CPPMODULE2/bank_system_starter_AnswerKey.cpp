/*
 * Bank Account System - Complete Solution
 * This program simulates a simple banking system with accounts, deposits,
 * withdrawals, interest calculations, and currency conversion.
 * 
 * This is the solution version with all type conversion issues fixed.
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <limits>

using namespace std;

// Global constants
const int MAX_ACCOUNTS = 100;
const double MAX_BALANCE = 1000000.0;

// Currency conversion rates (as of a fictional date)
// Changed from float to double for better precision
const double USD_TO_EUR = 0.85;
const double USD_TO_JPY = 110.0;
const double EUR_TO_USD = 1.18;
const double EUR_TO_JPY = 129.5;
const double JPY_TO_USD = 0.0091;
const double JPY_TO_EUR = 0.0077;

// Account structure
struct Account {
    int accountNumber;
    string ownerName;
    double balance;
    char accountType;  // 'S' for Savings, 'C' for Checking
};

// Function prototypes
void displayMenu();
Account createAccount(int accountNum);
void deposit(Account& account, double amount);
bool withdraw(Account& account, double amount);
double calculateInterest(const Account& account, int days);
double convertCurrency(double amount, char fromCurrency, char toCurrency);
void displayAccountSummary(const Account& account);
void testBoundaryConditions();
bool safeFloatToInt(double floatValue, int& result);
bool safeIntegerAddition(int a, int b, int& result);

// Vector to store accounts
vector<Account> accounts;

int main() {
    cout << "===== BANK ACCOUNT SYSTEM =====" << endl;
    cout << "This program demonstrates a simple banking system." << endl;
    cout << "All type conversion issues have been fixed in this version!" << endl;
    cout << endl;

    int choice;
    int accountCounter = 100; // Starting account number
    
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                // Create a new account
                if (accounts.size() < MAX_ACCOUNTS) {
                    Account newAccount = createAccount(accountCounter++);
                    accounts.push_back(newAccount);
                    cout << "Account created successfully!" << endl;
                    displayAccountSummary(newAccount);
                } else {
                    cout << "Maximum number of accounts reached." << endl;
                }
                break;
            }
            
            case 2: {
                // Deposit money
                int accNum;
                double amount;
                cout << "Enter account number: ";
                cin >> accNum;
                
                bool found = false;
                for (size_t i = 0; i < accounts.size(); i++) {
                    if (accounts[i].accountNumber == accNum) {
                        cout << "Enter amount to deposit: ";
                        cin >> amount;
                        deposit(accounts[i], amount);
                        cout << "Deposit successful!" << endl;
                        displayAccountSummary(accounts[i]);
                        found = true;
                        break;
                    }
                }
                
                if (!found) {
                    cout << "Account not found." << endl;
                }
                break;
            }
            
            case 3: {
                // Withdraw money
                int accNum;
                double amount;
                cout << "Enter account number: ";
                cin >> accNum;
                
                bool found = false;
                for (size_t i = 0; i < accounts.size(); i++) {
                    if (accounts[i].accountNumber == accNum) {
                        cout << "Enter amount to withdraw: ";
                        cin >> amount;
                        if (withdraw(accounts[i], amount)) {
                            cout << "Withdrawal successful!" << endl;
                            displayAccountSummary(accounts[i]);
                        } else {
                            cout << "Insufficient funds or invalid amount." << endl;
                        }
                        found = true;
                        break;
                    }
                }
                
                if (!found) {
                    cout << "Account not found." << endl;
                }
                break;
            }
            
            case 4: {
                // Calculate interest
                int accNum, days;
                cout << "Enter account number: ";
                cin >> accNum;
                
                bool found = false;
                for (size_t i = 0; i < accounts.size(); i++) {
                    if (accounts[i].accountNumber == accNum) {
                        cout << "Enter number of days: ";
                        cin >> days;
                        
                        double interest = calculateInterest(accounts[i], days);
                        cout << "Interest earned after " << days << " days: $" << fixed << setprecision(2) << interest << endl;
                        cout << "Updated balance with interest: $" << fixed << setprecision(2) << accounts[i].balance + interest << endl;
                        found = true;
                        break;
                    }
                }
                
                if (!found) {
                    cout << "Account not found." << endl;
                }
                break;
            }
            
            case 5: {
                // Convert currency
                int accNum;
                char fromCurr, toCurr;
                cout << "Enter account number: ";
                cin >> accNum;
                
                bool found = false;
                for (size_t i = 0; i < accounts.size(); i++) {
                    if (accounts[i].accountNumber == accNum) {
                        cout << "Available currencies: U (USD), E (EUR), J (JPY)" << endl;
                        cout << "From currency (U/E/J): ";
                        cin >> fromCurr;
                        cout << "To currency (U/E/J): ";
                        cin >> toCurr;
                        
                        // Validate currency codes
                        fromCurr = toupper(fromCurr);
                        toCurr = toupper(toCurr);
                        
                        if ((fromCurr != 'U' && fromCurr != 'E' && fromCurr != 'J') ||
                            (toCurr != 'U' && toCurr != 'E' && toCurr != 'J')) {
                            cout << "Invalid currency code. Please use U, E, or J." << endl;
                            break;
                        }
                        
                        double convertedAmount = convertCurrency(accounts[i].balance, fromCurr, toCurr);
                        
                        cout << "Converted amount: ";
                        switch(toCurr) {
                            case 'U': cout << "$"; break;
                            case 'E': cout << "€"; break;
                            case 'J': cout << "¥"; break;
                        }
                        cout << fixed << setprecision(2) << convertedAmount << endl;
                        found = true;
                        break;
                    }
                }
                
                if (!found) {
                    cout << "Account not found." << endl;
                }
                break;
            }
            
            case 6: {
                // Display all accounts
                if (accounts.empty()) {
                    cout << "No accounts to display." << endl;
                } else {
                    cout << "\n===== ACCOUNT SUMMARIES =====" << endl;
                    for (const Account& acc : accounts) {
                        displayAccountSummary(acc);
                        cout << "----------------------------" << endl;
                    }
                }
                break;
            }
            
            case 7: {
                // Test boundary conditions
                testBoundaryConditions();
                break;
            }
            
            case 8:
                cout << "Exiting program. Thank you!" << endl;
                break;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        
        cout << endl;
    } while (choice != 8);
    
    return 0;
}

// Function to display the main menu
void displayMenu() {
    cout << "\n===== MENU =====" << endl;
    cout << "1. Create a new account" << endl;
    cout << "2. Deposit money" << endl;
    cout << "3. Withdraw money" << endl;
    cout << "4. Calculate interest" << endl;
    cout << "5. Convert currency" << endl;
    cout << "6. Display all accounts" << endl;
    cout << "7. Test boundary conditions" << endl;
    cout << "8. Exit" << endl;
}

// Function to create a new account
Account createAccount(int accountNum) {
    Account newAccount;
    newAccount.accountNumber = accountNum;
    
    cout << "Enter account owner name: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, newAccount.ownerName);
    
    cout << "Enter initial balance: $";
    double initialBalance;
    cin >> initialBalance;
    
    // Fixed: No unnecessary type conversion
    // Validate initial balance
    if (initialBalance < 0) {
        cout << "Initial balance cannot be negative. Setting to 0." << endl;
        newAccount.balance = 0.0;
    } else if (initialBalance > MAX_BALANCE) {
        cout << "Initial balance exceeds maximum allowed. Setting to maximum." << endl;
        newAccount.balance = MAX_BALANCE;
    } else {
        newAccount.balance = initialBalance;
    }
    
    cout << "Enter account type (S for Savings, C for Checking): ";
    cin >> newAccount.accountType;
    newAccount.accountType = toupper(newAccount.accountType);
    
    return newAccount;
}

// Function to deposit money into an account
void deposit(Account& account, double amount) {
    // Fixed: Use double for amount parameter instead of int
    if (amount <= 0) {
        cout << "Deposit amount must be positive." << endl;
        return;
    }
    
    if (account.balance + amount > MAX_BALANCE) {
        cout << "Deposit would exceed maximum balance limit." << endl;
        return;
    }
    
    account.balance += amount;
}

// Function to withdraw money from an account
bool withdraw(Account& account, double amount) {
    // Fixed: Use double for amount parameter instead of int
    if (amount <= 0) {
        cout << "Withdrawal amount must be positive." << endl;
        return false;
    }
    
    if (amount > account.balance) {
        cout << "Insufficient funds." << endl;
        return false;
    }
    
    account.balance -= amount;
    return true;
}

// Function to calculate interest for a given number of days
double calculateInterest(const Account& account, int days) {
    if (days <= 0) {
        return 0.0;
    }
    
    // Interest rates (annual)
    double rate;
    
    if (account.accountType == 'S') {
        rate = 0.03; // 3% for Savings
    } else {
        rate = 0.01; // 1% for Checking
    }
    
    // Fixed: Use double for all calculations to maintain precision
    double dailyRate = rate / 365.0;
    double interest = account.balance * dailyRate * static_cast<double>(days);
    
    // Round to nearest cent
    return round(interest * 100.0) / 100.0;
}

// Function to convert between currencies
double convertCurrency(double amount, char fromCurrency, char toCurrency) {
    // Fixed: Return double instead of float for better precision
    if (amount <= 0) {
        return 0.0;
    }
    
    if (fromCurrency == toCurrency) {
        return amount;
    }
    
    double result = amount;
    
    // Convert from source currency to USD as an intermediate step
    if (fromCurrency == 'E') { // From EUR
        result *= EUR_TO_USD;
    } else if (fromCurrency == 'J') { // From JPY
        result *= JPY_TO_USD;
    }
    // If fromCurrency is 'U', no conversion needed
    
    // Convert from USD to target currency
    if (toCurrency == 'E') { // To EUR
        result *= USD_TO_EUR;
    } else if (toCurrency == 'J') { // To JPY
        result *= USD_TO_JPY;
    }
    // If toCurrency is 'U', no conversion needed
    
    return result;
}

// Function to display account summary
void displayAccountSummary(const Account& account) {
    cout << "\nAccount Number: " << account.accountNumber << endl;
    cout << "Owner: " << account.ownerName << endl;
    cout << "Type: " << (account.accountType == 'S' ? "Savings" : "Checking") << endl;
    cout << "Balance: $" << fixed << setprecision(2) << account.balance << endl;
}

// Safe function to convert float to int with validation
bool safeFloatToInt(double floatValue, int& result) {
    // Check if the value is within int range
    if (floatValue < static_cast<double>(numeric_limits<int>::min()) || 
        floatValue > static_cast<double>(numeric_limits<int>::max())) {
        return false; // Value too large or too small for int
    }
    
    // Check if there's a fractional part that would be lost
    if (floatValue != floor(floatValue)) {
        cout << "Warning: Fractional part will be lost in conversion." << endl;
    }
    
    result = static_cast<int>(floatValue);
    return true;
}

// Safe function to add two integers, detecting potential overflow
bool safeIntegerAddition(int a, int b, int& result) {
    // Check for overflow
    if (a > 0 && b > 0 && a > numeric_limits<int>::max() - b) {
        return false; // Positive overflow
    }
    
    // Check for underflow
    if (a < 0 && b < 0 && a < numeric_limits<int>::min() - b) {
        return false; // Negative overflow
    }
    
    result = a + b;
    return true;
}

// Function to test boundary conditions
void testBoundaryConditions() {
    cout << "\n===== TESTING BOUNDARY CONDITIONS =====" << endl;
    
    // Create a test account
    Account testAccount;
    testAccount.accountNumber = 999;
    testAccount.ownerName = "Test Account";
    testAccount.balance = 1000.0;
    testAccount.accountType = 'S';
    
    cout << "Initial test account:" << endl;
    displayAccountSummary(testAccount);
    
    // Test 1: Large deposit with overflow protection
    double largeAmount = 2000000.0; // Larger than MAX_BALANCE
    cout << "\nTest 1: Large deposit of $" << fixed << setprecision(2) << largeAmount << endl;
    
    // This will now be safely handled by the deposit function
    deposit(testAccount, largeAmount);
    cout << "After large deposit attempt:" << endl;
    displayAccountSummary(testAccount);
    
    // Test 2: Decimal precision in interest calculation
    testAccount.balance = 100.0;
    double rate = 0.03333333; // 3.333333% interest rate
    
    cout << "\nTest 2: Decimal precision in interest calculation" << endl;
    cout << "Interest rate: " << fixed << setprecision(6) << rate * 100 << "%" << endl;
    
    double interest = calculateInterest(testAccount, 30); // 30 days
    cout << "Interest for 30 days: $" << fixed << setprecision(2) << interest << endl;
    
    // Test 3: Currency conversion precision
    double largeBalance = 1000000.0;
    
    cout << "\nTest 3: Currency conversion precision" << endl;
    cout << "Original amount: $" << fixed << setprecision(2) << largeBalance << endl;
    
    double eurAmount = convertCurrency(largeBalance, 'U', 'E');
    double jpyAmount = convertCurrency(largeBalance, 'U', 'J');
    
    cout << "Converted to EUR: €" << fixed << setprecision(2) << eurAmount << endl;
    cout << "Converted to JPY: ¥" << fixed << setprecision(2) << jpyAmount << endl;
    
    // Test 4: Safe integer addition
    int maxInt = numeric_limits<int>::max();
    int smallInt = 100;
    int safeResult;
    
    cout << "\nTest 4: Safe integer addition" << endl;
    cout << "Maximum integer value: " << maxInt << endl;
    cout << "Small integer to add: " << smallInt << endl;
    
    if (safeIntegerAddition(maxInt, smallInt, safeResult)) {
        cout << "Safe addition result: " << safeResult << endl;
    } else {
        cout << "Addition would cause overflow - operation prevented!" << endl;
    }
    
    // Test 5: Safe float to int conversion
    double testFloat = 123.456;
    int intResult;
    
    cout << "\nTest 5: Safe float to int conversion" << endl;
    cout << "Float value: " << fixed << setprecision(3) << testFloat << endl;
    
    if (safeFloatToInt(testFloat, intResult)) {
        cout << "Converted integer value: " << intResult << endl;
    } else {
        cout << "Conversion failed - value out of range!" << endl;
    }
}

