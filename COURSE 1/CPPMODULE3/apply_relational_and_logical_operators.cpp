// Task 2: Apply Relational and Logical Operators
#include <iostream>

int main() {
    // Declare player attributes
    int playerlevel {10};
    int playerScore {1550};
    int minimumLevel {5};
    int minimumScore {1000};
    bool hasCompleteMap = false;
    // Relational comparisons
    bool levelQualified = playerlevel >= minimumLevel;
    bool scoreQualified = playerScore >= minimumScore;
    std::cout << "Level qualified: " << (levelQualified ? "Yes" : "No") << '\n';
    std::cout << "Score qualified: " << (scoreQualified ? "Yes" : "No") << '\n';
    // Logical combinations
    bool basicAchievement = levelQualified && scoreQualified;
    bool specialAchievement = basicAchievement && hasCompleteMap;
    bool anyQualification = levelQualified || scoreQualified;
    bool eliteAchievement = playerScore > 1500;

    std::cout << "Basic achienvement: " << (basicAchievement ? "Earned" : "Not Earned") << '\n';
    std::cout << "Special achievement: " << (specialAchievement ? "Earned" : "Not Earned") << '\n';
    std::cout << "Any qualifications: " << (anyQualification ? "Yes" : "No") << '\n';
    std::cout << "Elite achievement: " << (eliteAchievement ? "Earned" : "Not Earned") << '\n';


    return 0;
}