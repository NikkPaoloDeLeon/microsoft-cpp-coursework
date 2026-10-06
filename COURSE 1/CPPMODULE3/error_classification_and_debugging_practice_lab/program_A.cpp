/*
#include <iostream>
#include <limits>
#include <string>
#include <format>

int getValidInteger(const std::string& prompt);



int main() {
    int score1, score2, score3;
    int count {1};
    std::string score1String = std::format("Enter test score ", count);
    score1 = getValidInteger(score1String);
    count++;
    std::string score2String = std::format("Enter test score ", count);
    score2 = getValidInteger(score2String);
    count++;
    std::string score3String = std::format("Enter test score ", count);
    score3 = getValidInteger(score3String);
    double average {0.0};
    average = (score1 + score2 + score3) / count;
    std::cout << "Average: " << average << '\n';

    
}

int getValidInteger(const std::string& prompt) {
    bool validInput {false};
    int value {0};
    do {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: Invalid input!" << '\n';
            continue;
        }
        validInput = true;
    } while (!validInput);
    return value;
}
*/
#include <iostream>
using namespace std;
int main() {
    int score1, score2, score3;
    cout << "Enter three test scores: ";
    cin >> score1 >> score2 >> score3;
    double average = (score1 + score2 + score3) / 3;
    cout << "Average score: " << average << endl;
    return 0;
}