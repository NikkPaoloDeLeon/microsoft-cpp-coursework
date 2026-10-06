// Creating a score calculator that processes game data. 
// Compare how different loop types handle the same counting task.
#include <iostream>
#include <string>
#include <cmath>
#include <limits>

void displayHeader();
void displayMenu();
int getUserChoiceMenu();
void displayLoop(int userChoice);
void forLoopFunction();
void whileLoopFunction();
void doWhileLoopFunction();

int main() {
    bool exitProcess = false;
    do {
        displayHeader();
        displayMenu();
        int userChoice {getUserChoiceMenu()};
        displayLoop(userChoice);
        if (userChoice == 4) {
            exitProcess = true;
        }

    } while (!exitProcess);
    
    return 0;
}

void displayHeader() {
    std::cout << "\n=== SCORE CALCULATOR ===" << std::endl;
}
void displayMenu() {
    std::cout << std::string(40, '-') << '\n';
    std::cout << "\tChoices\t" << '\n';
    std::cout << std::string(40, '-') << '\n';
    std::cout << "1. For Loop" << '\n';
    std::cout << "2. While Loop" << '\n';
    std::cout << "3. Do while Loop" << '\n';
    std::cout << "4. Exit" << '\n';
}
int getUserChoiceMenu() {
    int choice;
    while (true) {
        std::cout << "Enter your selected choice: ";
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cout << "Error: Invalid input" << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
            std::cout << "Error: Invalid input!" <<'\n';
            continue;
        }
        break;
    }
    return choice;
}

void displayLoop(int userChoice) {
    switch (userChoice) {
    case 1:
        forLoopFunction();
        break;
    case 2:
        whileLoopFunction();
        break;
    case 3:        
        doWhileLoopFunction();
        break;
    case 4:
        std::cout << "Thank you for using the app." << '\n';
        break;

    default:
        break;
    }
}

void forLoopFunction() {
    std::cout << "Method 1: For loop" << '\n';
    int totalScore {0};
    for (int level = 1; level <=  5; level++) {
        int levelScore {level * 100};
        totalScore += levelScore;
        std::cout << "Level " << level << ": " << levelScore << " points" << '\n';
    }
    std::cout << "Total with for loop: " << totalScore << '\n';
}

void whileLoopFunction() {
    std::cout << "Method 2: While loop" << '\n';
    int totalScore {0};
    int level {1};
    while (level <= 5) {
        int levelScore = level * 100;
        totalScore += levelScore;
        std::cout << "Level " << level << ": " << levelScore << " points" << '\n';
        level++;
    }
    std::cout << "Total with while loop: " << totalScore << '\n';
}

void doWhileLoopFunction() {

}