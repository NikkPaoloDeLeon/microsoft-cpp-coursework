#include <iostream>
#include <array>
#include <random>
#include <ctime>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>   
#include <numeric>

// Forward declaration for random number generation
int generateRandomNumber();
int validateIntegerInput(const std::string& prompt);
int searchCArray(int data[],  int number);
int searchSTDArray(const std::array<int, 20>& data, int number);
double getMeanC_Style(int data[]);
double getMeanSTD(const std::array<int, 20>& data);
double getMedianC_Stlye(int data[], int size);
double getMedianSTD(const std::array<int, 20>& data, int size);
double getModeC_Style(int data[], int size);
double getModeSTD(const std::array<int, 20>& data);

int main() {
    // Seed random number based on system time
    std::srand(static_cast<unsigned>(std::time(0)));
    // Declare arracy using C-style
    int c_style_numbers[20] = {};
    // Declare array using std::array
    std::array<int, 20> std_array_numbers {};
    
    std::cout << "Populating C-style array... " << '\n';
    // Populate the C-style array
    for (int i {}; i < 20; i++) {
        c_style_numbers[i] = generateRandomNumber();
    }
    std::cout << "C-style array has been populated... " << '\n';

    std::cout << "Populating std::array... " << '\n';
    for (int i {0}; i < static_cast<int>(std::size(std_array_numbers)); i++) {
        std_array_numbers[i] = generateRandomNumber();
    }
    // Display the two populated table (not sorted)
    std::cout << std::string(5, '=') << " DATA COMPARISON TABLE " << std::string(5, '=') << '\n';
    std::cout << std::left << std::setw(15) << "C-STYLE" << std::right << std::setw(15) << "STD::ARRAY" << '\n';
    for (int i {0}; i < 20; i++) {
         std::cout << std::left << std::setw(15) <<c_style_numbers[i] << std::right << std::setw(15) << std_array_numbers[i] << '\n';
    }

    int sorted_c_style_numbers[20];
    for (int i {0}; i < 20; i++) {
        sorted_c_style_numbers[i] = c_style_numbers[i];
    }

    // Implement bubble sort in C-style array
    for (int i {0}; i < (20-1); i++) {
        bool swapped {false};
        for (int j {0}; j < 20-i-1; j++) {
            if (sorted_c_style_numbers[j] > sorted_c_style_numbers[j+1]) {
                int temp = sorted_c_style_numbers[j];
                sorted_c_style_numbers[j] = sorted_c_style_numbers[j+1];
                sorted_c_style_numbers[j+1] = temp; 
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    std::array<int, 20> sorted_std_array_numbers = std_array_numbers;
    // Sort the std array using std sort in ascending order
    std::sort(sorted_std_array_numbers.begin(), sorted_std_array_numbers.end());

    // Display the two populated table (with sorted column)
    // Display the two populated tables (with sorted columns)
    std::cout << std::string(5, '=') << " DATA COMPARISON TABLE WITH SORTED " << std::string(5, '=') << '\n';

    // HEADERS: Uniform width and alignment (using left alignment for all makes it easy to read)
    std::cout << std::left << std::setw(25) << "C-STYLE NOT SORTED" 
        << std::left << std::setw(25) << "C-STYLE SORTED" 
        << std::left << std::setw(25) << "STD::ARRAY NOT SORTED" 
        << std::left << std::setw(25) << "STD::ARRAY SORTED" << '\n';

    // SEPARATOR LINE
    std::cout << std::string(100, '-') << '\n';

    // DATA ROWS: Exact same alignments and widths as the headers
    for (int i {0}; i < 20; i++) {
    std::cout << std::left << std::setw(25) << c_style_numbers[i] 
        << std::left << std::setw(25) << sorted_c_style_numbers[i] 
        << std::left << std::setw(25) << std_array_numbers[i] 
        << std::left << std::setw(25) << sorted_std_array_numbers[i] << '\n';
    }


    int findNumber {0};
    findNumber = validateIntegerInput("Please enter a valid Integer number: ");
    int numberLocation = searchCArray(sorted_c_style_numbers, findNumber);
    if (numberLocation == 1) {
        std::cout << "Number does not exist in the sorted_c_style_numbers array!" << '\n';
    } else {
        std::cout << "Number " << findNumber << " exists in the sorted_c_style_numbers array. Found in " << numberLocation + 1 << " readings." << '\n';
        std::cout << "Located at index: " << numberLocation << '\n'; 
    }

    int numberLocationForSTDArray = searchSTDArray(sorted_std_array_numbers, findNumber);
        if (numberLocationForSTDArray == 1) {
        std::cout << "Number does not exist in the sorted_c_style_numbers array!" << '\n';
    } else {
        std::cout << "Number " << findNumber << " exists in the sorted_c_style_numbers array. Found in " << numberLocationForSTDArray + 1 << " readings." << '\n';
        std::cout << "Located at index: " << numberLocationForSTDArray << '\n'; 
    }
    

    // Display the mean using the manual method for the C-stlye and accumulate for the std::array
    double meanC_Style {0.0};
    double meanSTD {0.0};
    std::cout << std::string(100, '=') << '\n';
    std::cout << std::string(40, ' ') << " STATISTICAL ANALYSIS " << '\n';
    std::cout << std::string(100, '=') << '\n';
    // Get mean 
    meanC_Style = getMeanC_Style(c_style_numbers);
    meanSTD = getMeanSTD(std_array_numbers);
    // Display the mean
    std::cout << std::left << std::setw(25) << "Measures" 
        << std::left << std::setw(25) << "C-STYLE ARRAY" <<
        std::left << std::setw(25) << "STD::ARRAY ARRAY" << '\n';
    std::cout << std::left << std::setw(25) << "Mean" 
        << std::left << std::setw(25) << meanC_Style <<
        std::left << std::setw(25) << meanSTD << '\n';

    // Get median
    double medianC_Style {0.0};
    double medianSTD {0.0};
    int sortedSizeC_Style = static_cast<int>(sizeof(sorted_c_style_numbers));
    medianC_Style = getMedianC_Stlye(sorted_c_style_numbers, sortedSizeC_Style);
    medianSTD = getMedianSTD(sorted_std_array_numbers, 20);
    // Display median of the two arrays
    std::cout << std::left << std::setw(25) << "Median" 
        << std::left << std::setw(25) << medianC_Style <<
        std::left << std::setw(25) << medianSTD << '\n';
    
    // Get mode 
    double modeC_Style {0.0};
    double modeSTD {0.0};

    modeC_Style = getModeC_Style(sorted_c_style_numbers, sortedSizeC_Style);
    modeSTD = getModeSTD(sorted_std_array_numbers);
    // Display mode of the two arrays
    std::cout << std::left << std::setw(25) << "Mode" 
        << std::left << std::setw(25) << modeC_Style <<
        std::left << std::setw(25) << modeSTD << '\n';

    return 0; 
}

 // Find for the mean using the manual type for soreted_c_style_numbers array
double getMeanC_Style(int data[]) {
    double sum {0};
    int size = 20;
    for (int i {0}; i < size; i++) {
        sum += data[i];
    }
    return sum / static_cast<double>(size);
}
 // Find for the mean using std::accumulate for sorted_std_array_numbers array
double getMeanSTD(const std::array<int, 20>& data) {
    double sum {0.0}, mean {0.0};
    if (data.empty()) {
        std::cout << "Array has no elements! Cannot perform function." << '\n';
    }
    sum = std::accumulate(data.begin(), data.end(), 0);
    mean = sum / static_cast<double>(std::size(data));
    return mean ;
} 

// Find the median for C-style array
double getMedianC_Stlye(int data[], int size) {
    double median {0.0};
    for (int i {0}; i < size; i++) {
        if (size % 2 == 0 && i == size / 2) {
            median = (data[i-1] + data[i]) / 2;
        } else if (size % 2 == 1 && i == (size / 2)) {
            median = data[i];
        }
    }  
    return median;
}

double getMedianSTD(const std::array<int, 20>& data, int size) {
    double median {0.0};
    if (data.empty()) {
        std::cout << "Array has no elements! Cannot perform function." << '\n';
    }
    for (int i {0}; i < size; i++) {
        if (size % 2 == 0 && i == size/2) {
             median = (data[i-1] + data[i]) / 2;
        } else if (size % 2 != 0 && i == (size / 2)) {
            median = data[i];
        }
    }

    return median;

}

double getModeC_Style(int data[], int size) {
    int mode = data[0];
    int count = {1};
    int maxCount {1};
    for (int i {0}; i < size-i-1; i++) {
        if (data[i] == data[i+1]) {
            count += 1;
        } else {
            count = 1;
        }

        if (count > maxCount) {
            maxCount = count;
            mode = data[i];
        }
    }
    return mode;
}
double getModeSTD(const std::array<int, 20>& data) {
    int mode = data[0];
    int count = {1};
    int maxCount {1};
    for (int i {0}; i < static_cast<int>(std::size(data)) - 1; i++) {
        if (data[i] == data[i+1]) {
            count += 1;
        } else {
            count = 1;
        }

        if (count > maxCount) {
            maxCount = count;
            mode = data[i];
        }
    }
    return mode;
}
// Ask the user for a value that would be used to search the arrays for c-style
int searchSTDArray(const std::array<int, 20>& data, int number) {
    int numberLocation {0};
    for (int i {0}; i < 20; i++) {
        if (number == data[i]) {
            return numberLocation = i;
        }
    }
    return 1;
}

// Ask the user for a value that would be used to search the arrays for c-style
int searchCArray(int data[], int number) {
    int numberLocation {0};
    for (int i {0}; i < 20; i++) {
        if (number == data[i]) {
            return numberLocation = i;
        }
    }
    return 1;
}

// Funtion returns a random generated number based on system time seed
int generateRandomNumber() {
    return (std::rand() % 100) + 1;
}

// Function to validate input if it is an integer
int validateIntegerInput(const std::string& prompt) {
    bool validInput {false};
    int validInteger {0};
    do {
        std::cout << prompt;
        std::cin >> validInteger;
        if (std::cin.fail() || validInteger > std::numeric_limits<int>::max() - validInteger) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max());
            std::cout << "Invalid input!" << '\n';
            continue;
        }
        validInput = true;
    } while(!validInput);
    return validInteger;
}