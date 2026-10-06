/// Implementation of the mathematical calculation of the grading system
#include "grading_logic.h"

/// Calculate the Finalterm weight by multiplying the raw score by 40%
float calculatePrelimWeight(float rawScore) {
    return rawScore * 0.40;
}

/// Calculate the Midterm weight by multiplying the raw score by 40%
float calculateMidtermWeight(float rawScore) {
    return rawScore * 0.40;
}

float calculateFinalWeight(float rawScore) {
    return rawScore * 0.40;
}

float computeTotalGrade(float prelimWeight, float midtermWeight, float finalWeight) {
    return prelimWeight + midtermWeight + finalWeight;
}