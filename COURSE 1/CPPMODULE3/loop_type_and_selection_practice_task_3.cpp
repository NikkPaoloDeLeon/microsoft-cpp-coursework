// Using break and continue to control loop execution in a number processing scenario
#include <iostream> 
#include <limits>
#include <string>

// Forward declarations
void displayHeader();
void mainProcess();

int main() {    
    displayHeader();
    mainProcess();

    return 0;
}

void displayHeader() {
    std::cout << '\n' << std::string('=', 4) << " NUMBER PROCESSOR " << std::string('=', 4) << '\n';
    std::cout << "\nProcessing numbers 1-20:" << '\n';
    std::cout << "- Skip multiples of 3" << '\n';;
}

void mainProcess() {
    for (int num = 0; num <= 20; num++) {
        // Skips multiple of 3
        if (num % 3 == 0) {
            std::cout << num <<  " (skipped - multiple of 3)" << '\n';
            //continue;
        }
        if (num >= 15) {
            std::cout << num << " (stopping here) " << 'n';
            //break;
        }
        std::cout << num << " (processed)" << '\n';

    }
    std::cout << "--Loop finished--" << '\n';

    std::cout << "\n=== Finiding the first even number ===" << '\n';
    int numbers[] = {7, 13, 9, 14, 11, 8, 5};
    
    for (int i = 0; i < std::size(numbers); i++) {
        std::cout << "Checking " << numbers[i] << "... " << '\n';
        if (numbers[i] % 2 ==0) {
            std::cout << "Found first Even number: " << numbers[i] << '\n';
            break;
        } else {
            std::cout << "odd, continuing..." << std::endl;
        }
    }
}