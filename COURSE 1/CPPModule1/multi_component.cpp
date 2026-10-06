#include <iostream>
#include <iomanip>
#include <string>
#include <array>

#include <chrono> // header for date and time
#include <random> // header for random numbers
using namespace std;


int main(){
    // Program title and introduction
    cout << "===========================================\n";
    cout << "               MULTI-COMPONENT\n";
    cout << "===========================================\n";
    cout << "This program demonstrates using multiple headers\n";
    cout << "and formatting techniques in C++\n";

    // Component 1: Basic information display
    cout << "---------- COMPONENT 1: BASIC INFO ----------\n";
    
    //Create variables to store information
    /*
    A string is a sequence of characters
    A variable is a storage location that holds a value
    */

   string name = "C++ Programming";
   string version = "C++17";
   string creator = "Bjorne Stroustrup";
   int yearCreated = 1985;

   //Display the information store in the variable
   cout << "Language: " << name << '\n';
   cout << "version: " << version << '\n';
   cout << "Creator: " << creator << '\n';
   cout << "Year Created: " << yearCreated << '\n';

   // Add more variables for additional facts a string, a bool and an int
   string fact1 = "C++ programming is a compiled language";
   bool fact2 = true;
   int fact3 = 0;

   // Display the additional facts
   cout << "Interesting Fact 1: " << fact1 << '\n';
   cout << "Interesting Fact 2: " << (fact2 ? "Yes" : "No") << '\n';
   cout << "Interesting Fact 3: " << fact3 << '\n';

    // Component 2: Formatted numeric output
    cout << "---------- COMPONENT 2: FORMATTED NUMBER ----------\n";

    // initialize numeric variables
    double pi {3.14159265358979323846};
    double e {2.71828182845904523536};
    double goldenRatio {1.61803398874989484820};

    // Display the different number precisions

    cout << "\nDefault display: \n";
    cout << "Pi = " << pi << '\n';
    cout << "e = " << e << '\n';
    cout << "Golden ration = " << goldenRatio << '\n';

    // Display it with a format of 2 decimal places
    cout << "\nWith 2 decimal places\n";
    cout << fixed << setprecision(2);
    cout << "Pi = " << pi << '\n';
    cout << "e = " << e << '\n';
    cout << "Golden ratio = " << goldenRatio << '\n';

    // Display it with the format of 6 decimal places
    cout << "\nWith 6 decimal places\n";
    cout << fixed << setprecision(6);
    cout << "pi = " << pi << '\n';
    cout << "e = " << e << '\n';
    cout << "Golden ration = " << goldenRatio << '\n';

    // Reset formatting of decimal places of the cout;
    cout.unsetf(ios::fixed);
    cout << setprecision(6);



    // Component 3: Table display;
    cout << "\n---------- COMPONENT 3: TABLE DATA ----------\n";

    // Set up table header
    // setw sets the field width for the next output;
    cout << left << setw(15) << "Data Type" << setw(20) << "Size(bytes)" << setw(20) << "Value Range" << '\n';
    cout << string(55, '-') << '\n';

    // Table rows
    cout << left << setw(15) << "int" << right << setw(20) << sizeof(int) << left << setw(20) << "  -2^31 to 2^31-1" << '\n';
    cout << left << setw(15) << "double" << right << setw(20) << sizeof(double) << left << setw(20) << "  +=7e^308" << '\n';
    cout << left << setw(15) << "char" << right << setw(20) << sizeof(char) << left << setw(20) << "  -128 to 127" << '\n';
    cout << left << setw(15) << "bool" << right << setw(20) << sizeof(bool) << left << setw(20) << "  true or false" << '\n';
    // Additional rows for additional rows
    cout << left << setw(15) << "float" << right << setw(20) << sizeof(float) << left << setw(20) << "   +=1.18x10^-38 to 3.40x10^38" << '\n';
    cout << left << setw(15) << "string" << right << setw(20) << sizeof(string) << left << "   no fixed range" << '\n';
    
    // Component 4: Custom component
    cout << "\n--------- COMPONENT 4: PROGRAM INFO ----------\n";
    // Get current data and time info (simulated)
    string currentDate {"2023-08-15"};
    string userName {"C++ Learner"};
    int linesOfCode {75};

    // Format and display program information
    cout << string(10,'-') << " Program: Multi-Component Example " << string(10, '-');
    cout << left << setw(15) << "Title" << setw(20) << "Value" << '\n';
    cout << string(45, '-') << '\n';
    cout << left << setw(15) << "Author" << right << setw(20) << userName << '\n';
    cout << left << setw(15) << "Date" << right << setw(20) << currentDate << '\n';
    cout << '\n' << string(10, '-') << "Code Statistics" << string(10, '-') << '\n';
    cout << left << setw(15) << "Lines of code" << right << setw(20) << linesOfCode << '\n';
    cout << left << setw(15) << "Header files" << right << setw(20) << '3' << '\n';
    cout << left << setw(15) << "Components" << right << setw(20) << '4' << '\n';

    // Display progress bar (simulated)
    cout << "Completion: [";
    int progress {80};
    //A loop allows something to happen over again
    for (int a = 0; a < 20; a++) {
        if(a < progress/5) {
            cout << '=';
        }else {
            cout << " ";
        }
    }
    cout << "] " << progress << "%" << '\n';

    //Program end
    cout << "\nProgram execution completed." << endl;

    //BONUS CHALLENGE
    /*
    1. If you're feeling adventurous, try implementing one or more of these enhancements:

    2. Add a component that uses mathematical functions from the <cmath> header

    3. Create a component that displays a simple animation using loops and timing

    4. Implement a component that formats and displays a simple CSV dataset
    */
    

    return 0;
}