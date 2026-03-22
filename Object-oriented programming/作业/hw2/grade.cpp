#include <vector>
#include <stdexcept>
#include "grade.h"
#include "median.h"

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

	double hw_score = 0.6 * average(hw) + 0.4 * median(hw);
	return grade(midterm, final, hw_score);
}

double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}

bool fgrade(const Student_info& s)
{
	return grade(s) < 60;
}

