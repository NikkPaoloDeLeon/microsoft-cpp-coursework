// Include header guards
#ifndef STATISTICS_H
#define STATISTICS_H
#include <vector>
#include <limits>

double average(const std::vector<double>& numbers, std::size_t vectorSize);
double minimum(const std::vector<double>& numbers);
double maximum(const std::vector<double>& numbers);

#endif