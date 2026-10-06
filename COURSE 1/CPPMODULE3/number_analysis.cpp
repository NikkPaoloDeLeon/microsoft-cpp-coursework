/*
PSEUDO CODE:
BEGIN
    Initialize variables (count, min, max, sum)    
    REPEAT
        Prompt user for a number
        Get user input        
        IF count < MAX_NUMBERS THEN
            Store number in array
            Update min if number is smaller than current min
            Update max if number is larger than current max
            Add number to sum
            Increment count
        END IF        
        Ask if user wants to enter another number
        Get user response
    UNTIL user doesn't want to enter more numbers OR count equals MAX_NUMBERS    
    Calculate average (sum / count)    
    Display min, max, sum, average    
    FOR each number in the array
        Determine if even or odd
        Determine if positive or negative
        Display results
    END FOR
END
*/
// Header files
#include <iostream>
#include <limits>
#include <cmath>
#include <string>
#include <vector>
#include <format>
#include <iomanip>

// Forward declaration
std::vector<double> getNumbers();
double getValidDouble(const std::string& prompt);
double getMinimum(std::vector<double> numbers);
double getMaximum(std::vector<double> numbers);
double getSum(std::vector<double> numbers);
double getAverage(std::vector<double> numbers, double sum);
std::vector<double> getEven(std::vector<double> numbers);
std::vector<double> getOdd(std::vector<double> numbers);
std::vector<double> getPositive(std::vector<double> numbers);
std::vector<double> getNegative(std::vector<double> numbers);

int main() {
    bool continueProcess {true};
    do {
        double min {0.0}, max {0.0}, sum {0.0}, average {0.0};
        std::vector<double> even, odd, positive, negative; 
        std::vector<double> numbers = getNumbers();
        std::cout << "This are the 10 numbers: " << '\n'; 
        for (int i = 0; i < numbers.size(); i++) {
            if (i == 9) {
                std::cout << numbers[i];
            } else {
                std::cout << numbers[i] << ", ";
            }
        }
        min = getMinimum(numbers);
        std::cout << "The minimum number is: " << min << '\n';
        max = getMaximum(numbers);
        std::cout << "The maximum number is: " << max << '\n';
        sum = getSum(numbers);
        std::cout << "The sum of the 10 numbers is: " << sum << '\n';
        average = getAverage(numbers, sum);
        std::cout << "The average of the 10 number is: " << average << '\n';
        even = getEven(numbers);
        odd = getOdd(numbers);
        size_t maxRowsOddAndEven = (even.size() > odd.size()) ? even.size() : odd.size();
        std::cout << std::left << std::setw(20) << "Even Numbers" << std::right << std::setw(20) << "Odd Numbers" << '\n';
        std::cout << std::string(50, '-') << '\n'; 
        for (std::size_t i = 0; i < maxRowsOddAndEven; i++ ){
            if (i < even.size()) {
                std::cout << std::left << std::setw(20) << even[i];
            } else {
                std::cout << std::left << std::setw(20) << "";
            }
            if (i < odd.size()) {
                std::cout << std::right << std::setw(20) << odd[i];
            } else {
                std::cout << std::right << std::setw(20) << "";
            }
            std::cout << '\n';
        }
        positive = getPositive(numbers);
        negative = getNegative(numbers);
        size_t maxRowsPositiveAndNegative = (even.size() > odd.size()) ? even.size() : odd.size();
        std::cout << std::left << std::setw(20) << "Positive Numbers" << std::right << std::setw(20) << "Negative Numbers:" << '\n';
        std::cout << std::string(50, '-') << '\n'; 
        for (int i = 0; i < maxRowsPositiveAndNegative; i++ ){
            if (i < positive.size()) {
                std::cout << std::left << std::setw(20) << positive[i];
            } else {
                std::cout << std::left << std::setw(20) << "";
            }
            if (i < negative.size()) {
                std::cout << std::right << std::setw(20) << negative[i];
            } else {
                std::cout << std::right << std::setw(20) << "";
            }
            std::cout << '\n';
        }
        char userChoice;
        std::cout << '\n' << "Do you want to do another analysis? (Y) yes or (N) no: ";
        std::cin >> userChoice;
        switch (userChoice) {
        case 'Y':
            break;
        case 'N':
            continueProcess = false;
            break;
        default:
            std::cout << "Error: Invalid input!" << '\n';
            return 0;
            break;
        }
    } while (continueProcess);

    return 0;
}

std::vector<double> getNumbers() {
    std::vector<double> numbers(10);
    for (int i = 0; i < 10; i++) {
        std::string prompt = std::format("Enter number {} :", (i + 1));
        numbers[i] = getValidDouble(prompt);
    }
    return numbers; 
}

double getValidDouble(const std::string& prompt) {
    bool validInput = {false};
    double value {0};
    do {
        std::cout << prompt;
        if (std::cin >> value) {
            validInput = true;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: Invalid Input! Please enter numbers only." << '\n';
        }
    } while(!validInput);
    return value;
}

double getMinimum(std::vector<double> numbers) {
    double min {numbers[0]};
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    return min;
}

double getMaximum(std::vector<double> numbers) {
    double max {numbers[0]};
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}

double getSum(std::vector<double> numbers) {
    double sum {0.0};
    for (int i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
    }
    return sum;
}

double getAverage(std::vector<double> numbers, double sum) {
    double avg {0.0};
    avg = sum / numbers.size();
    return avg;
}

std::vector<double> getEven(std::vector<double> numbers) {
    std::vector<double> evenNumbers;
    evenNumbers.reserve(numbers.size());
    for (int i = 0; i < numbers.size(); i++) {
        if (static_cast<int>(numbers[i]) % 2 == 0) {
            evenNumbers.push_back(numbers[i]);
        }
    }
    return evenNumbers;
}

std::vector<double> getOdd(std::vector<double> numbers) {
    std::vector<double> oddNumbers;
    oddNumbers.reserve(numbers.size());
    for (int i = 0; i < numbers.size(); i++) {
        if (static_cast<int>(numbers[i]) % 2 == 1) {
            oddNumbers.push_back(numbers[i]);
        }
    }
    return oddNumbers;
}

std::vector<double> getNegative(std::vector<double> numbers) {
    std::vector<double> negativeNumbers;
    negativeNumbers.reserve(numbers.size());
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] < 0) {
            negativeNumbers.push_back(numbers[i]);
        }
    }
    return negativeNumbers;
}

std::vector<double> getPositive(std::vector<double> numbers) {
    std::vector<double> positiveNumbers;
    positiveNumbers.reserve(numbers.size());
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] > 0) {
            positiveNumbers.push_back(numbers[i]);
        }
    }
    return positiveNumbers;
}