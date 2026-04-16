#ifndef GUARD_analysis_h
#define GUARD_analysis_h

#include <vector>
#include "Student_info.h"

double median_analysis(const std::vector<Student_info> & students);
double average_analysis(const std::vector<Student_info> & students);
double optimistic_median_analysis(const std::vector<Student_info> & students);

#endif
