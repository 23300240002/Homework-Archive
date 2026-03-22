#include <algorithm>
#include <iostream>
#include <ios>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

int main() 
{ 
	cout << "Please enter your name:";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;
	cout << "Please enter you midterm and final exam grades:" << endl;

	double midterm = 0.0;
	double final_exam = 0.0;
	cin >> midterm >> final_exam;
	cout << "Enter all your homework grades, followed by end-of-file:" << endl;
	vector<double> homework;
	double x = 0.0;
	while (cin >> x) {
		homework.push_back(x);
	}

	sort(homework.begin(), homework.end());
	double median = 0.0;
	vector<double>::size_type size = homework.size(); // 不写这个扣分吗？
	if (size % 2 == 0) { // 偶数个元素，中位数是中间两个元素平均值
		median = (homework[size / 2 - 1] + homework[size / 2]) / 2;
	} else { // 奇数个元素，直接取中间元素
		median = homework[size / 2];
	}
	double grade = 0.2 * midterm + 0.4 * final_exam + 0.4 * median;
	cout << "Your final grade is " << fixed << setprecision(1) << grade << endl;
	cout << "Press any key to continue";
	return 0; 
} 
