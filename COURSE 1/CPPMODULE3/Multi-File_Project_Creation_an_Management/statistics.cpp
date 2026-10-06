// Include header file
#include "statistics.h"

double average(const std::vector<double>& numbers, std::size_t vectorSize) {
    double sum {0.0};
    for (double number : numbers) {
        sum += number;
    }
    return sum / static_cast<double>(vectorSize);
}

double minimum(const std::vector<double>& numbers) {
    double value {std::numeric_limits<double>::max()};
    for (double number : numbers) {
        if (number <= value) {
            value = number;
        }
    }
    return value;
}

double maximum(const std::vector<double>& numbers) {
    double value {std::numeric_limits<double>::min()};
    std::size_t length = numbers.size();
    for (std::size_t i = 0; i < length; i++) {
        if (numbers[i] >= value) {
            value = numbers[i];
        }
    }
    return value;
}