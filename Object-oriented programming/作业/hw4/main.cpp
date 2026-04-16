#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <list>
#include "grade.h"
#include "Student_info.h"
using namespace std;

int main() { 
	vector<Student_info> students;
	Student_info record;

	while (record.read(cin)) {
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);
	for (vector<Student_info>::const_iterator iter = students.begin(); iter != students.end(); ++iter) {
		try {
			double final_grade = iter->grade();
			streamsize prec = cout.precision();
			cout << iter->name() << "'s final grade is "
				 << setprecision(3) << final_grade
				 << setprecision(prec) << endl;
		} catch (domain_error e) {
			cout << iter->name() << "'s final grade is " << e.what() << endl;
		}
	}
	return 0; 
}
