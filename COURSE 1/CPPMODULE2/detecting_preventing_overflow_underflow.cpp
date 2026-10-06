#include <climits>

bool willAdditionOverflow(int a, int b) {
    // Check for positive overflow
    if (a > 0 && b > 0 && a > INT_MAX - b){     // a== 1 b == 3
        return true;
    }

    // Check for negative overflow
    if (a < 0 && b < 0 && a < INT_MIN - b) {
        return true;
    }
    return false;
}

bool safeIntegerAddition(int a, int b, int& result) {
    if (willAdditionOverflow(a,b)) {
        return false;
    }

    result = a + b;

    return true; 
}

bool willMultiplicationOverflow(int a, int b) {
    // Handle special cases
    if (a == 0 || b == 0) { 
        return false;
    }
    if (a == 1 || b == 1) {
        return false;
    } 
    if (a == -1) {
        return (a == INT_MIN);
    }
    if (b == -1) {
        return (b == INT_MIN);

    // Check for overflow
    if  (a > 0 && b >0) {
        return a > INT_MAX / b;
    }
    if (a < 0 && b < 0) {
        return a < INT_MAX / b;
    }
    if (a < 0) {
        return a < INT_MIN / b;
    } else {
        return b < INT_MIN / a;
    }
    

    return false;


}
