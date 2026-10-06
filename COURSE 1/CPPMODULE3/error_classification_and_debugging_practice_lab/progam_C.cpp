#include <iostream>
using namespace std;
int main() {
    int dividend, divisor;
    cout << "Enter two numbers for division: ";
    cin >> dividend >> divisor;
    int result = dividend / divisor;
    cout << dividend << " / " << divisor << " = " << result << endl;    
    return 0;
}