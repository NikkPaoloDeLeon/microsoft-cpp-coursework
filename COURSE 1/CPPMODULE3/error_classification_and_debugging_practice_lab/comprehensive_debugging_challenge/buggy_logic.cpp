 /*
 * Buggy Logic Game
 * 
 * This program implements a simple number-guessing game:
 * 1. The computer generates a random number
 * 2. The player tries to guess the number
 * 3. The computer provides hints (higher/lower)
 * 4. The game ends when the player guesses correctly
 * 
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

// Forward declaration
int generateRandomNumber(int min, int max);
void playGame();
void displayInstructions();
bool playAgain();

int main() {
    std::cout << "=== Buggy Number Guessing Game ===" << '\n';
    // Seed the random number generator
    /// srand(time(0)); Error: Runtime error - Conversion from time to int
    std::srand(static_cast<unsigned>(std::time(0)));
    displayInstructions();
    bool continuePlaying = true;
    while (continuePlaying) {
        playGame();
        continuePlaying = playAgain();
    }
    std::cout << "Thank you for playing!" << '\n';
    return 0;
}
// Display game instructions
void displayInstructions() {
    std::cout << "\nWelcome to the Number Guessing Game!" << '\n';
    std::cout << "I'm thinking of a number between 1 and 100." << '\n';
    std::cout << "Try to guess the number, and I'll tell you if it's too high or too low." << '\n';
    std::cout << "Let's begin!" << '\n';
}
// Generate a random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    /// return min + std::rand() % (max + 1); // Bug: Incorrect range calculation; Error: Logical error - Exceeding the maximum range of numbers
    return min + std::rand() % (max - min + 1);
}

// Play one round of the game
void playGame() {
    const int MIN_NUMBER = 1;
    const int MAX_NUMBER = 100; 
    int secretNumber = generateRandomNumber(MIN_NUMBER, MAX_NUMBER);
    int playerGuess; 
    int numberOfGuesses = 0;
    bool hasGuessCorrectly = false;
    while (!hasGuessCorrectly) {
        std::cout << "Enter your guess: ";
        std::cin >> playerGuess;
        std::cout << "Debug: Secret number = " << secretNumber << '\n';
        std::cout << "Debug: Player guess = " << playerGuess << '\n';
         numberOfGuesses++;
        /// if (playerGuess = secretNumber) { // Bug: Assignment instead of comparison; Error: Logical error = used of assignement operator to a logical process
        if (playerGuess == secretNumber) {
            std::cout << "Congratulations! You guessed the number in " << numberOfGuesses << " guesses!" << '\n';
            hasGuessCorrectly = true;
         } else if (playerGuess < secretNumber) {
            std::cout << "Too low. Try again!" << '\n';
        } else if (playerGuess > secretNumber) {
            std::cout << "Too high. Try again!" << '\n';
        }
        // Add a reasonable limit on guesses to prevent infinite loops
        if (numberOfGuesses >= 10) {
            std::cout << "You've used all your guesses! The number was " << secretNumber << "." << '\n';
            hasGuessCorrectly = true;
        }
    }

}
// Ask if the player wants to play again
bool playAgain() {
    char response;
    std::cout << "\nDo you want to play again? (y/n): ";
    std::cin >> response;
    // Bug: Should only return true for 'y' or 'Y'
    /// return (response != 'n'); Error: Logical error - should only return true if 'y'
    return (response == 'y');
}