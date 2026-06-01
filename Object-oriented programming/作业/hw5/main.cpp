#pragma warning(disable: 4786)
#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <map>
#include "grade.h"
#include "Student_info.h"
#include "Vec.h"
using namespace std;

void extract_levals(Vec<Student_info> & students,map<string,int>& levals)
{
	for(Vec<Student_info>::iterator iter=students.begin();iter!=students.end();iter++){
		string lv=iter->leval();
		map<string,int>::iterator it=levals.find(lv);
		if(it==levals.end()){
			levals.insert(pair<string,int>(lv,1));
		}else{
			it->second++;
		}	
	}
}

int main() 
{
	map<string,int> levals;
	Vec<Student_info> students,fails;
	Student_info record;
	string::size_type maxlen = 0;

	while(record.read(cin)){
		 if(record.name().size()>maxlen)
			 maxlen=record.name().size();
		students.push_back(record);
	}
	//sort(students.begin(),students.end(),compare);
	try{
		extract_levals(students,levals);
		for(map<string,int>::const_iterator i=levals.begin(); i!=levals.end();i++){
			cout << i->first << "\t"
				<< i->second << endl;
		}
	}catch(domain_error e){
			cout << e.what();
	}
	return 0; 
}
