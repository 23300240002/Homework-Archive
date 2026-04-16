#include <vector>
#include <stdexcept>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using namespace std;

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.empty()) {
		throw domain_error("student has done no homework");
	}
	return grade(midterm, final, median(hw));
}

double grade(const Student_info& s)
{
	return s.grade();
}

