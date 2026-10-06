#include <climits>
#include <iostream>

/*int main() {
    // Integer Division example
    int totalPoints {95};
    int numTests {3};
    double average1 {totalPoints / numTests};
    std::cout << "Average implicit conversion: " << average1 << '\n';

    double average2 {static_cast<double>(totalPoints) / 3};
    double average3 {totalPoints / static_cast<double>(3)};
    std::cout << "Average explicit conversion: " << average2 << '\n';
    std::cout << "Average explicit conversion 2: " << average3 << '\n';
    // Character to Integer conversion
    char gradeA {'A'};
    int gradeValue1 {gradeA};
    char gradeB {'B'};
    int gradeValue2 {gradeB};
    std::cout << "ASCII value of A" << gradeA << '\n';
    std::cout << "ASCII value of B" <<  gradeB << '\n';

    double preciseValue {3.14159};
    int truncatedValue {static_cast<int>(preciseValue)};
    std::cout << "Original Value: " << preciseValue << '\n';
    std::cout << "Truncated Value: " << truncatedValue << '\n';

}*/

int main() {
    // Problem 1: Lost precision in financial calculation
    int dollars = 13425;
    float interestRate = 0.25; // 5%
    float interest = dollars * interestRate; // Issue here!    
    std::cout << "Interest earned: $" << interest << std::endl;
    // Problem 2: Unexpected truncation  
    double price = 19.99;
    int wholeDollars = static_cast<int>(price); // Issue here!    
    std::cout << "Price in whole dollars: $" << wholeDollars << std::endl;

    // Add a line that shows the lost cents from the price truncation
    double lostCents {price - static_cast<double>(wholeDollars)};
    std::cout << "Lost cents: " << lostCents << '\n';
    return 0;
}