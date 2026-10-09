#include <iostream>
#include <string>

int main() {
    std::string monthString, dayString, yearString;
    //std::string date {"June/12/1999"};
    std::string date {"January/1/1999"};
    size_t month = date.find("/");
    std::cout << "monthPos = " << month << '\n';
    if (month != std::string::npos) {
        monthString = date.substr(0, month);
    }
    std::cout << monthString << '\n';
    size_t day = date.find("/", month+1);
    std::cout << "dayPos = " << day << '\n';
    if (day != std::string::npos) {
        dayString = date.substr(month+1, (day-1)-month);
    }
    std::cout << dayString << '\n';

    yearString = date.substr(day+1);

    std::cout << yearString;

    return 0;
}
