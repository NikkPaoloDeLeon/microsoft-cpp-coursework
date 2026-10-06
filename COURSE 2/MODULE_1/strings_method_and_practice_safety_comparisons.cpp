#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <array>

// Forward declarations
int countWords(const std::string& text);
std::array<int, 5> countVowels(const std::string& text);
bool isPangram(const std::string& text);

int main() {
    std::string message = "Welcome to the world of C++ programming!";
    std::cout << "Original message: " << message << '\n';

    // Extract the first word using substr
    size_t first_space = message.find(' ');
    if (first_space != std::string::npos) {
        std::string first_word = message.substr(0, first_space);
        std::cout << "First word: " << first_word << '\n';
    }
    // Your code here: Find and extract the last word using rfind() and substr()
    size_t lastSymb = message.find('!');
    size_t lastChar = message.rfind(' ');
    if (lastChar != std::string::npos) {
        std::string last_word = message.substr(lastChar, (lastSymb - lastChar));
        std::cout << "Last word: " << last_word << '\n';
    }

    // Your code here: Count how many times the letter 'o' appears in the message 
    int count {0};
    for (char& chars : message) {
        if (chars == 'o') {
            count++;
        }
    }
    std::cout << "Number of letter o's in the string message: " << count << '\n';    

    std::string text = "Hello world! The world is beautiful.";
    std::cout << "Original: " << text << '\n';

    //Replace "world" with "universe"
    size_t pos = text.find("world");
    std::cout << "Position of the word world " << pos << '\n';
    if (pos != std::string::npos) {
        text.replace(pos, 5, "universe");
        std::cout << "After first replacement: " << text << '\n';
    }

    // Your code here: Replace the second occurrence of "world" with "universe"
    // Hint: Use find() with a starting position parameter  
    size_t pos2 = text.find("world", pos); 
    if (pos2 != std::string::npos) {
        text.replace(pos2, 5, "universe");
        std::cout << "After second replacement: " << text << '\n';
    }

    // Your code here: Remove all exclamation marks from the text using erase()
    size_t pos3 = text.find('!');
    if (pos3 != std::string::npos) {
        text.erase(pos3);
        std::cout << "After erasing (!): " << text << '\n';
    }
    
    

    // Convert text to uppercase (for each character, use std::toupper)
    for (char& char2 : text) {
        char2 = static_cast<char>(std::toupper(char2));
    }

    std::cout << "After toupper: " << text << '\n';

   
    // C-style string operations
    std::cout << std::string(40, '=') << '\n';
    std::cout << "C-STYLE OPERATIONS" << '\n';
    std::cout << std::string(40, '=') << '\n';
    const char* c_str = "Hello";
    char c_buff[20];
    strcpy(c_buff, c_str);
    strcat(c_buff, " World");
    std::cout << "C-style result: " << c_buff << '\n';
    std::cout << "C-style lenght: " << strlen(c_buff) << '\n';
    
    // std::string operations
    std::string cpp_str = "Hello";
    cpp_str += " World!";
    std::cout << "std::string result: " << cpp_str << '\n';
    std::cout << "std::string lenght: " << cpp_str.length() << '\n';

    // Your code here: Demonstrate safe bounds checking
    // Try to access character at index 15 in both strings 
    
    try {
        std::cout << c_buff[15] << '\n';

        std::cout << cpp_str.at(static_cast<size_t>(sizeof(cpp_str)) + 1) << '\n';
    } catch (const std::out_of_range& e) {
        std::cout << "Index out of bounds: " << e.what() << '\n';
    }

    // Your code here: Show what happens when you try to concatenate 
    // a very long string to c_buffer (comment out to avoid crash)
    // strcat(c_buffer, " This is a very long string that will cause overflow");  
    /*try {
        strcat(c_buff, " This is a very long string that will cause overflow");
    } catch (const std::out_of_range& e) {
        std::cout << "Buffer overflow!: " << e.what() << '\n';
    }*/

    std::string text2 = "The Quick Brown Fox Jumps Over The Lazy Dog";
    // Count words (spaces + 1)
    int words = countWords(text2);
    std::cout << "Word count: " << words << '\n';

    // Your code here: Count vowels (a, e, i, o, u) - case insensitive
    std::array<int, 5> vowels = countVowels(text2);
    std::cout << "Vowel a or A count: " << vowels[0] << '\n';
    std::cout << "Vowel e or E count: " << vowels[1] << '\n';
    std::cout << "Vowel i or I count: " << vowels[2] << '\n';
    std::cout << "Vowel o or O count: " << vowels[3] << '\n';
    std::cout << "Vowel u or U count: " << vowels[4] << '\n';

    // Check if text contains all letters of the alphabet
    std::cout << "=== IS PANGRAM ===" << '\n';
    std::cout << "Is pangram: " << (isPangram(text2) == true ? "Yes" : "No") << '\n';

    return 0;
}

int countWords(const std::string& text) {
    int countW {0};
    countW = static_cast<int>(std::count(text.begin(), text.end(), ' ') + 1); 
    return countW;
}

std::array<int, 5> countVowels(const std::string& text) {
    std::array<int, 5> vowelCount {};
    for (char character: text) {
        if (character == 'a' || character == 'A') {
            vowelCount[0] += 1;
        } else if (character == 'e' || character == 'E') {
            vowelCount[1] += 1;
        } else if (character == 'i' || character == 'I') {
            vowelCount[2] += 1;
        } else if (character == 'o' || character == 'O') { 
            vowelCount[3] += 1;
        } else if (character == 'u' || character == 'U') { 
            vowelCount[4] += 1;
        } else {
            std::cout << character << " is not a vowel." << '\n';
        }

    }

    return vowelCount;
}
// function to check if all letters in the alphabet appears in the string
bool isPangram(const std::string& text) {
    bool pangram {true};
    std::array<int, 26> counter {};
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (auto& chr : text) {
        if (!std::isalpha(chr)) {
            continue;
        }
        char cLower = static_cast<char>(std::tolower(chr));
        size_t loc = alphabet.find(cLower);
        if (loc != std::string::npos) {
            counter[loc] = 1;
        }
        
    }
    for (int arr : counter) {
        if (arr == 0) {
            pangram = false;
            break;
        }
    }
    return pangram;
}