// Inlcude the header files of the functions that would be used
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <format>
#include <optional>
#include <charconv>
#include <array>
#include <map>
#include <cctype>
#include <unordered_map>
#include <string_view>
// Forward declarations
std::optional<int> GetAge(const std::string& prompt);
std::optional<int> ValidateInteger(const std::string input);
std::optional<std::array<std::string, 3>> GetFullName();
std::optional<std::string> ValidateNameString(const std::string input, const std::string part);
std::optional<std::string> ValidateEmailString(const std::string& input);
std::optional<std::string> GetEmail(const std::string& prompt);
std::optional<std::string> ValidateBirthday(const std::string& input, const int part);
std::optional<std::array<std::string, 3>> GetBirthday(const std::string& prompt);
void DisplayUserData();

// The start of the program
int main() {
    DisplayUserData();
    return 0;

}

void DisplayUserData() {
    std::array<std::string, 3> fullname = GetFullName().value_or(std::array<std::string, 3> {"", "", ""});
    std::array<std::string, 3> birthday = GetBirthday("Please Enter your birthday: ").value_or(std::array<std::string, 3> {"", "", ""});
    int age = GetAge("Please enter your age: ").value_or(0);
    std::string email = GetEmail("Please enter your email address: ").value_or(std::string(""));
    std::string birthdayString = birthday.at(0) + ' ' + birthday.at(1) + ", " + birthday.at(2);
    std::string fullnameString = fullname.at(0) + ' ' + fullname.at(1) + ' ' + fullname.at(2);
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::string(110, '=') << '\n';
    std::cout << std::setw(60) << " USER DATA " << '\n';
    std::cout << std::string(110, '=') << '\n';
    std::cout << std::setw(30) << "Fullname" << std::setw(30) << "Birthday" << std::setw(20)
        << "Age" << std::setw(30) << "Email" << '\n';
    std::cout << std::string(110, '-') << '\n';
    std::cout << std::setw(30) << fullnameString
        << std::setw(30) << birthdayString << std::setw(20)
        << age << std::setw(30) << email << '\n';
}

std::optional<int> GetAge(const std::string& prompt) {
    std::string input;
    int age {0};
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, input)) {
            std::cerr << "FATAL STREAM ERROR" << '\n';
            return std::nullopt;
        }
        auto ageString = ValidateInteger(input);
        if (!ageString) {
            continue;
        }
        if (ageString < 0 || ageString > 120) {
            std::cout << "Invalid Age! " << '\n';
            continue;
        }
        age = *ageString;
        break;
    }
    return age;

}
std::optional<std::array<std::string, 3>> GetFullName() {
    std::string input;
    std::string firstName, middleName, lastName;

    while (true) {
        std::string part;
        std::cout << "Please Enter your first name: ";
        if (!std::getline(std::cin, input)) {
            std::cerr << "FATAL STREAM ERROR!" << 'n';
            return std::nullopt;
        }
        part = "First";
        auto validateName = ValidateNameString(input, part);
        if (!validateName.has_value()) {
            continue;
        }
        firstName = *validateName;
        break;
    }
    input.clear();

    while (true) {
        std::string part;
        std::cout << "Please Enter your middle name: ";
        if (!std::getline(std::cin, input)) {
            std::cerr << "FATAL STREAM ERROR!" << 'n';
            return std::nullopt;
        }
        part = "Middle";
        auto validateName = ValidateNameString(input, part);

        if (!validateName.has_value()) {
            continue;
        }
        middleName = *validateName;
        break;
    }
    input.clear();

    while (true) {
        std::string part;
        std::cout << "Please Enter your last name: ";
        if (!std::getline(std::cin, input)) {
            std::cerr << "FATAL STREAM ERROR!" << 'n';
            return std::nullopt;
        }
        part = "Middle";
        auto validateName = ValidateNameString(input, part);

        if (!validateName.has_value()) {
            continue;
        }
        lastName = *validateName;
        break;
    }
    
    input.clear();
    return std::array<std::string, 3> {firstName, middleName, lastName};
}

std::optional<std::string> GetEmail(const std::string& prompt) {
    std::string email, input;
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin,input)) {
            std::cerr << "FATAL STREAM ERROR." << '\n';
        }
        auto validateEmail = ValidateEmailString(input);
        if (!validateEmail) {
            std::cerr << "Please check your email." << '\n';
            continue;
        }
        email = *validateEmail;
        break;
    }
    return email;
}

std::optional<std::string> ValidateEmailString(const std::string& input) {
    std::cout << "Debugger: " << input << '\n';
    if (input.empty()) {
        std::cerr << "Email Cannot be Empty." << '\n';
        return std::nullopt;
    }
    if (input.find_first_not_of(" \t") ==  std::string::npos) {
        std::cerr << "Email cannot be spaces only." << '\n';
        return std::nullopt;
    }

    if (input.find("  ") != std::string::npos) {
        std::cerr << "Email cannot contain 2 consecutive space." << '\n';
        return std::nullopt;
    }

    bool isValidSet = std::all_of(input.begin(), input.end(), [](unsigned char c) {
        return isalnum(c) || c == '@' || c == '.';
    });
    if (!isValidSet) {
        std::cerr << "Invalid email format." << '\n';
        return std::nullopt;
    }

    size_t tagPos = input.find("@gmail.com");
    size_t tagPos2 = input.find("@yahoo.com");
    if (tagPos == std::string::npos && tagPos2 == std::string::npos) {
        std::cerr << "Email format should end with @gmail.com or @yahoo.com." << '\n';
        return std::nullopt;
    }
    return input;
}

std::optional<std::string> ValidateNameString(const std::string input, const std::string part) {
    if (input.empty()) {
        std::cerr << part << " name cannot be empty." << '\n';
        return std::nullopt;
    }

    if (input.find_first_not_of(" \t") == std::string::npos) {
        std::cerr << part << " name cannot only be spaces." << '\n';
        return std::nullopt;
    }

    if (input.find("  ") != std::string::npos) {
        std::cerr << part << " name cannot have two consecutive spaces." << '\n';
        return std::nullopt;
    }

    bool isValidSet = std::all_of(input.begin(), input.end(), [](unsigned char c) {
        return std::isalpha(c) || std::isspace(c) || c == '-' || c == '.';
    });

    if (!isValidSet) {
        std::cerr << part << " name can only contain letters, -, and spaces." << '\n';
        return std::nullopt;
    }
    return input;
}

std::optional<int> ValidateInteger(const std::string input) {
    int value {0};
    //std::cout << "Debugger: " << input << '\n';
    auto [pointer, errorC] = std::from_chars(input.data(), input.data() + input.size(), value);
    if (pointer != input.data() + input.size()) {
        std::cerr << "Logical Error: Please input numbers only." << '\n';
        return std::nullopt;
    }
    if (errorC == std::errc::invalid_argument) {
        std::cerr << "Type Error: Please input a valid integer." << '\n';
        return std::nullopt;
    }
    if (errorC == std::errc::result_out_of_range) {
        std::cerr << "Overflow: You have exceeded the maximum value." << '\n';
        return std::nullopt;
    }
    return value;
}
std::optional<std::array<std::string, 3>> GetBirthday(const std::string& prompt) {
    std::string month, day, year, input;
    const std::unordered_map<std::string_view, int> month_days = {
        {"january", 31}, {"february", 28}, {"march", 31},
        {"april", 30},   {"may", 31},      {"june", 30},
        {"july", 31},    {"august", 31},   {"september", 30},
        {"october", 31}, {"november", 30}, {"december", 31}
    };
    while (true) { 
        std::cout << prompt;
        if (!std::getline(std::cin, input)) {
            std::cerr << "FATAL STREAM ERROR!" << '\n';
            return std::nullopt;
        }
        size_t monthPos = input.find("/");
        size_t dayPos = input.find("/", monthPos+1);
        std::string monthString = input.substr(0, monthPos);
        std::string dayString = input.substr(monthPos+1, (dayPos-1)-monthPos);
        std::string yearString = input.substr(dayPos+1);

        if (!(month_days.contains(monthString))) {
            std::cerr << "Please input a valid month." << '\n';
            continue;
        }
        auto validatedMonth = ValidateBirthday(monthString, 1);
        month = *validatedMonth;
        if (!(month_days.at(month) >= std::stoi(dayString))) {
            std::cerr << "Please input a valid day." << '\n';
            continue;
        }
        auto validatedDay = ValidateBirthday(dayString, 2);
        if (!validatedDay) {
            std::cerr << "Please input a valid day." << '\n';
            continue;
        }
        day = *validatedDay;

        auto validatedYear = ValidateBirthday(yearString, 3);
        if (!validatedYear) {
            std::cerr << "Please input a valid year." << '\n';
            continue;
        }
        year = *validatedYear;
        break;
    }

    return std::array<std::string, 3> {month, day, year};
}
    


std::optional<std::string> ValidateBirthday(const std::string& input, const int part) {
    std::string month, stringDay, stringYear;
    int day, year;
    switch (part) {
    case 1: {

        if (input.empty()) {
            std::cerr << "Month cannot be empty." << '\n';
            return std::nullopt;
        }  
        if (input.find_first_not_of(" \t") == std::string::npos) {
            std::cerr << "Month cannot be just spaces." << '\n';
            return std::nullopt;
        }  
        if (input.find(" ") != std::string::npos) {
            std::cerr << "Month cannot contain spaces" << '\n';
        }
        bool isValidSet = std::all_of(input.begin(), input.end(), [](unsigned char c) {
            return isalpha(c);
        });
        if (!isValidSet) {
            std::cerr << "Invalid month!" << '\n';
        }
        month = input;
        return month;
        }
    case 2: {
        if (input.empty()) {
            std::cerr << "Day cannot be empty." << '\n';
            return std::nullopt;
        }
        auto [pointer, errorC] = std::from_chars(input.data(), input.data() + input.size(), day);
        if (pointer != input.data() + input.size()) {
            std::cerr << "Day should only contain numbers." << '\n';
            return std::nullopt;
        }
        if (errorC == std::errc::invalid_argument) {
            std::cerr << "Day cannot be letters." << '\n';
            return std::nullopt;
        }
        if (errorC == std::errc::result_out_of_range) {
            std::cerr << "Input exceeded the maximum number." << '\n';
            return std::nullopt;
        }
        if (day < 0 || day > 31) {
            std::cerr << "Invalid day." << '\n';
            return std::nullopt;
        }
        stringDay = std::to_string(day);
        return stringDay;
        }
        break;
    case 3: {
        if (input.empty()) {
            std::cerr << "Day cannot be empty." << '\n';
            return std::nullopt;
        }
        auto [pointer, errorC] = std::from_chars(input.data(), input.data() + input.size(), year);
        if (pointer != input.data() + input.size()) {
            std::cerr << "Day should only contain numbers." << '\n';
            return std::nullopt;
        }
        if (errorC == std::errc::invalid_argument) {
            std::cerr << "Day cannot be letters." << '\n';
            return std::nullopt;
        }
        if (errorC == std::errc::result_out_of_range) {
            std::cerr << "Input exceeded the maximum number." << '\n';
            return std::nullopt;
        }
        if (year < 1900 || year > 2026) {
            std::cerr << "Invalid year." << '\n';
            return std::nullopt;
        }
        stringYear = std::to_string(year);
        return stringYear;
        }
    default:
        break;
    }
    return std::nullopt;
}
