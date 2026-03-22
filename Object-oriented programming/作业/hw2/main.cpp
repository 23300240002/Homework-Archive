#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <list>
#include "grade.h"
#include "Student_info.h"
using namespace std;

list<Student_info> extract_fails(list<Student_info> & students)
{
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();
	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else {
			++iter;
		}
	}
	return fail;
}


int main() 
{ 
	list<Student_info> students;
	Student_info record;
	while (read(cin, record)) {
		students.push_back(record);
	}

	students.sort();
	list<Student_info> fail = extract_fails(students);

	for (list<Student_info>::const_iterator it = fail.begin(); it != fail.end(); ++it) {
		cout << left << setw(10) << it->name
			 << "Your final grade is "
			 << fixed << setprecision(1) << grade(*it) << endl;
	}

	return 0; 
}
