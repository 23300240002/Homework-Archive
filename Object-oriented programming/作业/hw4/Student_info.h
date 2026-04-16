#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <string>
#include <vector>
#include <istream>

class Student_info {
public:
	// 默认构造函数
	Student_info(): midterm(0), final(0) {}
	// 带输入流参数的构造函数
	Student_info(std::istream& is): midterm(0), final(0) { read(is); }

	std::istream& read(std::istream& in); // 读取学生信息
	double grade() const; // 计算学生成绩
	std::string name() const { return n; } // 获取学生姓名
	bool valid() const { return !homework.empty(); } // 判断学生成绩是否有效

private:
	std::string n; // 学生姓名
	double midterm; // 期中成绩
	double final; // 期末成绩
	std::vector<double> homework; // 作业成绩列表

};

// 比较学生姓名，用于排序
bool compare(const Student_info& x, const Student_info& y);
// 读取学生作业成绩
std::istream& read_hw(std::istream& in, std::vector<double>& hw);

#endif
