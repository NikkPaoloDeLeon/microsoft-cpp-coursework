// you'll create visually interesting text patterns using nested loops while 
// Mastering the iteration structures that power everything from image processing to data visualization.
#include <iostream>
#include <string>
#include <limits>

// Forward declarations
void printWelcomeMessage();
void printMenu();
int getUserChoiceMenu();
void routing(int choice, int patternheight);
int getPatternHeight();
void generateRightTriangle(int height);
void generateRightInvertedTriangle(int height);
void generatePyramid(int height);
void generateDiamond(int height);
void generateNumberPattern(int height);
void generateCustomPattern(int height);
void generateMyOwnPattern(int height);


int main() {
    bool exitProcess = false;
    while (!exitProcess)
    {
        int userChoice;
        printWelcomeMessage();
        printMenu();
        userChoice = getUserChoiceMenu();
        if (userChoice >= 1 && userChoice <= 6) {
            int patternHeight;
            patternHeight = getPatternHeight();
            routing(userChoice, patternHeight);
            continue;
        } else {
            exitProcess = true;
        }

        
    }
    std::cout << "Thank you!" << '\n';
    return 0;
}

void printWelcomeMessage() {
    std::cout << '\n' << std::string(40, '=') << "\n";
    std::cout << std::string(10, ' ') << " PATTERN GENERATOR " << std::string(10, ' ') << '\n';
    std::cout << std::string(40, '=') << '\n';
    std::cout << "This program generate various patterns" << '\n';
    std::cout << "using different types of loops." << '\n'; 
}

void printMenu() {
    std::cout << std::string(40, '-') << '\n';
    std::cout << "Select a pattern to generate:" << '\n';
    std::cout << "1. Right-angled Triangle (using for loop)" <<'\n';
    std::cout << "2. Pyramid (using while loop)" << '\n' ;
    std::cout << "3. Diamond (using do-while loop)" << '\n';
    std::cout << "4. Number Pattern (using nested loops)" << '\n';
    std::cout << "5. Custom Pattern (combination of loops)" << '\n';
    std::cout << "6. My Own Custom pattern" << '\n';
    std::cout << "7. Exit" << '\n';
}

int getUserChoiceMenu() {
    int choice {0};
    while (true) {
        std::cout << "Select Choice from numbers 1-6: ";
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cout << "Error: Invalid input! Please enter number from 1 7." << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice < 1 || choice > 7){
            std::cout << "Error: Invalid input! Please enter number from 1 -7." << '\n';
            continue;
        }
        break;
    }
    return choice;
}

int getPatternHeight() {
    int patternheight;
    while (true) {
        std::cout << "Enter pattern height: ";
        std::cin >> patternheight;
        if (std::cin.fail()) {
           std::cout << "Error: Invalid input! Please enter values between 1 and 20." << '\n';
           std::cin.clear();
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
           continue; 
        }

        if (patternheight < 1 || patternheight > 20) {
            std::cout << "Error: Invalid input! Please enter values between 1 and 20." << '\n';
            continue;
        }
        break;
    }
    return patternheight;
}



void routing(int choice, int patternHeight) {
    switch (choice)
    {
    case 1:
        generateRightTriangle(patternHeight);
        break;
    case 2: 
        generatePyramid(patternHeight);
        break;
    case 3:
        generateDiamond(patternHeight);
        break;
    case 4: 
        generateNumberPattern(patternHeight);
        break;
    case 5:
        generateCustomPattern(patternHeight);
        break;
    case 6: 
        generateMyOwnPattern(patternHeight);
        break;
    case 7:
        std::cout << "Thank you!" << '\n';
        exit;
    default:
        std::cout << "Error: Invalid input! Please enter number from 1 -6." << '\n';
        break;
    }
}

void generateRightTriangle(int height) {
    std::cout << std::string(40, '-') << '\n';
    std::cout << std::string(3, ' ') << "Right-angled Triangle (For Loop)" << '\n';
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < i; ++j) {
            std::cout << "* ";
        }
        std::cout << '\n';
    } 
    generateRightInvertedTriangle(height);
}

void generateRightInvertedTriangle(int height) {
    std::cout << '\n' << std::string(40, '-') << '\n';
    std::cout << std::string(3, ' ') << "Right-angled Inverted Triangle (For Loop)" << '\n';

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < (height-i); j++) {
            std::cout << "* ";
        }
        std::cout << '\n';
    }

}

void generatePyramid(int height){
    std::cout << '\n' << std::string(40, '-') << '\n';
    std::cout << std::string(3, ' ') << "Pyramid (While Loop)" << '\n';   
    int row {0};
    while (row < height) {    // 0 < 5
        int space {0};             
        while (space < height - row) {      // 0 < 5-0
            std::cout << " ";               // _ _ _ _ _ 
            space++;
        }
        int star {0};
        while (star < 2 * row + 1) {
            std::cout << "*";
            star++;
        }
        std::cout << '\n';
        row++;
    }
}
void generateDiamond(int height) {
    std::cout << '\n' << std::string(40, '-') << '\n';
    std::cout << std::string(3, ' ') << "Diamond Pattern (Do-While Loop)" << '\n';  
    int row {0};
    do {
        int space {0};             
        while (space < height - row) {      // 0 < 5-0
            std::cout << " ";               // _ _ _ _ _*
            space++;                        // _ _ _ _ * * *
        }                                   // _ _ _ * * * * * 
        int star {0};                       // _ _ * * * * * * *
        while (star < 2 * row + 1) {        // _ * * * * * * * * *
            std::cout << "*";               // 
            star++;
        }
        std::cout << '\n';
        row++;
    } while (row < height);
    row = height - 2;
    do { 
        int space {0};
        do {
            std::cout << " ";
            space++;
        } while (space < height - row);

        int stars {0};
        do {
            std::cout << "*";
            stars++;
        } while (stars < 2 * row + 1);
        std::cout << '\n';
        row--;
    } while (row >= 0);
    
}
void generateNumberPattern(int height) {
    std::cout << '\n' << std::string(40, '-') << '\n';
    std::cout << std::string(3, ' ') << "Number Pattern (Nested Loops)" << '\n';  
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= height - i; j++) {         // _ _ _ _ 1_
            std::cout << "  ";                          // _ _ _ 1_2_1
        }                                               // _ _ 1_2_3_2_1_
        for (int j = 1; j <= i; j++) {
            std::cout << j << " ";
        }

        for (int j = i - 1; j >= 1; j-- ) {
            std::cout << j << " ";
        }
        std::cout << '\n';
    }
}
void generateCustomPattern(int height) {
    std::cout << '\n' << std::string(40, '-') << '\n';
    std::cout << std::string(3, ' ') << "Custom Pattern (Combined Loops)" << '\n';
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= height; j++) {
            if (i == 1 || i == height || j == 1 || j == height) {
                std::cout << "* ";                                     // 00 01 02 03 04
            } else {
                std::cout << "  ";
            }
                                                                       // 10 11 12 13 14 
        }
        std::cout << '\n';
    }  

    std::cout << '\n' << std::string(40, '-') << '\n';
    std::cout << std::string(3, ' ') << "Another pattern using while and for loops" << '\n';

    int initializer {1};
    while (initializer <= height) {
        for (int j = 1; j <= height - initializer; j++) {
            std::cout << " ";
        }
        int j = initializer;
        while (j <= 2 * initializer - 1) {
            std::cout << j % 10;;
            j++;
            if (j > 2 * initializer - 1) {
                break;
            }

        }
        std::cout <<'\n';
        initializer++;
    }
    

}

void generateMyOwnPattern(int height) {
    std::cout << '\n' << std::string(40, '-') << '\n';
    std::cout << std::string(3, ' ') << "My Own Pattern (Combined Loops)" << '\n';
    int row {height-2};
    do {
        int space {0};                    // space = 5   height = 5
        while (space < height-row) {      // 5 < 5       * * * * *
            std::cout << " ";             //             _ * * * _
            space++;
        }
        int stars {0};
        do {
            std::cout << "*";
            stars++;
        } while (stars < 2 * row + 1);
        std::cout << '\n';
        row--;
    } while (row >= 0);

    row = 0;
    while (row < height) {
        for (int space = 0; space < height - row; space++) {
            std::cout << " ";
        }
        for (int stars = 0; stars < 2 * row + 1; stars++) {
            std::cout << "*";
        }
        std::cout << '\n';
        row++;
    }
}