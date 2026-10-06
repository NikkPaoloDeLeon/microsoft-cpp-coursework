#include <iostream>
#include <array>

int main() {
    // C style array implementation
    int c_temps[10] = {72, 75, 68, 80, 77, 73, 69, 82, 78, 76};
    // C++ style/std array implementation 
    std::array<int, 10> std_temps {72, 75, 68, 80, 77, 73, 69, 82, 78, 76};
    std::cout << "Temperature data loaded successfully!" << '\n';

    // Access the 5th, 7th, and 10th temperature readings
    std::cout << "5th reading - C-style: " << c_temps[4] << '\n';
    std::cout << "5th reading - std::array: " << std_temps[4] << '\n';
    std::cout << "6th reading - C-style: " << c_temps[6] << '\n';
    std::cout << "6th reading - std::array: " << std_temps[6] << '\n';
    std::cout << "10th reading - C-style: " << c_temps[9] << '\n';
    std::cout << "10th reading - std::array: " << std_temps[9] << '\n';
    // Modify 3rd reading to 85 degrees
    c_temps[2] = 85;
    std_temps[2] = 85;
    c_temps[7] = 90;
    std_temps[7] = 90;
    // Display all temperatures to confirm modifications
    std::cout << "========================================================" << '\n';
    std::cout << "C-style temperatures: " << '\n';
    for (int i {0}; i < 10; i++) {
        std::cout << "Reading " << i + 1 << " temperature: " << c_temps[i] << '\n';
    }
    std::cout << '\n';
    std::cout << "std::array temperatures: " << '\n';
    for (int i {0}; i < std::size(std_temps); i++) {
         std::cout << "Reading " << i + 1 << " temperature: " << std_temps[i] << '\n';
    }


    std::cout << "Test out-of-bounds:" << '\n';
    std::cout << "C-style[10]" << c_temps[10] << "(unsafe!)" << '\n';
    try {
        std::cout << "std::array.at(10): " << std_temps.at(10) << '\n';
    } catch (const std::out_of_range& e) {
        std::cout << "Exception caught: " << e.what() << '\n';
    }
    return 0;
}