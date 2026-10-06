/// Includes header guards and forward declaration of the functions from the report display module

/// Header guards
#ifndef REPORT_DISPLAY_H
#define REPORT_DISPLAY_H

/// forward declarations for the printing functions: system header, component breakdown, final grade
void printSystemHeader();
void printComponentBreakdown(float weightedPrelim, float weightedMidterm, float weightedFinal);
void printFinalScore(float finalScore);



#endif 