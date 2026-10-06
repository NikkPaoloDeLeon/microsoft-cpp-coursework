/*
 * Bank Account System
 * This program simulates a simple banking system with accounts, deposits,
 * withdrawals, interest calculations, and currency conversion.
 * 
 * WARNING: This code contains multiple type conversion issues that need to be fixed!
 */

/*
Issue 1:
Line number: 277
Problematic code: float tempBalance = initialBalance;
Issue description: We have an implicit conversion from double to float which is a potential for a mathematical precision loss.
Potential problems: Potentical mathematical precision loss

Issue 2:
Line number: 278
Problematic code:  newAccount.balance = tempBalance;
Issue description: We have an implicit conversion from float to double which is a potential for a mathematical precision loss.
Potential problems: Potentical mathematical precision loss

Issue 3:
Line number: 290
Problematic code: account.balance += static_cast<double>(amount);
Issue description: We have a implicit conversion when adding the variable amount which is an integer to a double.
Potential problems: Implicit conversion can lead to mathematical precision loss.
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <limits>  
#include <climits>

using namespace std;

// Global constants
#define MAX_ACCOUNTS 100
#define MAX_BALANCE 1000000

// Currency conversion rates (as of a fictional date)
double USD_TO_EUR = 0.85f;
double USD_TO_JPY = 110.0f;
double EUR_TO_USD = 1.18f;
double EUR_TO_JPY = 129.5f;
double JPY_TO_USD = 0.0091f;
double JPY_TO_EUR = 0.0077f;

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
void deposit(Account& account, int amount);
bool withdraw(Account& account, int amount);
bool willOverflow(const Account& account, double amount);
bool willUnderflow(const Account& account, double amount);
double calculateInterest(Account account, int days);
double convertCurrency(double amount, char fromCurrency, char toCurrency);
void displayAccountSummary(const Account& account);
void testBoundaryConditions();

// Vector to store accounts
vector<Account> accounts;

int main() {
    cout << "===== BANK ACCOUNT SYSTEM =====" << endl;
    cout << "This program demonstrates a simple banking system." << endl;
    cout << "NOTE: This code contains type conversion issues that need to be fixed!" << endl;
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
                for (int i = 0; i < accounts.size(); i++) {
                    if (accounts[i].accountNumber == accNum) {
                        cout << "Enter amount to deposit: ";
                        cin >> amount;
                        bool ofValid = willOverflow(accounts[i], amount);
                        while (ofValid == true) {
                            std::cout << "Invalid Amount! Enter the Accepted amount only." << '\n';
                            cout << "Enter amount to deposit: ";
                            cin >> amount;
                            ofValid = willOverflow(accounts[i], amount);
                        }
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
                int accNum, amount;
                cout << "Enter account number: ";
                cin >> accNum;
                
                bool found = false;
                for (int i = 0; i < accounts.size(); i++) {
                    if (accounts[i].accountNumber == accNum) {
                        cout << "Enter amount to withdraw: ";
                        cin >> amount;
                        bool ofValid = willUnderflow(accounts[i], amount);
                        while (ofValid == true) {
                            std::cout << "Invalid Amount! Enter the Accepted amount only." << '\n';
                            cout << "Enter amount to withdraw: ";
                            cin >> amount;
                            ofValid = willUnderflow(accounts[i], amount);
                        }
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
                for (int i = 0; i < accounts.size(); i++) {
                    if (accounts[i].accountNumber == accNum) {
                        cout << "Enter number of days: ";
                        cin >> days;
                        
                        double interest = calculateInterest(accounts[i], days);
                        cout << "Interest earned after " << days << " days: $" << interest << endl;
                        cout << "Updated balance with interest: $" << accounts[i].balance + interest << endl;
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
                for (int i = 0; i < accounts.size(); i++) {
                    if (accounts[i].accountNumber == accNum) {
                        cout << "Available currencies: U (USD), E (EUR), J (JPY)" << endl;
                        cout << "From currency (U/E/J): ";
                        cin >> fromCurr;
                        char fromCurr2 = toupper(fromCurr);
                        while (fromCurr2 != 'U' && fromCurr2 != 'E' && fromCurr2 != 'J'){
                            std::cout << "Invalid Currency! Please choose only from available currencies: U (USD), E (EUR), J (JPY)" << '\n';
                            std::cout << "From currency (U/E/J): " << '\n';
                            std::cin >> fromCurr;
                            toupper(fromCurr);
                        }
                        cout << "To currency (U/E/J): ";
                        cin >> toCurr;
                        char toCurr2 = toupper(toCurr);
                        while (toCurr2 != 'U' && toCurr2 != 'E' && toCurr2 != 'J') {
                            std::cout << "Invalid Currency! Please choose only from available currencies: U (USD), E (EUR), J (JPY)" << '\n';
                            std::cout << "To currency (U/E/J): " << '\n';
                            std::cin >> toCurr;
                            toupper(toCurr);
                        }
                        
                        double convertedAmount = convertCurrency(accounts[i].balance, 
                                                              toupper(fromCurr), 
                                                              toupper(toCurr));
                        
                        cout << "Converted amount: ";
                        switch(toupper(toCurr)) {
                            case 'U': cout << "$"; break;
                            case 'E': cout << "€"; break;
                            case 'J': cout << "¥"; break;
                        }
                        cout << convertedAmount << endl;
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
    
    // Convert double to float and then back to double - potential precision loss!
    float tempBalance = static_cast<float>(initialBalance);
    newAccount.balance = static_cast<double>(tempBalance);
    
    cout << "Enter account type (S for Savings, C for Checking): ";
    cin >> newAccount.accountType;
    
    return newAccount;
}

// Function to deposit money into an account
void deposit(Account& account, int amount) {
    // Problem: int amount is added to a double balance without explicit conversion
    if (amount > 0) {
        account.balance += static_cast<double>(amount);
    }
}

// Function to withdraw money from an account
bool withdraw(Account& account, int amount) {
    // Problem: int amount is subtracted from a double balance without explicit conversion
    if (amount > 0 && amount <= account.balance) {
        account.balance -= static_cast<double>(amount);
        return true;
    }
    return false;
}

// Function to calculate interest for a given number of days
double calculateInterest(Account account, int days) {
    // Interest rates (annual)
    double rate;
    
    if (account.accountType == 'S') {
        rate = 0.03; // 3% for Savings
    } else {
        rate = 0.01; // 1% for Checking
    }
    
    // Problem: days is converted to float in division, potential precision loss
    double dailyRate = rate / static_cast<double>(365);
    
    // Problem: mixing double, float and int in calculation
    double interest = account.balance * static_cast<double>(dailyRate) * static_cast<double>(days);
    int truncatedInterest = static_cast<int>(interest * 100);
    return truncatedInterest / 100.0;
}

// Function to convert between currencies
double convertCurrency(double amount, char fromCurrency, char toCurrency) {
    // Problem: double amount converted to float result, potential precision loss
    double result = (amount);
    
    if (fromCurrency == toCurrency) {
        return result;
    }
    
    // Convert from source currency to USD as an intermediate step
    if (fromCurrency == 'E') { // From EUR
        result *= EUR_TO_USD;
    } else if (fromCurrency == 'J') { // From JPY
        result *= JPY_TO_USD;
    }
    
    // Convert from USD to target currency
    if (fromCurrency != 'U' && toCurrency == 'U') {
        // Already converted to USD
    } else if (toCurrency == 'E') { // To EUR
        result *= USD_TO_EUR;
    } else if (toCurrency == 'J') { // To JPY
        result *= USD_TO_JPY;
    }
    
    // Problem: potential truncation when converting to float
    return result;
}

// Function to display account summary
void displayAccountSummary(const Account& account) {
    cout << "\nAccount Number: " << account.accountNumber << endl;
    cout << "Owner: " << account.ownerName << endl;
    cout << "Type: " << (account.accountType == 'S' ? "Savings" : "Checking") << endl;
    cout << "Balance: $" << fixed << setprecision(2) << account.balance << endl;
}

// Add this function to your code
bool safeFloatToInt(float floatValue, int& result) {
    // Your implementation here:

    if (!std::isfinite(floatValue)) {
        return false;
    }

    long double checkingValue = static_cast<long double>(floatValue);
    // 1. Check if the float is too large for an int
    if (checkingValue < static_cast<long double>(std::numeric_limits<int>::min()) 
    ||checkingValue > static_cast<long double>(std::numeric_limits<int>::max())) {
        return false;
    }
    // 2. Check if the float has a fractional part that would be lost
    if (std::trunc(floatValue) != floatValue) {
        return false;
    }
    // 3. If safe, convert and return true; otherwise return false
    result = static_cast<int>(floatValue);
    return true; // Replace with your implementation
}

bool willOverflow(const Account& account, double amount) {
    if (std::isinf(amount + account.balance) == true) {
        return true; 
    }
    return false; 
}

bool willUnderflow(const Account& account, double amount) {
    if (amount > account.balance == true) {
        return true;
    }
    return false;
}

bool willMultiplicationUnderflow (const Account& account) {
    if (account.balance > 0 && ((account.balance * 0.03) == 0.0 || (account.balance * 0.01) == 0.0)) {
        return true;
    }
    return false; 
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
    
    // Test 1: Large deposit
    int largeAmount = 2000000000; // Larger than MAX_BALANCE
    cout << "\nTest 1: Large deposit of $" << largeAmount << endl;
    
    // Problem: This might overflow or exceed MAX_BALANCE
    deposit(testAccount, largeAmount);
    cout << "After large deposit:" << endl;
    displayAccountSummary(testAccount);
    
    // Test 2: Decimal precision
    testAccount.balance = 100.0;
    double rate = 0.03333333; // 3.333333% interest rate
    
    // Problem: Potential precision loss when converting double to float
    float dailyRate = rate / 365;
    
    // Problem: Mixing types in calculation
    double interest = testAccount.balance * dailyRate * 30; // 30 days
    
    cout << "\nTest 2: Decimal precision" << endl;
    cout << "Interest rate: " << rate * 100 << "%" << endl;
    cout << "Daily rate: " << dailyRate << endl;
    cout << "Interest for 30 days: $" << interest << endl;
    
    // Test 3: Currency conversion precision
    double largeBalance = 1000000.0;
    
    // Problem: Converting large double to float for currency conversion
    float eurAmount = convertCurrency(largeBalance, 'U', 'E');
    float jpyAmount = convertCurrency(largeBalance, 'U', 'J');
    
    cout << "\nTest 3: Currency conversion precision" << endl;
    cout << "Original amount: $" << largeBalance << endl;
    cout << "Converted to EUR: €" << eurAmount << endl;
    cout << "Converted to JPY: ¥" << jpyAmount << endl;
    
    // Test 4: Integer overflow
    int maxInt = numeric_limits<int>::max();
    int smallInt = 100;
    
    // Problem: This will overflow
    int overflowResult = maxInt + smallInt;
    
    cout << "\nTest 4: Integer overflow" << endl;
    cout << "Maximum integer value: " << maxInt << endl;
    cout << "Small integer to add: " << smallInt << endl;
    cout << "Result of addition: " << overflowResult << endl;
}