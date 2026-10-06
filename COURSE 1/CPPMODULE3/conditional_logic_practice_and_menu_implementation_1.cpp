// A simple text-based adveenture game where player chooses left or right path
#include <iostream>
#include <string>


// forward declarations
// function for the start game

int displayMenu();
int startGame();
int loadGame();
int viewHighscore();
int settings();
int helpOrInstructions();

int main() {
    bool initializeGame = false;
    while (!initializeGame) {
        initializeGame = displayMenu();
    }

    return 0;
}

int displayMenu() {
    int menuChoice;
    std::cout << "=== Game Menu === " << '\n';
    std::cout << "1. Start New Game" << '\n';
    std::cout << "2. Load Game" << '\n';
    std::cout << "3. View High Scores" << '\n';
    std::cout << "4. Settings" << '\n';
    std::cout << "5. Help or Instructions" << '\n';
    std::cout << "6. Exit Game" << '\n';
    std::cin >> menuChoice;
    switch (menuChoice) {
        case 1:
            startGame();
            break;
        case 2:
            loadGame();
            break;
        case 3:
            viewHighscore();
            break;
        case 4: 
            settings();
            break;
        case 5:
            helpOrInstructions();
            break;
        case 6: {
            std::cout << "Are you sure you want to exit the game? Yes or No: ";
            std::string choice;
            std::cin.ignore();
            std::getline(std::cin, choice);
            if (choice == "yes" || choice == "YES") {
                std::cout << "Thank you for playing!";
                return 1;   
            } else if (choice == "no" || choice == "NO") {
                return 0;
            }
            break;
        }
            
    default:
        std::cout << "Invalid choice. Please select 1-5: ";
        displayMenu();
        break;
    }
    return 1;
}

int startGame() {
    std::string playerChoice;
    std::cout << "Welcome to the adventure game" << '\n';
    std::cout << "Starting new adventure game." << '\n';
    std::cout << "Wecome, brave explorer" << '\n';
    std::cout << "You stand at a cross roads, in a mysterious forsest." << '\n';
    std::cout << "Do you want to go 'left' or 'right'? ";
    std::cin >> playerChoice; 
    if (playerChoice == "LEFT" || playerChoice == "left") {
        std::cout << "You discover a hidden chest!" << '\n';
        std::cout << "Inside you fin 1000 gold coins";
        return 0; 
    } else if (playerChoice == "RIGHT" || playerChoice == "right") {
        std::cout << "You meet a wise old sage. " << '\n';
        std::cout << "The sage gave you a magical potion. " << '\n';
        return 0;
    } else {
        std::cout << "You stand still, unsure of your choice." << '\n';
        std::cout << "Time passess nothing happens." << '\n';
    }
    return 0; 
}
int loadGame() {
    std::cout << "Loading saved game..." << '\n';
    std::cout << "Game loaded successfully." << std::endl;
    return 0;
}
int viewHighscore() {
    std::cout << "=== HIGH SCORES ===" << '\n';
    std::cout << "1. Alice - 15,000 points" << '\n';
    std::cout << "2. Bob - 12,500 points" << '\n';
    return 0;
}
int settings() {
    std::cout << "Opening settings menu..." << '\n';
    std::cout << "Sound: ON, Difficulty: Medium" << '\n';
    return 0;
}
int helpOrInstructions() {
    std::cout << "Opening Instructions menu..." << '\n';
    std::cout << "Basic Instructions" << '\n';
    return 0;
}