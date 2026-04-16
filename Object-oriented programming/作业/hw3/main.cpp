#pragma warning(disable: 4786)
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <map>
#include "algorithm.h"
#include "grade.h"
#include "Student_info.h"
#include "analysis.h"
using namespace std;

void write_analysis(ostream & out, const string & name, 
double analysis(const vector<Student_info>&), 
const vector<Student_info> & did, const vector<Student_info> & didnt) {
	out << name << ": median(did) = " << analysis(did)
		<< ", median(didnt) = " << analysis(didnt) << endl;
}

int main() { 
	vector<Student_info> did, didnt;
	Student_info record;
	while(read(cin, record)){
		if(did_all_hw(record))
			did.push_back(record);
		else
			didnt.push_back(record);
	}
	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);
	
	return 0; 
}
