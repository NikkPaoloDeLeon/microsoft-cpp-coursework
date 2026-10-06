//  Multi-function utility program that users can interact with via a text-based menu.
#include <iostream>
#include <string>
#include <format>
#include <limits>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <format>
#include <cctype>
#include <sstream>

// Forward declarations
void displayMainmenu();
int validateUserIntegerInput(const std::string& prompt);
//void dateDifferenceCalculator();
bool validateUserCharInput(const std::string& prompt);
void wordCounter();
void wordCounterHeader();
void wordCounterMenu();
void wordCounterProcessRouting(int choice);
void countLetters();
void countWords();
void countSpaces();
void countAll();
void highOrLowMiniGame();
bool highOrLowMiniGameProcess(int numberOfGuesses, int secretNumber);
int generateRandomInteger(int min, int max);
void powerAllotmentGame();
std::vector<int> attributeAllotment(int attributeCount);
std::vector<int> attributeAllotmentAI(int attributeCount);
int generateRandomInteger(int max);
void basicCalculator();
double validateUserDoubleInput(const std::string& prompt);
double sumProcess(std::vector<double> addends);
void addition();
void division();
void subtraction();
void multiplication();
double differenceProcess(const std::vector<double>& operands);
double multiplicationProcess(const std::vector<double>& operands);
double quotientProcess(const std::vector<double>& operands);


// Entry point to the program
int main() {
    bool running {true};
    do {
        int userChoice {0};
        displayMainmenu();
        userChoice = validateUserIntegerInput("Please enter your choice: ");
        switch (userChoice) {
            case 1: 
                wordCounter();
                break;
            case 2: 
                highOrLowMiniGame();
                break;
            case 3:
                powerAllotmentGame();
                break;
            case 4:
                basicCalculator();
                break;
            case 5:
                std::cout << "Thank you for trying this utility system!" << '\n';
                running = false;
                break;
            default: 
                std::cout << "Invalid Input! Returning to main menu..." << '\n';
                break;
        }
    } while (running);
    return 0;
}

void displayMainmenu() {
    std::cout << std::string(5, '=') << " UTILITY PROGRAM MENU " << std::string(5, '=') << '\n';
    std::cout << "PRESS 1: Word Counter" << '\n';
    std::cout << "PRESS 2: High or Low mini Game" << '\n';
    std::cout << "PRESS 3: Power Allotment Game" << '\n';
    std::cout << "PRESS 4: Basic Addition" << '\n';
    std::cout << "PRESS 5: Exit" << '\n';
}
void wordCounter() {
    // Initialize program state
    bool exitProcess {false};
    int menuChoice {0};
    do {
        wordCounterHeader(); 
        wordCounterMenu();
        std::string menuChoicePrompt = "Select the process you want to do: ";
        menuChoice = validateUserIntegerInput(menuChoicePrompt);
        wordCounterProcessRouting(menuChoice);
    } while (!exitProcess);
}

// Display header for the division function
void wordCounterHeader() {
    std::cout << '\n' << std::string(55, '=') << '\n';
    std::cout << '=' << std::string(53, ' ') << '=' << '\n';
    std::cout << '=' << std::string(15, ' ') << "WELCOME TO WORD COUNTER" << std::string(15, ' ') << '=' << '\n';
    std::cout << std::string(55, '=') << '\n';
}
// Display the available options that
void wordCounterMenu() {
    std::cout << "1. Count Letters" << '\n';
    std::cout << "2. Count Words" << '\n';
    std::cout << "3. Count Spaces" << '\n';
    std::cout << "4. Count All" << '\n';
    std::cout << "5. Exit" << '\n';
}
void wordCounterProcessRouting(int choice) {
    switch (choice) {
    case 1:
        countLetters();
        break;
    case 2:
        countWords();
        break;
    case 3:
        countSpaces();
        break;
    case 4:
        countAll();
        break;
    default:
        std::cout << "Invalid input!" << '\n';
        break;
    }
}

// Word counter letter count function
void countLetters() {
    int letterCount {0};
    std::string stringOfWords;
    std::cout << '\n' << "Please enter a string or a sentence: " << '\n';
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, stringOfWords);
    for (size_t i = 0; i < stringOfWords.length(); i++) {

        if (stringOfWords.empty()) {
            std::cout << "String is empty!" << '\n';
            return;
        }
        char character = stringOfWords[i];
        unsigned char uCharacter = static_cast<unsigned char>(character);

        if (isalpha(uCharacter)) {
            letterCount++;
        }
    }
    std::cout << '\n' << "The string (" << stringOfWords << ") has " << letterCount << " letters." << '\n';
    
}

void countWords() {
    int wordCount {0};
    std::string stringOfWords;
    std::string word;
    std::cout << '\n' << "Please enter a string or a sentence: " << '\n';
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, stringOfWords);
    if (stringOfWords.empty()) {
        std::cout << "String is empty!" << '\n';
        return;
    }
    std::stringstream strStream(stringOfWords);
    while (strStream >> word) {
        wordCount++;
    }
    std::cout << '\n' << "The string (" << stringOfWords << ") has " << wordCount << " words." << '\n';
}

void countSpaces() {
    int spaceCount {0};
    std::string stringOfWords;
    std::cout << '\n' << "Please enter a string or a sentence: " << '\n';
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, stringOfWords);
    for (size_t i = 0; i < stringOfWords.length(); i++) {

        if (stringOfWords.empty()) {
            std::cout << "String is empty!" << '\n';
            return;
        }
        char character = stringOfWords[i];
        unsigned char uCharacter = static_cast<unsigned char>(character);

        if (isspace(uCharacter)) {
            spaceCount++;
        }
    }
    std::cout << '\n' << "The string (" << stringOfWords << ") has " << spaceCount << " spaces." << '\n';
}
void countAll() {
    int letterCount {0};
    int wordCount{0};
    int spaceCount{0};
    std::string stringOfWords;
    std::string word;
    std::cout << '\n' << "Please enter a string or a sentence: " << '\n';
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, stringOfWords);
    for (size_t i = 0; i < stringOfWords.length(); i++) {

        if (stringOfWords.empty()) {
            std::cout << "String is empty!" << '\n';
            return;
        }
        char character = stringOfWords[i];
        unsigned char uCharacter = static_cast<unsigned char>(character);

        if (isalpha(uCharacter)) {
            letterCount++;
        }
            if (isspace(uCharacter)) {
            spaceCount++;
        }
    }
    std::stringstream strStream(stringOfWords);
    while (strStream >> word) {
        wordCount++;
    }
    std::cout << std::left << std::setw(15) << "# of Words" << std::right << std::setw(15) << "# of Letters" << std::right << std::setw(15) << "# of spaces" << '\n';
    std::cout << std::left << std::setw(15) << wordCount << std::right << std::setw(15) << letterCount << std::right << std::setw(15) << spaceCount << '\n';
}




void highOrLowMiniGame() {
    bool exitProcess {false};
    do {
        std::srand(static_cast<unsigned>(time(0)));
        int min {1};
        int max {50};
        int numberOfGuesses {1};
        bool result {false};
        std::cout << '\n' << std::string(5, '=') << " WELCOME TO HIGH OR LOW MINIGAME" << std::string(5, '=') << '\n';
        std::cout << "This is a mini game where in you guess a number from 0 to 50," << '\n';
        std::cout << "and you are given 10 tries to guess the secret number. The system will only tell you" << '\n';
        std::cout << "if your guess is higher or lower than the secre number." << '\n';
        std::cout << "System : Choosing number from 1 to 50... " << '\n';
        std::cout << "..." << '\n';
        int secretNumber = generateRandomInteger(min, max);
        std::cout << "I have now a number in mind... " << '\n';
        std::cout << "Debugging: Secret number = " << secretNumber << '\n'; 
        highOrLowMiniGameProcess(numberOfGuesses, secretNumber);
        if (result == true) {
            std::cout << "Congratulation in guessing the secret number " << secretNumber << '\n';
        } else {
            std::cout << "Life is not always a win. " << '\n';
        }
        exitProcess = validateUserCharInput("\nDo you still want to do another process? Y or N: "); 
        if (exitProcess) {
            std::cout << "Going back to main menu..." << '\n';
        } 
    } while(!exitProcess);
}

bool highOrLowMiniGameProcess(int numberOfGuesses, int secretNumber) {
    std::string prompt;
    int userGuess {0};
    while (numberOfGuesses <= 11 && userGuess != secretNumber) {
        switch (numberOfGuesses) {
            case 1:
                prompt =  std::format("What is your {}st guess: ", numberOfGuesses);
                break;
            case 2:
                prompt =  std::format("What is your {}nd guess: ", numberOfGuesses);
                break;
            case 3:
                prompt =  std::format("What is your {}rd guess: ", numberOfGuesses);
                break;
            case 4:
                prompt =  std::format("What is your {}th guess: ", numberOfGuesses);
                break;
            case 5:
                prompt =  std::format("What is your {}th guess: ", numberOfGuesses);
                break;
            case 6:
                prompt =  std::format("What is your {}th guess: ", numberOfGuesses);
                break;
            case 7:
                prompt =  std::format("What is your {}th guess: ", numberOfGuesses);
                break;
            case 8:
                prompt =  std::format("What is your {}th guess: ", numberOfGuesses);
                break;
            case 9:
                prompt =  std::format("What is your {}th guess: ", numberOfGuesses);
                break;
            case 10:
                prompt =  std::format("What is your last guess: ", numberOfGuesses);
                break;
            default:
                break;
            }
            userGuess = validateUserIntegerInput(prompt);
        if (userGuess == secretNumber) {
            std::cout << "You have guessed the secret number " << secretNumber << " in just " << numberOfGuesses << " guesses!" << '\n';
            break;
        } else if (userGuess > secretNumber) {
            std::cout << "Your guess " << userGuess << " is higher than the secret number." << '\n'; 
            numberOfGuesses++;
        } else if (userGuess < secretNumber) {
             std::cout << "Your guess " << userGuess << " is lower than the secret number." << '\n'; 
             numberOfGuesses++;
        } 
        if (numberOfGuesses == 11) {
            std::cout << "You've used all your guesses!. Nice try!" << '\n';
            break;  
        }
    }
    return (userGuess == secretNumber ? true : false);
}

void powerAllotmentGame() {
    std::srand(static_cast<unsigned>(time(0)));
    bool exitProcess {false};
    do {
        int areas {0};
        std::cout << '\n' << std::string(3, '=') << " WELCOME TO POWER ALLOTMENT GAME " << std::string(3, '=') << '\n';
        std::cout << "This is a game where you chose how many areas" << '\n';
        std::cout << "you will divide. The minimum number of areas is 3 and the maximum is 5." << '\n';
        std::cout << "If you chose 3 you will divide 80 points in those 3 areas. After alloting" << '\n';
        std::cout << "the points you will simulate agaisnt the computer who also alloted points" << '\n';
        std::cout << "in those 3 areas. Higher point wins! NOTE: YOU CANNOT EXCEED THE MAX POINTS!" << '\n';
        std::cout << "LETS BEGIN!" << '\n';
        std::string prompt = "How may Areas do you want to have? (3 - 5): ";
        areas = validateUserIntegerInput(prompt);
        //std::cout << "You have chosen " << areas << " areas." <<'\n';
        std::vector<int> attributeStoragePlayer = attributeAllotment(areas);

        for (int i = 0; i < areas; i++) {
            std::cout << "Power at area " << i + 1 << " = " << attributeStoragePlayer[i] << '\n';
        }

        std::cout << "Now its the AI's turn to allot power to areas..." << '\n';
        std::cout << "AI is allotting power..." << '\n';
        std::cout << "..." << '\n';
        std::vector<int> attributeStorageAI = attributeAllotmentAI(areas);
        std::cout << "AI is done alloting power!" << '\n';

        std::cout << "The battle begins!" << '\n';
        std::cout << std::string(30, '=') << '\n';
        std::cout << std::left << std::setw(15) << "PLAYER" << std::right << std::setw(15) << "COMPUTER" << '\n';
        for (int i = 0; i < areas; ++i) {
            std::cout << std::left << std::setw(15) << attributeStoragePlayer[i] << std::right << std::setw(15) << attributeStorageAI[i] << '\n';
        } 



        exitProcess = true;

    } while(!exitProcess);

}
std::vector<int> attributeAllotmentAI(int attributeCount) {
    int power {0};
    int availablePowerCapacity {0};
    int maxPowerCapacity {0};

    switch (attributeCount) {
    case 3:
        maxPowerCapacity = 30;
        break;
    case 4:
        maxPowerCapacity = 60;
        break;
    case 5:
        maxPowerCapacity = 100;
        break;
    default:
        break;
    }

    std::vector<int> attributeStorage(attributeCount);
    attributeStorage.reserve(attributeCount);
    availablePowerCapacity = maxPowerCapacity;
    for (int i = 0; i < attributeCount && availablePowerCapacity > 0;) {
        power = generateRandomInteger(maxPowerCapacity);

        if (power > maxPowerCapacity || power < 0) {
            //std::cout << "Invalid power! Power should be between 0 and " << maxPowerCapacity << '.' << '\n';
            continue;
        }
        if (power > availablePowerCapacity) {
            //std::cout << "You cannot exceed your power capacity!" << '\n';
            //std::cout << "You only have " << availablePowerCapacity << " power capacity" << '\n';
            continue;   
        }

        availablePowerCapacity -= power;

        //std::cout << "Available power left for allotment: " << availablePowerCapacity << '\n';

        attributeStorage[i] = power;

        if (availablePowerCapacity <= 0) {
            break;
        }
        i++;

    }
    return attributeStorage;
}

int generateRandomInteger(int max) {
    return 0 + std::rand() % (max - 0 + 1);
}

std::vector<int> attributeAllotment(int attributeCount) {
    int power {0};
    int maxPowerCapacity {0};
    int availablePowerCapacity {0};

    switch (attributeCount) {
        case 3:
            std::cout << "You have chosen " << attributeCount <<  " areas." << '\n';
            std::cout << "Your maximum points to allot is 30." << '\n';
            maxPowerCapacity = 30;
            break;
        case 4: 
            std::cout << "You have chosen " << attributeCount <<  " areas." << '\n';
            std::cout << "Your maximum points to allot is 60." << '\n';
            maxPowerCapacity = 60;
            break;
        case 5: 
            std::cout << "You have chosen " << attributeCount <<  " areas." << '\n';
            std::cout << "Your maximum points to allot is 100." << '\n';
            maxPowerCapacity = 100;
            break;
        default:
            std::cout << "Invalid input!" << '\n';
            break;
    }
    std::vector<int> attributeStorage(attributeCount);
    attributeStorage.reserve(attributeCount);
    availablePowerCapacity = maxPowerCapacity;


    for (int i = 0; i < attributeCount && availablePowerCapacity > 0;) {
        std::string prompt = std::format("Enter power for area {}: ", i + 1);
        power = validateUserIntegerInput(prompt);

        if (power > maxPowerCapacity || power < 0) {
            std::cout << "Invalid power! Power should be between 0 and " << maxPowerCapacity << '.' << '\n';
            continue;
        }
        if (power > availablePowerCapacity) {
            std::cout << "You cannot exceed your power capacity!" << '\n';
            std::cout << "You only have " << availablePowerCapacity << " power capacity" << '\n';
            continue;   
        }
        availablePowerCapacity -= power;

        std::cout << "Available power left for allotment: " << availablePowerCapacity << '\n';

        attributeStorage[i] = power;

        if (availablePowerCapacity <= 0) {
            break;
        }
        i++; 
    }

    return attributeStorage;


}

// Function to perform random number generation
int generateRandomInteger(int min, int max) {
    return std::rand() % (max + 1);
}

// Validates user input for yes or no
bool validateUserCharInput(const std::string& prompt) {
    bool validInput {false};
    char validatedUserChoice;
    do {
        std::cout << prompt;
        std::cin >> validatedUserChoice;
        if (std::cin.fail() || std::cin.peek() != '\n' || (validatedUserChoice != 'y' && validatedUserChoice != 'Y' && validatedUserChoice != 'n' && validatedUserChoice != 'N')) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid Input! Enter Y or N only." << '\n';
        }
        validInput = true;
    } while (!validInput);
    return validatedUserChoice;
}

// Function to validate user input as integer only
int validateUserIntegerInput(const std::string& prompt) {
    bool validInput {false};
    int validatedUserChoice {0};
    do {
        std::cout << prompt;
        std::cin >> validatedUserChoice;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid Input! Select only from the choices." << '\n';
            continue;
        }
        validInput = true;
    } while (!validInput);
    return validatedUserChoice;
}

// Starting point for the function 
void basicCalculator() {
    // Initialize progam state and choice of operation 
    bool exitProcess {false};
    int operationChoice {0};

    // Initialize vector to store the addends
    std::vector<double> addends;
    // Initialize the state of this funciton
    //bool exitProcess {false};

    do {
        // Display header and instruction
        std::cout << '\n' << std::string(25, '=') << '\n';
        std::cout << "         WELCOME TO BASIC CALCULATOR            " << '\n';
        std::cout << std::string(25, '=') << '\n';
        std::cout << "PLEASE SELECT THE BASIC MATHEMATICAL OPERATION YOU WANT TO DO" << '\n';
        std::cout << "1. Addition" << '\n';
        std::cout << "2. Subtraction" << '\n';
        std::cout << "3. Multiplication" << '\n';
        std::cout << "4. Division" << '\n';
        std::cout << "5. Exit" << '\n';
        std::string operationPrompt =" Enter your choice of operation: ";
        operationChoice = validateUserIntegerInput(operationPrompt);
        
        // Routing to the right mathematical operation functions
        switch (operationChoice) {
        case 1:
            addition();
            break;
        case 2:
            subtraction();
            break;
        case 3:
            multiplication();
            break;
        case 4:
            division();
            break;
        case 5:
            std::cout << "Thank you for using the basic calculator!" << '\n';
            std::cout << "RETURNING TO THE MAIN PAGE..." << '\n';
            exitProcess = true;
            break;
        default:
            std::cout << "Invalid input!" << '\n';
            break;
        }
    } while (!exitProcess);
}

void addition() {
    // Initialize vector to store the addends
    int size {0};
    double sum {0.0};
    std::vector<double> addends;
    // Initialize the state of this funciton
    bool exitProcess {false};
    do {
        // Display header for the addition function
        std::cout << '\n' << std::string(55, '=') << '\n';
        std::cout << "         WELCOME TO BASIC ADDITION            " << '\n';
        std::cout << std::string(55, '=') << '\n';
        std::cout << "You can add upto how many numbers you want to. " << '\n';
        std::cout << "Just tell how many number you want to add. Followed" << '\n';
        std::cout << "by the numbers." << '\n';
        std::cout << "Lets begin..." << '\n';
        std::string prompt1 = "Enter how many number you want to add: ";
        size = validateUserIntegerInput(prompt1);
        if (size == 1) {
            std::cout << "Minimum numbers to be added is 2." << '\n';
            continue;
        }
        // Reserve a memory for the vector addends
        addends.reserve(size);
        for (int i = 0; i < size; ++i) {
            std::string prompt2 = std::format("Enter number {}: ", i+1);
            addends.push_back(validateUserDoubleInput(prompt2));
        }
        sum = sumProcess(addends);
        std::cout << "The sum of the " << size << " numbers (";
        for (int i = 0; i < size; ++i) {
            if (i == (size-1)) {
                std::cout << addends[i] << ") is " << sum << '\n';
                continue;
            }
            std::cout << addends[i] << ", ";
        }
        std::string prompt3 = "Do you want to do another addition? Y or N: ";
        char choice;
        choice = validateUserCharInput(prompt3);
        switch (choice) {
        case 'Y':
        case 'y':
            break;
        case 'N':
        case 'n':
            exitProcess = true;
            break;
        default:
            std::cout << "Invalid input!" << '\n';
            break;
        }
    } while (!exitProcess);
  
}

void subtraction() {
    // Initialize vector to store the operands
    int size {0};
    double difference {0.0};
    std::vector<double> operands;
    // Initialize the state of this funciton
    bool exitProcess {false};
    do {
        // Display header for the addition function
        std::cout << '\n' << std::string(55, '=') << '\n';
        std::cout << "         WELCOME TO BASIC SUBTRACTION           " << '\n';
        std::cout << std::string(55, '=') << '\n';
        std::cout << "You can subtract upto how many numbers you want to. " << '\n';
        std::cout << "Just tell how many number you want to subtract. Followed" << '\n';
        std::cout << "by the numbers." << '\n';
        std::cout << "Lets begin..." << '\n';
        std::string prompt1 = "Enter how many number you want to subtract: ";
        size = validateUserIntegerInput(prompt1);
        if (size == 1) {
            std::cout << "Minimum numbers to do subtraction is 2." << '\n';
            continue;
        }
        // Reserve a memory for the vector addends
        operands.reserve(size);
        for (int i = 0; i < size; ++i) {
            std::string prompt2 = std::format("Enter number {}: ", i+1);
            operands.push_back(validateUserDoubleInput(prompt2));
        }
        difference = differenceProcess(operands);
        std::cout << "The difference of the " << size << " numbers (";
        for (int i = 0; i < size; ++i) {
            if (i == (size-1)) {
                std::cout << operands[i] << ") is " << difference << '\n';
                continue;
            }
            std::cout << operands[i] << ", ";
        }
        std::string prompt3 = "Do you want to do another subtraction? Y or N: ";
        char choice;
        choice = validateUserCharInput(prompt3);
        switch (choice) {
        case 'Y':
        case 'y':
            break;
        case 'N':
        case 'n':
            exitProcess = true;
            break;
        default:
            std::cout << "Invalid input!" << '\n';
            break;
        }
    } while (!exitProcess);
  
}
void multiplication() {
    // Initialize vector to store the operands
    int size {0};
    double product {0.0};
    std::vector<double> operands;
    // Initialize the state of this funciton
    bool exitProcess {false};
    do {
        // Display header for the multiplication function
        std::cout << '\n' << std::string(55, '=') << '\n';
        std::cout << "         WELCOME TO BASIC MULTIPLICATION           " << '\n';
        std::cout << std::string(55, '=') << '\n';
        std::cout << "You can multiply upto how many numbers you want to. " << '\n';
        std::cout << "Just tell how many number you want to subtract. Followed" << '\n';
        std::cout << "by the numbers." << '\n';
        std::cout << "Lets begin..." << '\n';
        std::string prompt1 = "Enter how many number you want to multiply: ";
        size = validateUserIntegerInput(prompt1);
        if (size == 1) {
            std::cout << "Minimum numbers to do multiplication is 2." << '\n';
            continue;
        }
        // Reserve a memory for the vector operands
        operands.reserve(size);
        for (int i = 0; i < size; ++i) {
            std::string prompt2 = std::format("Enter number {}: ", i+1);
            operands.push_back(validateUserDoubleInput(prompt2));
        }
        product = multiplicationProcess(operands);
        std::cout << "The product of the " << size << " numbers (";
        for (int i = 0; i < size; ++i) {
            if (i == (size-1)) {
                std::cout << operands[i] << ") is " << product << '\n';
                continue;
            }
            std::cout << operands[i] << ", ";
        }
        std::string prompt3 = "Do you want to do another multiplication? Y or N: ";
        char choice;
        choice = validateUserCharInput(prompt3);
        switch (choice) {
        case 'Y':
        case 'y':
            break;
        case 'N':
        case 'n':
            exitProcess = true;
            break;
        default:
            std::cout << "Invalid input!" << '\n';
            break;
        }
    } while (!exitProcess);
}
void division() {
    // Initialize vector to store the operands
    int size {0};
    double quotient {0.0};
    std::vector<double> operands;
    // Initialize the state of this funciton
    bool exitProcess {false};
    do {
        // Display header for the division function
        std::cout << '\n' << std::string(55, '=') << '\n';
        std::cout << "         WELCOME TO BASIC DIVISION           " << '\n';
        std::cout << std::string(55, '=') << '\n';
        //std::cout << "You can subtract upto how many numbers you want to. " << '\n';
        std::cout << "Just tell how many number you want to Divide. Followed" << '\n';
        std::cout << "by the numbers." << '\n';
        std::cout << "Lets begin..." << '\n';
        std::string prompt1 = "Enter how many number you want to divide: ";
        size = validateUserIntegerInput(prompt1);
        if (size == 1) {
            std::cout << "Minimum numbers to do division is 2." << '\n';
            continue;
        }
        // Reserve a memory for the vector operands
        operands.reserve(size);
        for (int i = 0; i < size;) {
            std::string prompt2 = std::format("Enter number {}: ", i+1);
            double nonZeroDivisor {0.0};
            nonZeroDivisor = validateUserDoubleInput(prompt2);
            if (i > 0 && nonZeroDivisor == 0.0) {
                std::cout << "Cannot accept 0 as a divisor!" << '\n';
                continue;
            }
            operands.push_back(nonZeroDivisor);
            i++;
        }
        quotient = quotientProcess(operands);
        std::cout << "The quotient of the " << size << " numbers (";
        for (int i = 0; i < size; ++i) {
            if (i == (size-1)) {
                std::cout << operands[i] << ") is " << quotient << '\n';
                continue;
            }
            std::cout << operands[i] << ", ";
        }
        std::string prompt3 = "Do you want to do another division? Y or N: ";
        char choice;
        choice = validateUserCharInput(prompt3);
        switch (choice) {
        case 'Y':
        case 'y':
            break;
        case 'N':
        case 'n':
            exitProcess = true;
            break;
        default:
            std::cout << "Invalid input!" << '\n';
            break;
        }
    } while (!exitProcess);
}
double sumProcess(std::vector<double> addends) {
    double sum {0.0};
    for (int i = 0; i < static_cast<int>(size(addends)); ++i) {
        sum += addends[i];
    }
    return sum;
}
double differenceProcess(const std::vector<double>& operands) {
    double difference {0};
    for (int i {0}; i < static_cast<int>(size(operands)); ++i) {
        if (i == 0) {
            difference = operands[i];
            continue;
        }
        difference -= operands[i];
    }
    return difference;
}
double multiplicationProcess(const std::vector<double>& operands) {
    double product {1};
    for (int i {0}; i < static_cast<int>(size(operands)); i++) {
        product *= operands[i];
    }
    return product;
}
double quotientProcess(const std::vector<double>& operands) {
    double quotient {0.0};
    for (int i {0}; i < static_cast<int>(size(operands)); i++) {
        if (i == 0) {
            quotient = operands[i];
            continue;
        }
        quotient = quotient / operands[i];
    }
    return quotient;
}
double validateUserDoubleInput(const std::string& prompt) {
    bool validDoubleInput {false};
    double verifiedDouble {0.0};
    do {
        std::cout << prompt;
        std::cin >> verifiedDouble;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Enter a number only." << '\n';
            continue;
        }
        validDoubleInput = true;

    }while (!validDoubleInput);
    return verifiedDouble;
}



