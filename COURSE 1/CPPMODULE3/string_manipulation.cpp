#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <iomanip>
#include <algorithm>

int main() {
    bool continueProcess {false};
    do {
        bool palindrome {false};
        int consonants {0};
        int vowels {0};
        std::vector<char> vowelConntainer;
        std::vector<char> consonantContainer;
        std::cout << "Enter a string of words or letters: " << '\n';
        std::string prompt;
        std::getline(std::cin, prompt);
        for (char letter : prompt) {
            if (std::isalpha(static_cast<unsigned char>(letter))) {
                char upperCase = std::toupper(static_cast<unsigned char>(letter));
                if (upperCase == 'A' || upperCase == 'E' || upperCase == 'I' || upperCase == 'O' || upperCase == 'U') {
                    vowels++;
                    vowelConntainer.push_back(letter);
                } else {
                    consonants++;
                    consonantContainer.push_back(letter);
                }
            }
        }
        std::string reversed(prompt.rbegin(), prompt.rend());
        std::cout << prompt << '\n';
        std::cout << reversed << '\n';
        if (prompt == reversed) {
            std::cout << "It is a palindrome!" << '\n';
            palindrome = true;
        } else {
            std::cout << "It is not a palindrome!" << '\n';
            palindrome = false;
        }

        std::cout << "Number of vowel in the string: " << vowels << '\n';
        std::cout << "number of Consonants in the string: " << consonants << '\n';
        std::size_t max_rows = (vowelConntainer.size() > consonantContainer.size()) ? vowelConntainer.size() : consonantContainer.size();
        std::cout << std::left << std::setw(20) << "Vowels" << std::right << std::setw(20) << "Consonants" << '\n';
        std::cout << std::string(50, '-') << '\n';
        for (std::size_t i = 0; i < max_rows; i++) {
            if (i < vowelConntainer.size()) {
                std::cout << std::left << std::setw(20) << vowelConntainer[i];
            } else {
                std::cout << std::left << std::setw(20) << "";
            }
            if (i < consonantContainer.size()) {
                std::cout << std::right << std::setw(20) << consonantContainer[i];
            } else {
                std::cout << std::right << std::setw(20) << "";
            }
            std::cout << '\n';
        }
        char userChoice;
        std::cout << "'\n" << "Do you still want to continue process: (Y) yes or (N) no: ";
        std::cin >> userChoice; 
        switch (userChoice) {
        case 'Y':
        case 'y':
            continueProcess = true;
            break;
        case 'N':
        case 'n':
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