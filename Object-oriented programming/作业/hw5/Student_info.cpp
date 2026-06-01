#include "Student_info.h"
#include "grade.h"

using namespace std;

istream & read_hw(istream & in, Vec<double> & hw)
{
	if(in){
		hw.clear();
		double x;//a variable into which to read
		while(cin >> x){
			hw.push_back(x);
		}
		in.clear();
	}
	return in;
}

istream & Student_info::read(istream & is)
{
	is >> n >>midterm >>final;
	read_hw(is, homework);
	score = ::grade(midterm, final, homework);
	return is;
}

double Student_info::grade()const
{
	return score;
}

bool Student_info::fgrade()const
{
	return grade() < 60 ;
}

string Student_info::leval()const{
	double score=grade();
	if(score>=90) return "A";
	else if(score>=80) return "B";
	else if(score>=70) return "C";
	else if(score>=60) return "D";
	return "F";
}

bool compare(const Student_info &x, const Student_info &y)
{
	return x.name() < y.name();
}

inline string Student_info::name()const{
	return n;
}
