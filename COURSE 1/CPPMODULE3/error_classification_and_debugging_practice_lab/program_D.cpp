#include <iostream>

// int calculateGrade(int score);
char calculateGrade(int score);

int main() {
    int studentScores; 
    std::cout << "Enter students score: ";
    std::cin >> studentScores;
    char grade = calculateGrade(studentScores);
    std::cout << "Grade: " << grade << '\n';
    int scores[3] = {85, 92, 78};
    // std::cout << "Score 5: " << scores[5] << '\n';
    std::cout << "Score 3: " << scores[2] << '\n';
    
    int totalPoints = 0;
    for (int score : scores) {
        totalPoints += score;
    }
    int averagePoints = totalPoints /3;
    std::cout << "Average: " << averagePoints << '\n';
    return 0;
}

// int calculateGrade(int score) {
char calculateGrade(int score) {
    if (score >= 90) {
        return 'A';
    } else if (score >= 80) {
        return 'B';
    } else if (score >= 70) {
        return 'C';
    } else if (score >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}


