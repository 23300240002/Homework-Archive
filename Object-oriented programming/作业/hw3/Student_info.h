#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <vector>
#include <string>
#include <istream>
#include <iostream>

struct Student_info{
	std::string name;
	double midterm, final;
	std::vector<double> homework;
	bool operator<(const Student_info &n)const{
		return name<n.name;
	}

};

bool compare(const Student_info &x, const Student_info &y);
std::istream & read(std::istream & is, Student_info &s);
std::istream & read_hw(std::istream & in, std::vector<double> & hw);
bool did_all_hw(const Student_info & s);

#endif
