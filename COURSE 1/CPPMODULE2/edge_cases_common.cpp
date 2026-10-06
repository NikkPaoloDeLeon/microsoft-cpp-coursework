#include <climits>
#include <cfloat>
#include <iostream>

// Notes on Type Conversion and edge cases

int main() {
    // Edge case: Integer overflow
    int maxInt = INT_MAX;
    int integerOverflow = INT_MAX + 1;
    std::cout << "Max Integer value: " << maxInt << '\n';
    std::cout << "Integer Overflow: " << maxInt << " + 1 = " << integerOverflow << '\n';
    
    // Edge case: Integer Underflow
    int minInt = INT_MIN;
    int integerUnderflow = minInt - 1;
    std::cout << "Max Integer value: " << minInt << '\n';
    std::cout << "Integer Underflow: " << minInt << " - 1 = " << integerUnderflow << '\n';

    // Edge case: float and double overflow
    float maxFloat = FLT_MAX;
    double maxDouble = DBL_MAX;
    float floatOverflow = maxFloat * 2.0f;
    double doubleOverflow = maxDouble * 2.0;
    std::cout << "Max Float value: " << maxFloat << '\n';
    std::cout << "Float Overflow: " << maxFloat << " * 2 = " << floatOverflow << '\n';
    std::cout << "Max Double value: " << maxDouble << '\n';
    std::cout << "Double Overflow: " << maxDouble << " * 2 = " << doubleOverflow << '\n';
 
    // Edge case: float and double underflow
    float minFloat = FLT_TRUE_MIN;
    float floatUnderflow = minFloat / 2.0f;
    double minDouble = DBL_TRUE_MIN;
    double doubleUnderflow = minDouble / 2.0; 
    std::cout << "Min Float value: " << minFloat << '\n';
    std::cout << "Float underflow: " << minFloat << " / 2 = " << floatUnderflow << " Answer should be positive but due to overflow it is not" << '\n';
    std::cout << "Min Double value: " << minDouble<< '\n';
    std::cout << "Double underflow: " << minDouble << " / 2 = " << doubleUnderflow << " Answer should be positive but due to overflow it is not" << '\n';


    // Edge case: Zero in Division
    /*double result = 5.0 / 0.0; // results in infinity
    int intResult = 5 / 0; // undefines behavior
    std::cout << "When we divide by zero behavior becomes undefined: " << result << '\n';
    std::cout << "When we divide by zero behavior becomes undefined: " << intResult << '\n'; */

    float largeFloat = 25e10f;
    int largeFloatToInt = static_cast<int>(largeFloat); // My not fit in
    std::cout << "When we try to put an amount larger than the container : " << largeFloat << "-> Integer Container" << largeFloatToInt;
 
    
    return 0;
}