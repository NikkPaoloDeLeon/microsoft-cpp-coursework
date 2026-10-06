/// Include header files and header guards
#include <iostream>

/// library for structure and organization of outputs
#include <iomanip>
#include <string>

/// Use forward declaration for functions so that even I put it after the main function it can still be known by the compiler
void programHeader();
void programConversionBody();
void displayTemperatureFacts(double celcius);
double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);
double celsiusToKelvin(double celsius);
double kelvinToCelsius(double kelvin);
double fahrenheitToKelvin(double fahrenheit);
double kelvinToFahrenheit(double kelvin);


/// Global variables for the different conversion factors that are set as constants 
const double FREEZING_POINT_C {0.0};
const double FREEZING_POINT_F {32.0};
const double ABSOLUTE_ZERO_C {-273.15};
/// This formua is C = (F -32) * (quotient of 5/9)
const double F_TO_C_FACTOR {5.0/9.0};
/// This formula is F = C * (quotient of 9/5) + 32
const double C_TO_F_FACTOR {9.0/5.0};

/// Create the main function as the start up of the program
int main() {
    /// Call programHeader function
    programHeader();
    /// Call the main body of the program
    programConversionBody();

    return 0;
}
/// This function prints the header for the program
void programHeader(){
    std::cout << std::string(70, '=') << '\n';
    std::cout << std::string(30, ' ') << "TEMPERATURE CONVERTER" << std::string(30, ' ') << '\n';
    std::cout << std::string(70, '=') << '\n';
    std::cout << "This program converts temperature between" << '\n';
    std::cout << "Celsius, Fahrenheit, Kelvin" << '\n';
    std::cout << std::string(70, '-') << '\n';
}

/// This function prints the main conversion table
void programConversionBody() {
    bool keepRunning {true};

    while (keepRunning)
    {
        /// Display the menu options
        std::cout << "Temperature Conversion Options: " << '\n';
        std::cout << "1. Celsius to Fahrenheit" << '\n';
        std::cout << "2. Fahrenheit to Cesius" << '\n';
        std::cout << "3. Celsius to Kelvin" << '\n';
        std::cout << "4. Kelvin to Celsius" << '\n';
        std::cout << "5. Fahrenheit to Kelvin" << '\n';
        std::cout << "6. Kelvin to Fahrenheit" << '\n';
        std::cout << "7. Exit Program" << '\n';

        /// Ask for user choice for what type of conversion
        std::cout << '\n' << "Enter your choice (1-7)" << '\n';
        char choice {};
        std::cin >> choice;

        /// Variable for temperature input and result
        double inputTemp, result;
        switch (choice)
        {
        case '1': // Celsius to Fahrenheit
            std::cout << "Enter Temperature in Celsius" << '\n';
            std::cin >> inputTemp;
            result = celsiusToFahrenheit(inputTemp);
            while (result == false) {
                std::cout << "Temperature should be above Absolute zero(-273.15)" << '\n';
                std::cout << "Enter Temperature in Celsius" << '\n';
                std::cin >> inputTemp;
                result = celsiusToFahrenheit(inputTemp);
            }
            std::cout << std::fixed << std::setprecision(2);
            std::cout << std::string(70, '=') << '\n';
            std::cout << std::string(30, ' ') << "Conversion" << std::string(30, ' ') << '\n';
            std::cout << std::string(70, '=') << '\n';
            std::cout << std::left << std::setw(40) << "Temperature in Celsius (°C)" << std::right << std::setw(30) << "Temperature in Fahrenheit (°F)" << '\n';
            std::cout << std::left << std::setw(40) << inputTemp << std::right << std::setw(30) << result << '\n';
            displayTemperatureFacts(inputTemp);
            break;
        case '2': // Fahrenheit to Celsius
            std::cout << "Enter Temperature in Farenheit" << '\n';
            std::cin >> inputTemp;
            result = fahrenheitToCelsius(inputTemp);
            while (result == false) {
                std::cout << "Temperature cannot be below -459.67" << '\n';
                std::cout << "Enter Temperature in Fahrenheit" << '\n';
                std::cin >> inputTemp;
                result = fahrenheitToCelsius(result);
            }
            std::cout << std::fixed << std::setprecision(2);
            std::cout << std::string(70, '=') << '\n';
            std::cout << std::string(30, ' ') << "Conversion" << std::string(30, ' ') << '\n';
            std::cout << std::string(70, '=') << '\n';
            std::cout << std::left << std::setw(40) << "Temperature in Fahrenheit F" << std::right << std::setw(30) << "Temperature in Celsius C" << '\n';
            std::cout << std::left << std::setw(40) << inputTemp << std::right << std::setw(30) << result << '\n';
            displayTemperatureFacts(inputTemp);
            break;
        case '3': // Celsius to Kelvin
            std::cout << "Enter Temperature in Celsius" << '\n';
            std::cin >> inputTemp;
            result = celsiusToKelvin(inputTemp);
            while (result == false) {
                std::cout << "Temperature should be above Absolute zero(-273.15)" << '\n';
                std::cout << "Enter Temperature in Celsius" << '\n';
                std::cin >> inputTemp;
                result = celsiusToKelvin(inputTemp);
            }
            std::cout << std::fixed << std::setprecision(2);
            std::cout << std::string(70, '=') << '\n';
            std::cout << std::string(30, ' ') << "Conversion" << std::string(30, ' ') << '\n';
            std::cout << std::string(70, '=') << '\n';
            std::cout << std::left << std::setw(40) << "Temperature in Celsius (C)" << std::right << std::setw(30) << "Temperature in Kelvin (K)" << '\n';
            std::cout << std::left << std::setw(40) << inputTemp << std::right << std::setw(30) << result << '\n';
            displayTemperatureFacts(inputTemp);
            break;
        case '4': // Kelvin to Celsius
            std::cout << "Enter Temperature in Kelvin" << '\n';
            std::cin >> inputTemp;
            result = kelvinToCelsius(inputTemp);
            while (result == false) {
                std::cout << "Temperature should be above 0" << '\n';
                std::cout << "Enter Temperature in Kelvin" << '\n';
                std::cin >> inputTemp;
                result = kelvinToCelsius(inputTemp);
            }
            std::cout << std::fixed << std::setprecision(2);
            std::cout << std::string(70, '=') << '\n';
            std::cout << std::string(30, ' ') << "Conversion" << std::string(30, ' ') << '\n';
            std::cout << std::string(70, '=') << '\n';
            std::cout << std::left << std::setw(40) << "Temperature in Kelvin (K)" << std::right << std::setw(30) << "Temperature in Celsius (C)" << '\n';
            std::cout << std::left << std::setw(40) << inputTemp << std::right << std::setw(30) << result << '\n';
            displayTemperatureFacts(result);
            break;
        case '5': // Fahrenheit to Kelvin
            std::cout << "Enter Temperature in Fahrenheit" << '\n';
            std::cin >> inputTemp;
            result = fahrenheitToKelvin(inputTemp);
            while (result == false) {
                std::cout << "Temperature cannot be below -459.67" << '\n';
                std::cout << "Enter Temperature in Fahrenheit" << '\n';
                std::cin >> inputTemp;
                result = fahrenheitToKelvin(inputTemp);
            }
            std::cout << std::fixed << std::setprecision(2);
            std::cout << std::string(70, '=') << '\n';
            std::cout << std::string(30, ' ') << "Conversion" << std::string(30, ' ') << '\n';
            std::cout << std::string(70, '=') << '\n';
            std::cout << std::left << std::setw(40) << "Temperature in Fahrenheit F" << std::right << std::setw(30) << "Temperature in Kelvin (K)" << '\n';
            std::cout << std::left << std::setw(40) << inputTemp << std::right << std::setw(30) << result << '\n';
            displayTemperatureFacts(result);
            break;
        case '6': // Kelvin to Fahrenheit
            std::cout << "Input Temperature in Kelvin" << '\n';
            std::cin >> inputTemp;
            result = kelvinToFahrenheit(inputTemp);
            while (result == false) {
                std::cout << "Temperature should be above 0" << '\n';
                std::cout << "Enter Temperature in Kelvin" << '\n';
                std::cin >> inputTemp;
                result = kelvinToFahrenheit(inputTemp);
            }
            std::cout << std::fixed << std::setprecision(2);
            std::cout << std::string(70, '=') << '\n';
            std::cout << std::string(30, ' ') << "Conversion" << std::string(30, ' ') << '\n';
            std::cout << std::string(70, '=') << '\n';
            std::cout << std::left << std::setw(40) << "Temperature in Kelvin (K)" << std::right << std::setw(30) << "Temperature in Fahrenheit F" << '\n';
            std::cout << std::left << std::setw(40) << inputTemp << std::right << std::setw(30) << result << '\n';
            displayTemperatureFacts(result);
            break;
        case '7':
            keepRunning = false;
            std::cout << "Thank you for using the program!" << std::endl;
            break;
        default:
            std::cout << "INVALID CHOICE! PLEASES SELECT FROM NUMBERS 1 TO 7 ONLY!" << '\n';
            break;
        }


    }
    
    
}

void displayTemperatureFacts (double celsius) {
    std::cout << "\nInteresting facts about this temperature:" << '\n';

    if (celsius < ABSOLUTE_ZERO_C) {
        std::cout << "This temperature is below absolute zero, which is physically impossible!" << '\n';
    }else if (celsius == ABSOLUTE_ZERO_C) {
        std::cout << "This is absolute zero, the lowest possible temperature in the universe!" <<'\n';
    }else if (celsius < FREEZING_POINT_C) {
        std::cout << "This temperature is below the freezing point of water." << '\n';
    }else if (celsius == FREEZING_POINT_C) {
        std::cout << "This is the freezing point of water at standard pressure." << '\n';
    }else if (celsius < 20.00) {
        std::cout << "This is a cool temperature." << '\n';
    }else if (celsius <= 30.0) {
        std::cout << "This is a comfortable room temperature." <<'\n';
    }else if (celsius <= 40.00) {
        std::cout << "This is a hot temperature." << '\n';
    }else if (celsius <= 100.00) {
        std::cout <<  "This is a very hot temperature." << '\n';
    }else if (celsius == 100.00) {
        std::cout << "This is the boiling point of water at standard pressure." << '\n';
    }else {
        std::cout << "This is above the boiling point of water." << '\n';
    }
}


/// Function to convert a given celsius value to farenheit
double celsiusToFahrenheit(double celsius) {
    // Validate temperature inputs
    if (celsius < ABSOLUTE_ZERO_C) {
        return false;
    }
    double fahrenheit {celsius*C_TO_F_FACTOR + 32};
    return fahrenheit;
}

/// Function to convert a given farenheit to celsius
double fahrenheitToCelsius(double fahrenheit) {
    // Validate temperature inputs
    if (fahrenheit < -459.67) {
        return false;
    }
    double celsius {(fahrenheit - 32) * F_TO_C_FACTOR};
    return celsius;
}

/// Function to convert celsius to kelvin
double celsiusToKelvin(double celsius) {
    // Validate temperature inputs
    if (celsius < ABSOLUTE_ZERO_C) {
        return false;   
    }
    return celsius - ABSOLUTE_ZERO_C;
}

/// Function to convert kelvin to celsius
double kelvinToCelsius(double kelvin) {
    // Validate temperature inputs
    if (kelvin < 0) {
        return false;
    }
    return kelvin + ABSOLUTE_ZERO_C;
}

/// Function to convert farenheit to kelvin
double fahrenheitToKelvin(double fahrenheit) {
    // Validate temperature inputs
    if (fahrenheit < -459.67) {
        return false;
    }
    /// Convert the given farenheit first to celsius
    double celsius {fahrenheitToCelsius(fahrenheit)};
    return celsiusToKelvin(celsius);
}

/// Function to convert kelvin to farenheit
double kelvinToFahrenheit(double kelvin) {
    // Validate temperature inputs
    if (kelvin < 0) {
        return false;
    }
    /// Convert first to celsius, then to farenheit
    double celsius {kelvinToCelsius(kelvin)};
    return celsiusToKelvin(celsius);
}

