#include <iostream>

int main() {
    // Implicit conversion
    int integerVal = 8;
    double calcualatedValue = integerVal/3;
    std::cout << "Calculated value: " <<  calcualatedValue << std::endl;



    // Explicit conversion
    // FOr this one we are the one that wanted to truncate the decimal portion it did not automatically disappear we controlled it.
    double piValue = 3.14159;
    int truncatedPi = static_cast<int>(piValue);
    std::cout << "Truncated pi: " << truncatedPi << std::endl;



    // Example of potential precision loss
    int scoreSum = 215;
    float averageScore = scoreSum / 3;
    std::cout << "Average Score: " << averageScore << std::endl;

    // Preventing data loss
    // Implement type casts explicitly when conversion is necessary:
    int scoreSum2 = 215;
    float averageSCore2 = static_cast<float>(scoreSum2) / 3;
    std::cout << "Corrected Average Score: " << averageSCore2 << std::endl;
    
    int a {95};
    float b {static_cast<float>(a)};
    return 0;   
}