// Implement input validation loops to handle invalid user data
// Use stream manipulators to create professional-looking formatted output
// Apply error handling techniques to maintain program stability  
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <format>
#include <charconv>
#include <system_error>
#include <optional>
#include <algorithm>
#include <random>

// Forwad declaration
std::optional<int> GetValidCustomerAge(const std::string& propmt);
std::optional<std::string>GetValidCustomerName(const std::string& prompt);
void PrintCustomerInfo(std::string& name, std::string& customerID, double& balance, int& age);
std::string GenerateRandomCustomerID();
int GenerateRandomNumber();
std::optional<double> GetValidCustomerBalance(const std::string& prompt);

int main() {
    std::srand(static_cast<unsigned int>(time(0)));
    int userAge {0};
    std::string userName;
    std::string promptAge {"Please enter the age: "};
    userAge = GetValidCustomerAge(promptAge).value_or(0);
    std::cout << "Your age is " << userAge << '?' << '\n'; 
    std::string promptName = {"Please enter the name: "};
    userName = GetValidCustomerName(promptName).value_or("");
    std::cout << "Your name is " << userName << '?' << '\n';
    std::string customerID;
    customerID = GenerateRandomCustomerID();
    double userBalance = {0};
    std::string promptBalance {"Enter your available balance: "};
    userBalance = GetValidCustomerBalance(promptBalance).value_or(0);
    std::cout << "Custmoer balance is: " << std::fixed << std::setprecision(2) << userBalance << '\n';
    PrintCustomerInfo(userName, customerID, userBalance, userAge);

    return 0;
}

void PrintCustomerInfo(std::string& name, std::string& customerID, double& balance, int& age) {
    std::cout << std::string(120, '=') << '\n';   
    std::cout << std::setw(40) << "CUSTOMER INFORMATION" << '\n';
    std::cout << std::string(120, '=') << '\n';
    std::cout << std::setw(20) << "Name" << std::setw(20) << "Customer ID" << std::setw(30) << "Balance" << std::setw(10) << "Age" << '\n';
    std::cout << std::setw(20) << name << std::setw(20) << customerID << std::setw(30) << std::setprecision(2) << balance << std::setw(10) << age << '\n';
}
// Helps generate a number for the customer ID
int GenerateRandomNumber() {
    return std::rand() % 10;
}
// Generate a random user ID.
std::string GenerateRandomCustomerID() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::string customerID(10, ' ');
    std::uniform_int_distribution<> distr(0, 25);
    char randomLetter = static_cast<char>('A' + distr(gen));
    for (int i {0}; i < 10; i++) {
        if (i < 3 || (i >= 5 && i < 7)) {
            customerID.at(i) = randomLetter;
        }
        else {
            customerID.at(i) = static_cast<char>('0' + GenerateRandomNumber());
        }
    }
    return customerID;
}
// Funciton to get the balance of the user and make sure that the inputted data is 100 percent accurate as a double.
std::optional<double> GetValidCustomerBalance(const std::string& prompt) {
    std::string input;
    double balance;
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, input)) {
            std::cerr << "FATAL STREAM ERROR." << '\n';
            return std::nullopt;
        }
        auto [pointer, errorC] = std::from_chars(input.data(), input.data() + input.size(), balance);
        if (pointer != input.data() + input.size()) {
            std::cerr << "Syntax Error: Please input a valid number only." << '\n';
            continue;
        }
        if (errorC == std::errc::invalid_argument) {
            std::cerr << "Type Error: Please input number only." << '\n';
            continue;
        }
        if (errorC == std::errc::result_out_of_range) {
            std::cerr << "Overflow: You have exceeded the maximum number that can be inputted." << '\n';
        }
        if (balance < 0 ) {
            std::cerr << "Logical Error: Cannot input a negative number as a balance." << '\n';
        }
        return balance;
    }
}
// Funciton to get the name of the user and make sure that the inputted data is has under go checking for a name
std::optional<std::string>GetValidCustomerName(const std::string& prompt) {
    std::string name;
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, name)) {
            std::cout << "FATAL STREAM ERROR." << '\n';
            return std::nullopt;
        }
        // We use structured binding to scan the each character using std::from_char and check where in the string the error happens
        // First guard clause is to make sure that the string is not empty.
        if (name.empty()) {
            std::cerr << "Name cannot be empty." << '\n';
            continue;
        }
        if (name.find_first_not_of(" \t") == std::string::npos) {
            std::cerr << "Name cannot be spaces only." << '\n';
            continue;
        }
        if (name.find("  ") != std::string::npos) {
            std::cerr << "Name cannot have two conecutive spaces." << '\n';
            continue;
        }
        bool isValidSet = std::all_of(name.begin(), name.end(), [](unsigned char c) {
            return std::isalpha(c) || std::isspace(c) || c == '-' || c == '.';
        });
        if (!isValidSet) {
            std::cerr << "Syntax Error: name can only contain letters, -, ., and space." << '\n';
            continue;
        }
        return name;
    }
    
}

// Funciton to get the age of the user and make sure that the inputted data is 100 percent accurate
std::optional<int> GetValidCustomerAge(const std::string& propmt) {
    std::string input;
    int age {0};
    while (true) {
        std::cout << propmt;
        if (!std::getline(std::cin, input)) {
            std::cerr << "FATAL STREAM ERROR." << '\n';
            return std::nullopt;
        }
        auto [ptr, ec] = std::from_chars(input.data(), input.data() + input.size(), age);
        if (ptr != input.data() + input.size()) {
            std::cerr << "Syntax Error: Do not include non numeric characters." << '\n';
            continue;
        }
        if (ec == std::errc::invalid_argument) {
            std::cerr << "Type Error: Please input a valid number." << '\n';
            continue;
        }
        if (ec == std::errc::result_out_of_range) {
            std::cerr << "Overflow Error: Number input exceeds the accpeted limits" << '\n';
            continue; 
        }
        if (age <= 0 || age > 150) {
            std::cout << "Logical Error: Please enter a valid age!" << '\n';
            continue;
        }
        return age;
    }
}
