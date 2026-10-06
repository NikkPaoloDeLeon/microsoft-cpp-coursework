#include <iostream>
#include <string>
#include <algorithm>
#include <ranges>
#include <vector>
#include <cmath>

// Forward declarations
int CountWordsV1(const std::string& text);
int CountWordsV2(const std::string& text);
int CharOccurence(const std::string& text);
bool PalindromeCheck(const std::string& text);
double AverageWordLength(const std::string& text);

int main() {

    std::string text {"The big brown fox, a blue bird, and a white dog jumped over the fence. They are nowhere to be found."};
    std::cout << "Number of words in the text (using CountWordsV1): " << CountWordsV1(text) << '\n';
    std::cout << "Number of words in the text (using CountWordsV2): " << CountWordsV2(text) << '\n';
    int count = CharOccurence(text);
    std::cout << count << '\n';
    std::string aPalindrome {"Madam"};
    std::string notPalindrome {"Dog"};
    std::string emptyString {""};
    std::cout << "First text is " << ((PalindromeCheck(aPalindrome) == true) ? "a palindrome" : "not a palindrome") << '\n';
    std::cout << "Second text is " << ((PalindromeCheck(notPalindrome) == true) ? "a palindrome" : "not a palindrome")  << '\n';
    std::cout << "Third text is " << ((PalindromeCheck(emptyString) == true) ? "a palindrome" : "not a palindrome")  << '\n';
    std::cout << "The string has an average word length of " << std::ceil(AverageWordLength(text)) << " letters per word." << '\n';
    

}

// Counts words, single wodrds, articles.
int CountWordsV1(const std::string& text) {
    int count {0};
    if (text.empty()) {
        std::cout << "Cannot proceed with the process string is empty!" << '\n';
    }
    count = static_cast<int>(std::count(text.begin(), text.end(),' ') + 1);
    return count;
}
// Counts words, single wodrds, article using string traversal
int CountWordsV2(const std::string& text) {
    int count {1};
    if (text.empty()) {
        std::cout << "Cannot proceed with the process string is empty!" << '\n';
    }
    for (auto& chr : text) {
        if (chr == ' ') {
            count++;
        }
    }
    return count;
}

// Function to assess character occurrences within the text, ignoring non-alphabetic characters and standardizing case.
int CharOccurence(const std::string& text) {
    int count {0};
    int lead {0};
    char temp;
    if (text.empty()) {
        std::cout << "Cannot proceed with the process string is empty!" << '\n';
    }
    for (auto& a : text) {
        if (!isalpha(a)) {
            continue;
        }
        for (auto& b : text) {
            if (!isalpha(b)) {
                continue;
            }
            //std::cout << a << " == " << b << '\n';
            if (tolower(a) == tolower(b)) {
                count++;
            }
        }
        if (count > lead) {
            temp = a;
            lead = count;
        }
        count = 0;
        
    }
    std::cout << temp << ": ";
    return lead;
}

// Check if the given text is a palindrome or not
bool PalindromeCheck(const std::string& text) {
    bool palindrome {false};
    std::string reversed(text.rbegin(), text.rend());
    if (text.empty()) {
        std::cout << "Cannot proceed with the process string is empty!" << '\n';
    }
    for (int i {0}; i < static_cast<int>(text.length()); i++) {
        //std::cout << static_cast<char>((tolower(text.at(i)))) << " : " << static_cast<char>(tolower(reversed.at(i))) << '\n';
        if (static_cast<char>((tolower(text.at(i)))) != static_cast<char>(tolower(reversed.at(i)))) {
            return palindrome = false;
        }
    }
    palindrome = true;
    return palindrome;
}

double AverageWordLength(const std::string& text) {
    double average {0};
    int numberOfWords {CountWordsV1(text)};
    int numberOfLetters {0};
    for (auto& c : text) {
        if (isalpha(c)) {
            numberOfLetters++;
        }
    }
    average = static_cast<double>(numberOfLetters) / static_cast<double>(numberOfWords);

    return average;
}