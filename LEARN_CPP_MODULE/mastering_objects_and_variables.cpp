/// mastering Objects and Variables and their Assignment and Intialization

/// Include header files
/// This header file is for the input and output library. cout << to output to the console
#include <iostream>
/// This header is for the limits libary e.g. INT_MAX
#include <climits>
/// This header is for the string library
#include <string>
/// This header is for the setw function for table properties
#include <iomanip>

/// Create the main function
int main() {
    /// Section 1: STUDENT INFORMATION
    /// Display header for the APPLICATION
    std::cout << std::string(120, '=') << '\n';
    std::cout << std::string(40, ' ') << "SIMPLE STUDENT INFORMATION SYSTEM" << std::string(40, ' ') << '\n'; 
    std::cout << std::string(120, '=') << '\n' << '\n';
    /// Student information used in these section here are literals
    /// The initialization used here is copy initialization
    std::cout << std::string(49, '-') << " STUDENT INFORMATION " << std::string(49, '-') << '\n';
    std::cout << std::left << std::setw(35) << "Name of Student" << std::right << std::setw(10) 
        << "ID" << std::right << std::setw(5) << "Age" 
        << std::right << std::setw(15) << "Local ID" << std::right << std::setw(20) << "Global Variable" 
        << std::right << std::setw(10) << "GPA" << std::right << std::setw(25) << "Allowance" << '\n';
    
    /// Initialize basic student information
    std::string studentName           = "Jose Rizal";
    char        studentID             = 'A';
    short       studentAge            = 26;
    int         studentUniqueLocalID  = LONG_MAX;
    long        studentUniqueGlobalID = LONG_MAX;
    float       studentGPA            = 93.85f;
    double      studentSavings        = 4566.78965879;

    /// This is to display the memory usage off the data type
    std::cout << std::left << std::setw(35) << studentName
        << std::right << std::setw(10) << studentID << std::right << std::setw(5) 
        << studentAge << std::right << std::setw(25) << std::right << std::setw(15) 
        << studentUniqueLocalID << std::right << std::setw(20) << studentUniqueGlobalID 
        << std::right << std::setw(10) << studentGPA << std::right << std::setw(25) << studentSavings << '\n' ;



    return 0;
}
