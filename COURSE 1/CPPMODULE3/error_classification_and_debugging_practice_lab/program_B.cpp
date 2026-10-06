#include <iostream>

int main() {
    int temperature;
    std::cout << "Enter temperature in Celsius: ";
    std::cin >> temperature;
    int fahrenheit = (temperature * 9 / 5) + 32;
    std::cout << temperature << "C = " << fahrenheit << "F " << '\n';
    return 0;
}