#include <stdexcept>
#include "grade.h"
#include "median.h"
#include "Vec.h"

using namespace std;

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const Vec<double> & hw)
{
	if(hw.size()==0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, 0.6*average(hw)+0.4*median(hw));
}

