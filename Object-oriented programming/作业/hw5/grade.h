#ifndef GUARD_grade_h
#define GUARD_grade_h

#include "Student_info.h"
#include "Vec.h"

double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const Vec<double> & hw);
bool fgrade(const Student_info &s);

#endif
