#include <iterator>
#include "analysis.h"
#include "Student_info.h"
#include "algorithm.h"
#include "grade.h"

using std::vector;
using std::back_inserter;
using MySpace::median;
using MySpace::transform;

double median_analysis(const vector<Student_info> & students)
{
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
    return median(grades);
}

double average_analysis(const vector<Student_info> & students)
{
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), average_grade);
    return median(grades);
}

double optimistic_median_analysis(const vector<Student_info> & students)
{
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
    return median(grades);
}
