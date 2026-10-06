/// Declare the header files or libraries that would be used
/// iostream is for the input and outputstreams which will be displayed and inputed in the console
#include <iostream>
#include <vector>

/// Declare the main function which is the start
int main() {
    /// Declare the vector vairalbe
    std::vector<int> vec {1, 1, 1, 1, 1};
    /// Declare variable for health
    float playerHealth;
    std::vector<int>::iterator example = vec.begin();
    std::cout << *example;

    return 0;
}