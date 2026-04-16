#include "Student_info.h"
#include "grade.h"

using namespace std;

// 该函数是一个独立的函数
istream& read_hw(istream& in, vector<double>& hw)
{
	if (in) {
		hw.clear();
		double x;
		while (in >> x) {
			hw.push_back(x);
		}
		in.clear();
	}
	return in;
}

// 该函数是 Student_info 类的一个成员函数
istream& Student_info::read(istream& in)
{
	in >> n >> midterm >> final; // 姓名、期中成绩、期末成绩都是成员变量，不需要指定
	read_hw(in, homework); // homework 为成员变量，不需要指定
	return in;
}

// 该函数是 Student_info 类的一个成员函数
double Student_info::grade() const
{
	// midterm、final 和 homework 都是成员变量，不需要指定
    // 但是调用全局函数 grade，因此要用作用域解析运算符 ::
    return ::grade(midterm, final, homework);
}

// 比较学生姓名，用于排序
bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}
