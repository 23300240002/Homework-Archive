#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <string>
#include <istream>
#include <iostream>
#include "Vec.h"

class Student_info{
public:	
	Student_info():midterm(0),final(0){}
	Student_info(std::istream & is){read(is);}
	std::istream & read(std::istream & is);
	double grade()const;
	std::string name()const;
//	bool valid()const {return homework.empty();}
	bool fgrade()const;
	std::string leval()const;
private:
	//ADD:
	double score;
	std::string n;
	double midterm, final;
	Vec<double> homework;
};

bool compare(const Student_info &x, const Student_info &y);
std::istream & read_hw(std::istream & in, Vec<double> & hw);

#endif
