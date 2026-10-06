// A program that combines if-else and switch statement while getting different user input at the same time
#include <iostream>

// Get playerLevel
int getPlayerLevel();

// Validate user input for player level
int validatePlayerLevel(int playerLevel);

// Get difficulty
char getDifficulty(int playerLevel); 




int main() {
    // Initialize game state
    bool state = true;
    // Declare the variables for level of the player and the the difficulty
    int playerLevel;
    char difficulty;

    // Loop the prrogram
    while(state) {
        playerLevel = getPlayerLevel();
        difficulty = getDifficulty(playerLevel); 
        std::cout << "Game starting with level " << playerLevel << " character " << "and a game difficulty of " << difficulty << std::endl; 
    }
    

    return 0;

} 

int getPlayerLevel() {
    int playerLevel;
    std::cout << "Enter your player level (1-10): ";
    std::cin >> playerLevel;
    playerLevel = validatePlayerLevel(playerLevel); 
    return playerLevel;
}

int validatePlayerLevel(int playerLevel) {
    if (playerLevel < 1 || playerLevel > 10) {
        std::cout << "Invalid Level. Player level setting to 1." << std::endl;
        return playerLevel = 1;
    }
    return playerLevel; 
}
char getDifficulty(int playerLevel) {
    char level;
    std::cout << "Choose mode of Difficulty: " << '\n';
    std::cout << "E - Easy" << '\n';
    std::cout << "M - Medium" << '\n';
    std::cout << "H - Hard" << '\n';
    std::cin.ignore();
    std::cin >> level;
    switch (level) {
    case 'E':
    case 'e':
        std::cout << "Easy mode selected. " << '\n';
        level = 'E';
        break;
    case 'M':
    case 'm':
        std::cout << "Medium mode selected. " << '\n';
        level = 'M';
        break;
    case 'H':
    case 'h':
        std::cout << "Hard mode selected. Goodluck!" << '\n';
        level = 'H';
        break;
    default:
        std::cout << "Invalid choice! Defaulting to easy mode." << '\n';
        level = 'E';
    }

    // Seperate the bonuses from the return for the level.
    if ((level == 'E' || level == 'e') && playerLevel >= 5) {
         std::cout << "Bonus: Extra health for experienced player!" << '\n';
    } else if ((level == 'M' || level == 'm') && playerLevel >= 7) {
        std::cout << "Bonus: Special weapon unlocked. " << '\n';
    } else if ((level == 'H' || level == 'h') && playerLevel >= 8) {
        std::cout << "Bonus: Elite status achieved!" << '\n';
    } else {
        std::cout << "Warning: This will be challenging for your level" << '\n';
    }
    return level;
}