// Create a basic structure for the expression evaluator

// Libraries to be used
#include <iostream>
#include <string>   
#include <iomanip>
#include <cmath>
#include <regex>

// Forward declarations for function
void displayHeader();
void displayMenu();
void demonstrateLogicalPrecedence();
void explainPrecedence();
void stepByStepEvaluation();
double performOperation(double a, char op, double b);
bool getOperationAndNumberForArithmetic();
bool getOperationAndNumberForComparison();
bool getOperationAndBooleanForLogic(); 
bool performComparison(double a, std::string op, double b);
bool performLogical(bool a, std::string op, bool b);
bool performLogicalNot(bool a);
bool performLogical2(bool a, std::string op1, bool b, std::string op2, bool c);
int getPrecedence(char op);
double applyOperator(double num1, char op, double num2);
double evaluateExpression(std::string expression);
void getOperatorAndOperandForComplexExpression();
double performComplexOperation(std::string expression);

// Functions for validation
bool isOperator(char c);

// introduce the porgam starting point
int main() {
    displayHeader();
    displayMenu();
    return 0;
}

void displayHeader() {
    std::cout << std::string('=', 30) << '\n';
    std::cout << std::string(' ', 5) << "MATHEMATICAL EXPRESSION EVALUATOR" << std::string(' ', 5) << '\n';
    std::cout << std::string('=', 30) << '\n';
}

void displayMenu() {
    int choice;
    std::cout << "\nSelect operation type: " << '\n';
    std::cout << "1. Arithmetic (number operator number)" << '\n';
    std::cout << "2. Comparison (number operator number)" << '\n';
    std::cout << "3. Logical (true/false operator true/false)" << '\n';
    std::cout << "4. Display logical precedence" << '\n';
    std::cout << "5. Complex expression" << '\n';
    std::cout << "6. Explain operator precedence" << '\n';
    std::cout << "7. Step-by-step evaluation" << std::endl;
    std::cin >> choice;
    if (choice == 1) {
        bool continueCalculation = true; 
        while (continueCalculation) {
            continueCalculation = getOperationAndNumberForArithmetic();
        }
    } else if (choice ==  2) {
        bool continueComparison = true;
        while (continueComparison) {
           continueComparison = getOperationAndNumberForComparison();
        }
    } else if (choice == 3) {
        bool continueLogical = true;
        while (continueLogical) {
            continueLogical = getOperationAndBooleanForLogic();
        }
    }else if (choice == 4) {
        demonstrateLogicalPrecedence();
    } else if (choice == 5) {
        getOperatorAndOperandForComplexExpression();
    } else if (choice == 6) {
        explainPrecedence();
    } else if (choice == 7) {
        std::string expression;
        std::cout << "Enter Mathematical expresion: ";
        std::cin.ignore();
        std::getline(std::cin, expression);
        stepByStepEvaluation(expression);
    } else {
        std::cout << "Invalid choice!" << std::endl;
    }

}
// Get operators and operands for a complex expression
void getOperatorAndOperandForComplexExpression() {
    std::string expression;
    std::cout << "Enter a complex expression (1 + 2 * 3 * 4 / 5): ";
    std::cin.ignore();
    std::cin >> expression;
    double result = evaluateExpression(expression);

}

// Function to explain operator precedence
void explainPrecedence() {
    std::cout << "\n===== OPERATOR PRECEDENCE =====" << '\n';
    std::cout << "Operators are evaluated in the following order (highest to lowest):" << '\n';
    std::cout << "1. Parentheses: ( )" << '\n';
    std::cout << "2. Exponentiation: ^" << '\n';
    std::cout << "3. Multiplication, Division, Modulus: *, /, %" << '\n';
    std::cout << "4. Addition, Subtraction: +, -" << '\n';
    std::cout << "5. Relational operators: <, >, <=, >=, ==, !=" << '\n';
    std::cout << "6. Logical NOT: !" << '\n';
    std::cout << "7. Logical AND: &&" << '\n';
    std::cout << "8. Logical OR: ||" << '\n';
    std::cout << "\nExample: 2 + 3 * 4 = 2 + (3 * 4) = 2 + 12 = 14" << '\n';
    std::cout << "Example: (2 + 3) * 4 = 5 * 4 = 20" << std::endl;
}

// Function to demonstrate step-by-step evaluation
void stepByStepEvaluation(std::string expression) {
    std::cout << "\n===== STEP-BY-STEP EVALUATION =====" << '\n';
    std::cout << "Expression: " << expression << '\n';
    std::cout << "Step 1: Identify operators and their precedence" << '\n';
    // This is a simplified demonstration
    // In a real step-by-step evaluator, we would show each step of the evaluation process    
    std::cout << "Step 2: Evaluate operations according to precedence" << '\n';
    if (expression.find('*') != std::string::npos || expression.find('/') != std::string::npos) {
    std::cout << "  - Evaluate multiplication and division first" << '\n';
    // Example: Replace this with actual step-by-step evaluation
    std::cout << "  - Example: If expression is '2 + 3 * 4', evaluate '3 * 4' first to get '12'" << '\n';
    }
    std::cout << "Step 3: Evaluate remaining operations" << '\n';
    std::cout << "Final result: " << evaluateExpression(expression) << std::endl;
}

double evaluateExpression(std::string expression) {
    // Create a vector of numbers and operators
    std::vector<double> operands;
    std::vector<char> operators;
    for (int i = 0; i < expression.length(); i++) {
        // Skip spaces
        if (expression[i] == ' ') {
            continue;
        }
        // If current character is a digit or a decimal 
        if (isdigit(expression[i]) || expression[i] == '.') {
            std::string numStr = "";
            // Extract the entire number
            while (i < expression.length() && isdigit(expression[i]) || expression[i] == '.') {
                numStr += expression[i];
                i++;
            }
            i--; // move back one position for the loop since the loop will increment
            // Conver string to double to add values
            operands.push_back(std::stod(numStr));

        }
        // If current character is an operator
        else if (isOperator(expression[i])) {
            while(!operators.empty() && getPrecedence(operators.back() >= getPrecedence(expression[i]))) {
                double val2 = operands.back(); operands.pop_back();
                double val1 = operands.back(); operands.pop_back();
                char op = operators.back(); operators.pop_back(); 
                operands.push_back(applyOperator(val1, op, val2));
            }
            operators.push_back(expression[i]);
        }
        // If current character an opening parenthesis
        else if (expression[i] == '(') {
            operators.push_back(expression[i]);
        }
        // If current character is a closing parenthesis
        else if (expression[i] == ')') {
            // Evauate everythging inside a parenthesis
            while (!operators.empty() && operators.back() != '()') {
                double val2 = operands.back(); operands.pop_back();
                double val1 = operands.back(); operands.pop_back(); 
                char op = operators.back(); operators.pop_back();
                operands.push_back(applyOperator(val1, op, val2));
            }
            // Remove teh opening parenthesis
            if (!operators.empty()) {
                operators.pop_back();
            }
        }
    }
    while (!operators.empty()) {
        double val2 = operands.back(); operands.pop_back();
        double val1 = operands.back(); operands.pop_back();
        char op = operators.back();  operators.pop_back();
        operands.push_back(applyOperator(val1, op, val2));
    }
    // Return final results
    if (!operands.empty()) {
        return operands.back();
    } else {
        return 0;
    }
    
}

double applyOperator(double num1, char op, double num2) {
    return performOperation(num1, op, num2);
}

// Validate if input is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}

int getPrecedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/' || op == '%') {
        return 2;
    } 
    if (op == '^') {
        return 3; 
    }
    return 0;
}


// Shows how logical precedence works under the hood
void demonstrateLogicalPrecedence() {
    bool val1, val2, val3;
    std::string op1, op2; 
    std::cout << "\nEnter values as 1 (true) or 0 (false)" << '\n';
    std::cout << "Expression (value operator value): ";
    std::cin >> val1 >> op1 >> val2 >> op2 >> val3;
    bool result = performLogical2(val1, op1, val2, op2, val3);
    std::cout << "Result: " << (val1 ? "true"  : "false") << ' ' << op1 << ' ' << (val2 ? "true"  : "false") << ' ' << op2 << ' ' << (val3 ? "true"  : "false") << " = " << (result ? "true"  : "false") << std::endl;

}
// Get the operator and the boolean for logic
bool getOperationAndBooleanForLogic() {
    bool continueLogic = true;
    bool val;
    std::cout << "\nSelect logical operation:" << '\n';
    std::cout << "1. AND/OR (value operator value)" << '\n';
    std::cout << "2. NOT (not value)" << '\n';
    std::cout << "Enter choice (1 or 2): " << '\n';
    int logicChoice;
    std::cin >> logicChoice;
    if (logicChoice == 1) {
        bool val1, val2;
        std::string op;
        std::cout << "\nEnter values as 1 (true) or 0 (false)" << '\n';
        std::cout << "Expression (value operator value): ";
        std::cin >> val1 >> op >> val2;
        bool result = performLogical(val1, op, val2);
        std::cout << "Result: " << (val1 ? "true" : "false") << ' ' << op << ' ' << (val2 ? "true" : "false") << " = " << (result ? "true" : "false") << '\n';
 
    } else if (logicChoice == 2) {
        bool val;
        std::cout << "\nEnter value as 1 (true) or 0 (false)" << '\n';
        std::cin >> val;
        bool result = performLogicalNot(val);
        std::cout << "Result: ! " << (val ? "true" : "false") << " = " << (result ? "true" : "false");
    } else {
        std::cout << "Invalid choice!";
    }
    int choice;
    std::cout << "Continue with another calculation (y/n)?: " << '\n';
    std::cin >> choice;
    toupper(choice); 
    continueLogic= (choice == 'Y' || choice == 'N');

    return continueLogic; 
}

// Get the operator and operands for comparison
bool getOperationAndNumberForComparison() {
    bool continueComparison;
    double num1, num2;
    std::string op;
    char choice;
    std::cout << "'Enter a comparison expression (number operator number): " << '\n';
    std::cout << "Available operators: ==, !=, <, >, <=, >=" << '\n';
    std::cin >> num1 >> op >> num2;
    bool result = performComparison(num1, op, num2);
    std::cout << "Result: " << num1 << ' ' << op << ' ' << num2 << ' ' << (result ? "Yes" : "No") << std::endl;
    std::cout << "Continue with another calculation (y/n)?: " << '\n';
    std::cin >> choice;
    toupper(choice); 
    continueComparison = (choice == 'Y' || choice == 'N');
    return continueComparison;
}
// Get the operator and the operands for arithmetic
bool getOperationAndNumberForArithmetic() {
    bool continueCalculation;
    double num1, num2;
    char op, choice;
    std::cout << '\n' <<"Enter a simple expression (number operator number): " << '\n';
    std::cin >> num1 >> op >> num2;
    double result {performOperation(num1, op, num2)};
    std::cout << num1 << ' ' << op << ' ' << num2 << " = " << result << '\n';
    std::cout << "Continue with another calculation (y/n)?: " << '\n';
    std::cin >> choice;
    toupper(choice); 
    continueCalculation = (choice == 'Y' || choice == 'N');
    return continueCalculation ;
}

// Perform logical operations
bool performLogical(bool a, std::string op, bool b) {
    if (op == "&&") {
        return a && b;
    } else if (op == "||") {
        return a || b;
    } else {
        std::cout <<"Error: Unknown logical operator" << '\n';
    }
    return false;
}

// Perform logical operations for 3 values
bool performLogical2(bool a, std::string op1, bool b, std::string op2, bool c) {
    if (op1 == "&&") {
        bool val1, val2;
        val1 = a && b;
        if (op2 == "&&") {
            val2 = val1 && c;
            return val2;
        } else if (op2 == "||") {
            val2 = val1 || c;
            return val2;
        }
    } else if (op1 == "||") {
        bool val1, val2;
        if (op2 == "&&") {
            val1 = b && c;
            return val2 = a || val1;
        } else if (op2 == "||") {
            val1 = a || b;
            val2 = val1 || c;
            return val2;
        }
    } else {
        std::cout <<"Error: Unknown logical operator" << '\n';
    }
    return false;
}
bool performLogicalNot(bool a) {
    return !a;
}

// Handle operational operators
bool performComparison(double a, std::string op, double b) {
    if (op == "==") {
        return static_cast<int>(a) == static_cast<int>(b);
    } else if (op == "!=") {
        return a != b;
    } else if (op == ">") {
        return a > b;
    } else if (op == "<") {
        return a < b;
    } else if (op == ">=") {
        return a >= b;
    } else if (op == "<=") {
        return a <= b;
    } else {
        std::cout << "Error: Unknown comparison operator" << '\n';
    }
    return false; 
}

// Basic Arithmetic Operation
double performOperation(double a, char op, double b) {
    switch (op) {
        case '+':
            return a + b; 
        case '-': 
            return a - b;
        case '*': 
            return a * b;
        case '/': 
            if (b != 0) {
               return a / b; 
            }else {
                std::cout << "Error: Division by zero" << '\n';
                return 0;
            }
        case '%': 
            if (b != 0) {
                return static_cast<int>(a) % static_cast<int>(b);
            } else {
                std::cout << "Error: Division by zero" << '\n';
                return 0;
            }
        case '^':
            if (b == 0) {
                return 1;
            } else {
                return static_cast<int>(a) ^ static_cast<int>(b);
            }
        default: 
            std::cout << "Error: Unknown Operator" << '\n';
            return 0;
    }
}