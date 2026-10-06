/// Lab activity to 
/*
* check for spacing, 
* inconsistent or missing indention
* Poor variables and class names
* Missing comments explaining the code's prupose
* Inconsistent brace placement
*/

// There should be a space here in the header file
#include <iostream>
using namespace std;

// Name for class could be better
class CalculateNumber {
    // This varibale can be accessed by the public without setters or getters
    public:
        // This should be indented and have space
        // Shoul be a better variable names
        int number1, number2;

    void addition(){
        // Should be both on seperate lines for the statement
        // Better variable names 
        number1 = 10; 
        number2 = 20;
        // Name for the variable result variable can be better
        // There should be space before and after the operator
        int sum = number1 + number2;

        // The statement can be more complete though
        cout << "The result of " << number1 << " + " << number2 << " is: " << sum << '\n';

        if (sum > 25) {
            // Should be indented
            cout << sum <<  " is a Large number." << '\n';
        } else {
            // Should not be a one line 
            cout << sum << " is a Small number." << '\n';
        }
    }
};

int main() {
    CalculateNumber sum;
    sum.addition();
    return 0;
}