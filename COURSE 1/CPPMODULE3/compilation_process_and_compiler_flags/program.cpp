/*
#include <iostream>

int main() {
    int number;
    int result {number * 2};
    int unused_var {42};
    std::cout << "Enter a number: ";
    std::cin >> number;
    if (number == 5) {
        std::cout << "You entered five" << '\n';

    }
    std::cout << "Result: " << result << '\n';
    return 0;

}
*/

/*
#include <iostream>
#include <cmath>

#define SQUARE(x) ((x) * (x))

int main() {
    double radius {5.0};
    double area {3.14159 * SQUARE(radius)};
    std::cout << "Area of circle: " << area << '\n';
    std::cout << "Square Root: " << sqrt(area) << '\n';
    return 0;
}
*/

#include <iostream>
#include <chrono>

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci( n-1 ) + fibonacci(n - 2);
}

int fibonacci_iterative(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, result; 
    for (int i = 2; i <= n; i++) {
        result = a + b;
        a = b; 
        b = result;
    }
    return result;
}

int main() {
    int n {35};
    auto start = std::chrono::high_resolution_clock::now();
    int result {fibonacci_iterative(n)};
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    std::cout << "Fibonacci(" << n << ") = " << result <<'\n';
    std::cout << "Execution time: " << duration.count() << "ms" << '\n';
}
