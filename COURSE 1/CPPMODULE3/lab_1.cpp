/*
PSUEDO CODE: 
BEGIN AVERAGE COMPUTATION
    INITIALIZE SUM = 0, AVERAGE = 0, COUNT = 0
    INITIALIZE VECTOR CONTAINER SCORES TO SIZE 3 
    WHILE COUNT < 3
        PRINT ENTER SCORE FOR ASSIGNMENT COUNT: 
        READ SCORES TO INDEX COUNT
        IF READ FAILS OR SCORE[COUNT] < 0 OR SCORE[COUNT] > 100
            PRINT ERROR INVALID INPUT! SCORES MUST BE BETWEEN 0 AND 100
            CHECK FOR NUMBERIC LIMITS
            CLEAR READ
            GO BACK TO THE START OF THE ITERATION
        END IF
        SUM = SUM + SCORES AT INDEX COUNT
        COUNT++
    END WHILE
    AVERAGE = SUM/SIZE OF SCORES
    ROUND UP THE AVERAGE TO WHOLE NUMBER

    IF AVERAGE >= 90
        PRINT AVERAGE AND LETTER A
    ELSE IF AVERAGE >=80 
        PRINT AVERAGE AND LETTER B
    ELSE IF AVERAGE >= 70 
        PRINT AVERAGE AND LETTER C
    ELSE IF AVERAGE >= 60 
        PRINT AVERAGE AND LETTER D
    ELSE
        PRINT AVERAGE AND LETTER F
    END IF
END AVERAGE COMPUTATION
*/
/// Create a program that calculates final grades for students based on multiple assignment scores.
#include <iostream>
#include <vector>  
#include <limits>
#include <cmath>

int main() {
    int count {0}, sum {0};
    std::vector<int> scores(3);
    double average {0};

    while (count < scores.size()) {
        std::cout << "Enter score for assignment " << (count + 1) << ": ";
        std::cin >> scores[count];
        if (std::cin.fail() || scores[count] < 0 || scores[count] > 100) {
            std::cout << "ERROR: INVALID INPUT! SCORES MUST BE BETWEEN 0 AND 100" << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        sum += scores[count];
        count++;
    }
    average = static_cast<double>(sum)/scores.size();

    if (average >= 90) {
        std::cout << "Average score: " << static_cast<int>(std::round(average)) << ' ' << "Letter grade: A" << '\n';
    } else if (average >= 80) {
        std::cout << "Average score: " << static_cast<int>(std::round(average)) << ' ' << "Letter grade: B" << '\n';
    } else if (average >= 70) {
        std::cout << "Average score: " << static_cast<int>(std::round(average)) << ' ' << "Letter grade: C" << '\n';
    } else if (average >= 60) {
        std::cout << "Average score: " << static_cast<int>(std::round(average)) << ' ' << "Letter grade: D" << '\n';
    } else {
        std::cout << "Average score: " << static_cast<int>(std::round(average)) << ' ' << "Letter grade: F" << '\n';
    }
    return 0;
}