#include <iostream>

int main() {
    // Declare player statistic variables
    int baseScore {112};
    int bonusPoints {15};
    int timeBonus {10};

    // Do basic calculation
    int totalScore {baseScore + bonusPoints + timeBonus};
    std::cout << "Total score: " << totalScore << '\n';
    // Division and modulus 
    //int averageScore {(baseScore + bonusPoints + timeBonus) / 3};
    double averageScore {static_cast<double>(totalScore) / 3};
    int remainder {totalScore % 10};
    std::cout << "Average per section: " << averageScore << '\n';
    std::cout << "Score remainder: " << remainder << '\n';  

    return 0;
}