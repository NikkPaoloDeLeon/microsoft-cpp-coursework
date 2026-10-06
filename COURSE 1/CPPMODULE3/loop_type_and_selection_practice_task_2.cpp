//A program that validates user input using a do-while loop, which ensures the prompt appears at least once.
#include <iostream>
#include <string>
#include <limits>

void displayHeader();
int validatePlayerLevel();
void validatePlayerName(int playerLevel);

int main() {
    int playerLevel;
    displayHeader();
    playerLevel = validatePlayerLevel();
    validatePlayerName(playerLevel);
    return 0;
}

void displayHeader() {
    std::cout << std::string(5, '=') << " PLAYER REGISTRATION " << std::string(5, '=') << '\n';
}

int validatePlayerLevel() {
    int playerLevel;
    do {
        std::cout << "Enter your player level: ";
        std::cin >> playerLevel;
        if (std::cin.fail()) {
            std::cout << "Error: Invalid input!" << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (playerLevel < 1 || playerLevel > 10) {
            std::cout << "Error: Invalid level! please try again." << '\n';
        }
    } while (playerLevel < 1 || playerLevel > 10);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Valid level entered: " << playerLevel << std::endl;
        return playerLevel;
}

void validatePlayerName(int playerLevel) {
    std::string playerName;
    do {
        std::cout << "Enter your player name (Cannot be empty!): ";
        std::getline(std::cin, playerName); 
        if (playerName.empty()) {
            std::cout << "Error: Name cannot be empty!" << '\n';
        }

    } while (playerName.empty());
        std::cout << "Welcome, " << playerName << " (Level " << playerLevel << ")!" << std::endl;
}

