/// This file is for the forward declaration and header guards for all grading logic function
#ifndef GRADING_LOGIC_H
#define GRADING_LOGIC_H

/// Forward declarations for the grading logic functions
float calculatePrelimWeight(float rawScore);
float calculateMidtermWeight(float rawScore);
float calculateFinalWeight(float rawScore);
float computeTotalGrade(float prelimgGrade, float midtermGrade, float finalGrade);


#endif