#include "algorithm.h"
#include "Student_info.h"

using std::istream;
using std::vector;
using std::cin;
using MySpace::find;

istream & read_hw(istream & in, vector<double> & hw)
{
	if(in){
		hw.clear();
		double x;
		while(in >> x){
			hw.push_back(x);
		}
		in.clear();
	}
	return in;
}
istream & read(istream & is, Student_info &s)
{
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}
bool compare(const Student_info &x, const Student_info &y)
{
	return x.name < y.name;
}

bool did_all_hw(const Student_info & s)
{
	return find(s.homework.begin(), s.homework.end(), 0.0) == s.homework.end();
}
