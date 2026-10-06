/// Lab 2: Practical data types application

#include <iostream>
#include <streambuf>
#include <climits> /// For data type limits like INT_MAX or INT_MIN
#include <iomanip>
#include <typeinfo> 


int main() {
    /// Display program header

    std::cout << std::string(30, '=') << '\n';
    std::cout << std::string(5, ' ') << "PRACTICAL DATA TYPES" << std::string(5, ' ') << '\n';
    std::cout << std::string(30, '=') << '\n';

    std::cout << "This program demonstreate appropriate usage of different data types" << '\n';
    std::cout << "for various kings of information" << '\n' << '\n';

    /// Program sections

    /// Section 1: AGE DATA SECTION
    std::cout << std::string(10, '-') << "AGE DATA SECTION" << std::string(10, '-') << '\n';
    std::cout << "Selecting apporpriate data types for age information" << '\n';

    /// Integer types for ages (no fractional years needed)
    int childAge {8};
    int teenAge {15};
    int adultAge {42};

    /// Display age information 
    std::cout << std::string(15, '-') << "Age Information" << std::string(15, '-') << '\n';
    std::cout << std::left << std::setw(10) << "Child age" << std::right << std::setw(10) << childAge << '\n';
    std::cout << std::left << std::setw(10) << "Teen age" << std::right << std::setw(10) << teenAge << '\n';
    std::cout << std::left << std::setw(10) << "Adult age" << std::right << std::setw(10) << adultAge << '\n';

    /// check memory usage for the data type
    std::cout << '\n' << std::string(10, '-') << "Age data memory usage" << std::string(10, '-') << '\n';
    std::cout << std::left << std::setw(10) << "Size of int (for ages)" << std::right << std::setw(10) << sizeof(int) << '\n';
    

    /// Demonstrate age calculation 
    std::cout << '\n' << std::string(15, '=') << "Age calculations" << std::string(15, '=') << '\n';
    int totalAges {teenAge + childAge + adultAge};
    std::cout << std::left << std::setw(10) << "Total of all ages" << std::right << std::setw(15) << totalAges << " years " << '\n';
    
    /// Practice challenge 1
    /// average age calcullation
    int averageAge {totalAges/3};
    std::cout << std::left << std::setw(10) << "Average of all the ages" << std::right << std::setw(10) << averageAge << '\n';
    int ageDifference {adultAge - childAge};
    std::cout << std::left << std::setw(30) << "Age difference between the adult and the child" << std::right <<std::setw(10) << ageDifference << '\n';
    /// Calculate my age: We need my birth year and the year now
    int yearOfBirth {1999};
    int presentYear {2026};
    int myAge {presentYear - yearOfBirth};
    /// Display my age
    std::cout << std::left << std::setw(10) << "My age" << std::right << std::setw(10) << myAge << '\n';

    /// Section 2: PRICE DATA SECTION
    /// Display the Price data section header 
    std::cout << '\n' << std::string(20, '-') << "PRICE DATA SECTION" << std::string(20, '-') << '\n';
    std:: cout << "Selecting appropriate data types for price information" << '\n';

    /// Use double for prices (needs decimal precision)
    double coffeePrice {3.99};
    double laptopPrice {1299.99};
    double housePrice {350000.00};

    /// Display each price information
    std::cout << std::left << std::setw(20) << "Coffee price" << std::right << std::setw(20) << coffeePrice << '\n';
    std::cout << std::left << std::setw(20) << "Laptop price" << std::right << std::setw(20) << laptopPrice << '\n';
    std::cout << std::left << std::setw(20) << "House price" << std::right << std::setw(20) << housePrice << '\n';


    /// Show memory usage comparison between double and float if used in price
    float priceAsFloat {19.99f};
    double priceAsDouble {19.99};

    std::cout << std::string(15, '-') << "Price Storage Comparison" << std::string(15, '-') << '\n';
    std::cout << std::string(50, '-') << '\n';
    std::cout << std::left << std::setw(20) << "Data Type" << std::left << std::setw(10) << "Value" << std::right << std::setw(20) << "Memory Usage (bytes)" << '\n';
    std::cout << std::left << std::setw(20) << "Price as float" << std::left << std::setw(10) << priceAsFloat << std::right << std::setw(10) << sizeof(float) << '\n';
    std::cout << std::left << std::setw(20) << "Price as double" << std::left << std::setw(10) << priceAsDouble << std::right << std::setw(10) << sizeof(double) << '\n';

    /// Simple price calculation
    std::cout << std::string(10, '-') << "Calculate of Prices" << std::string(10, '-') << '\n';
    double totalPrice {coffeePrice + laptopPrice + housePrice};
    std::cout << "The total price of " << "Coffee (" << coffeePrice << ") + laptop (" << laptopPrice << ") + House (" << housePrice << ") is: $" << totalPrice << '\n'; 
    std::cout << " Coffee + Laptop total: $" << coffeePrice + laptopPrice << '\n';


    /// Section 3: CHARACTER DATA SECTION
    std::cout << std::string(15, '-') << "CHARACTER DATA SECTION" << std::string(15, '-') << '\n';
    std::cout << "Selecting appropriate data types for character information" << '\n';

    /// Character variables to hold single characters
    char studentGrade {'A'};
    char symbol {'#'};
    char studentInitial {'J'};

    /// Display character information
    std::cout << std::left << std::setw(15) << "Student Grade" << std::right << std::setw(15) << studentGrade << '\n';
    std::cout << std::left << std::setw(15) << "Symbol" << std::right << std::setw(15) << symbol << '\n';
    std::cout << std::left << std::setw(15) << "studentInitial" << std::right << std::setw(15) << studentInitial << '\n';

    /// Show memory usage of char data type
    std::cout << '\n' << std::string(15, '-') << "Character data memory usage" << std::string(15, '-') << '\n';
    std::cout << std::string(30, '-') << '\n';
    std::cout << std::left << std::setw(15) << "Size of char" << std::right << std::setw(15) << sizeof(char) << '\n';

    /// Practice challenge 2
    /// Create variables for your first and last name initials
    char firstNameInitial {'N'};
    char lastNameInitial {'D'};

    /// Display the User Initials of firstname and lastname
    std::cout << '\n' << std::string(15, '-') << "Initials and memory size" << std::string(15, '-') << '\n';

    std::cout << std::string(30, '=') << '\n';
    std::cout << std::left << std::setw(10) << "Variable" << std::right << std::setw(15) << "ASCII value" << '\n';
    std::cout << std::left << std::setw(10) << firstNameInitial << std::right << std::setw(15) << static_cast<int>(firstNameInitial) << '\n';
    std::cout << std::left << std::setw(10) << lastNameInitial << std::right << std::setw(15) << static_cast<int>(lastNameInitial) << std::endl;


    /// Section 4: BOOLEAN DATA SECTION
    std::cout << std::string(15, '-') << "BOOLEAN DATA SECTION" << std::string(15, '-') << '\n';
    std::cout << "Using simple boolean data types for true or false information" << '\n';

    /// Boolean variables for simple flags
    bool isActive {"true"};
    bool hasPermission {"false"};
    bool isCompleted {"true"};

    /// Display boolean values (you will see 1 if true and 0 if false);
    std::cout << std::left << std::setw(15) << "Process or Task" << std::right << std::setw(15) << "Boolean Value" << '\n';
    std::cout << std::string(30, '-') << '\n';
    std::cout << std::left << std::setw(15) << "User accournt active" << std::left << std::setw(20) << isActive << '\n';
    std::cout << std::left << std::setw(15) << "User has admin permission" << std::right << std::setw(20) << hasPermission << '\n';
    std::cout << std::left << std::setw(15) << "Task Completed" << std::right <<std::setw(20) << isCompleted << '\n' << '\n';

    /// Show memory usage of bool
    std::cout << '\n' << std::string(15, '-') << "Boolean memory usage" << std::string(15, '-') << '\n';
    std::cout << std::left << std::setw(15) << "Size of bool" << std::right << std::setw(15) << sizeof(bool) << '\n';
    
    /// Simple boolean comparisons
    std::cout << std::string(15, '-') << "Boolean Comparisons" << std::string(15, '-') << '\n';
    std::cout << "Are both account active and task completed?"<< '\n';
    if (isActive == true && isCompleted == true) {
        std::cout << "Answer: Yes" << '\n';
    } else {
        std::cout << "Answer: No" << '\n';
    }


    /// Lets Combine all the section into one Example
    std::cout << std::string(15, '=') << "SIMPLE PRODUCT EXAMPLE" << std::string(15, '=') << '\n';
    std::cout << "Combining multiple data types for a product" << '\n';

    /// Product information using different data types
    int firstProductId {12345};
    double firstProductPrice {29.99};
    char firstProductGrade {'8'};
    bool inStockFirstProduct {"true"};


    /// Add additional products
    /// Add second product details
    int secondProductId {123456};
    double secondProductPrice {493.435};
    char  secondProductGrade {'9'};
    bool inStockSecondProduct {"false"};

    /// Display product information
    std::cout << '\n' << std::string(15, '=') << "PRODUCT INFORMATION" << std::string(15, '=') << '\n';
    std::cout << std::string(30, '-') << '\n';
    std::cout << std::left << std::setw(10) << "Label" << std::right << std::setw(15) << "Value" << '\n';
    std::cout << std::left << std::setw(10) << "Product ID" << std::right << std::setw(15) << firstProductId << '\n';
    std::cout << std::left << std::setw(10) << "Product Price" << std::right << std::setw(15) << '&' << firstProductPrice<< '\n';
    std::cout << std::left << std::setw(10) << "Quality Grade" << std::right << std::setw(15) << firstProductGrade << '\n';
    std::cout << std::left << std::setw(10) << "In Stock" << std::right << std::setw(15) << inStockFirstProduct << '\n';

    /// Simple calculations
    double salesTax {firstProductPrice * 0.08}; // 8% tax
    double totalPriceWithTax {firstProductPrice + salesTax};


    std::cout << std::string(15, '=') << "Price Calculations" << std::string(15, '=') << '\n';
    std::cout << std::string(40, '-') << '\n';
    std::cout << "Sales tax (8%): $" << salesTax << '\n';
    std::cout << "Total price with tax: $" << totalPrice << '\n';

    /// Memory usage
    int totalMemorySize {sizeof(firstProductId) + sizeof(firstProductPrice) + sizeof(firstProductGrade) + sizeof(inStockFirstProduct)};
    std::cout << '\n' << "Total memory used in the simple program for this product: " << totalMemorySize << "bytes" << std::endl;

    /// Additional Section for data type experimentations
    /// Est. data type limits

    std::cout << std::string(15, '=') << "LONG AND SHORT DATA TYPES" << std::string(15, '=') << '\n';
    /// Lets try to put a very large number in int
    int money {INT_MAX};
    /// Initialize a short variable and long variable
    short health {SHRT_MAX};
    long atomicDistance {LONG_MAX};

    /// Try putting an char to an int variable
    char variableContainer = 40;

    std::cout << '\n' << std::left << std::setw(5) << "Data type ID" << std::right << std::setw(25) << "Data type Name" << 
    std::right << std::setw(20) << "Data Value" << std::right<< std::setw(20) << "Memory usage" << '\n';
    
    std::cout << std::left << std::setw(5) << typeid(health).name() << std::right << std::setw(25) << "Short" << 
    std::right << std::setw(25) << health <<  std::right << std::setw(20) << sizeof(health) << '\n';

    std::cout << std::left << std::setw(5) << typeid(atomicDistance).name() << std::right << std::setw(25) << "Long" <<
    std::right << std::setw(25) << atomicDistance << std::right << std::setw(20) << sizeof(atomicDistance) << '\n';

    std::cout << std::left << std::setw(5) << typeid(money).name() << std::right << std::setw(25) << "Int" << 
    std::right << std::setw(25) << money << std::right << std::setw(20) << sizeof(money) << '\n';

    std::cout << std::left << std::setw(5) << typeid(variableContainer).name() << std::right << std::setw(25) << "Char" << 
    std::right << std::setw(25) << variableContainer << std::right << std::setw(20) << sizeof(variableContainer) << '\n';


/*
*   🤔 Reflection Questions
*   Why is int more appropriate for ages than float or double?

*   What advantage does double have over float for storing prices?

*   When would you use char instead of int for storing information?

*   Why is bool useful even though it only stores true/false?

*   How does understanding data type memory usage help in programming?

*   🌟 Optional Bonus Challenges
*   If you finish early and want to explore more:

*   est data type limits: Try storing very large numbers in int variables and see what happens

*   Compare memory usage: Create variables of type short and long and compare their memory usage with int

*   Character exploration: Try storing numbers in char variables and see how they display

*   Add more products: Expand the product example with 3-4 different products
*/
    return 0;
}