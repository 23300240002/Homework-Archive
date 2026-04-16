#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int main() { 
	map<string, vector<int>> xref; // 键为单词，值为出现在的行号列表
	string line;
	int line_no = 0; // 行号从 1 开始

	while (getline(cin, line)) {
		++line_no; // 行号加 1
		istringstream iss(line); // 将行分解成单词，是否超纲？
		string word;
		while (iss >> word) {
			// 同一行重复出现时只记录一次，坑点
			if (xref[word].empty() || xref[word].back() != line_no) {
				xref[word].push_back(line_no);
			}
		}
	}

	for (auto it1 = xref.begin(); it1 != xref.end(); ++it1) {
		cout << it1->first;
		for (auto it2 = it1->second.begin(); it2 != it1->second.end(); ++it2) {
			cout << " " << *it2;
		}
		cout << endl;
	}

    
	return 0; 
}
