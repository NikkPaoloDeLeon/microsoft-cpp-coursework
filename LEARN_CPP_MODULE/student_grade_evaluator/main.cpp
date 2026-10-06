/// This is where the coordination of the student grade evaluator system happens

///  Include header files
#include "grading_logic.h"
#include "report_display.h"

/// Include I/O library
#include <iostream>

/// Asks for user input and call  other functions
int main() {

    
    printSystemHeader();

    /// Initialize then ask for raw prelim grade
    float rawPrelim {0.0};
    std::cout << "Enter Prelim Grade: ";
    std::cin >> rawPrelim;

    /// Initialize then ask for raw midterm grade
    float rawMidterm {0.0};
    std::cout << "Enter Midterm Grade: ";
    std::cin >> rawMidterm;

    /// Initialize then ask for raw final grade
    float rawFinal {0.0};
    std::cout << "Enter Final Grade: ";
    std::cin >> rawFinal;

    /// Initialize the weightedPrelim then assign to it the captured return value of the function calculatePrelimWeight;
    float weightedPrelim = calculatePrelimWeight(rawPrelim);

    /// Initialize the weightedMidterm then assign to it the captured return value of the function calculateMidtermWeight
    float weightedMidterm = calculateMidtermWeight(rawMidterm);

    /// Initialize the weightedFinal then assign to it the captured return value of the function calculateFinalWeight
    float weightedFinal = calculateFinalWeight(rawFinal);

    /// Initialize the final grade then assign to it the capture value of the function computeTotalGrade 
    float finalGrade = computeTotalGrade(weightedPrelim,  weightedMidterm, weightedFinal);


    /// Display the Breakdown of the grades first therefore we call the function that is incharge of printing it
    printComponentBreakdown(weightedPrelim, weightedMidterm, weightedFinal);
    
    /// Display the final score of 
    printFinalScore(finalGrade);


    return 0;
}