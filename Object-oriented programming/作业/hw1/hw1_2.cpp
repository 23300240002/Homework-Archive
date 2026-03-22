#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() 
{ 
	vector<string> words;
	string word;
	while (cin >> word) {
		words.push_back(word);
	}

	if (!words.empty()) {
		size_t min_len = words[0].size();
		size_t max_len = words[0].size(); // 维护最大和最小长度

		for (vector<string>::size_type i = 1; i != words.size(); ++i) {
			if (words[i].size() < min_len) min_len = words[i].size();
			if (words[i].size() > max_len) max_len = words[i].size();
		}

		cout << "longest: ";
		for (vector<string>::size_type i = 0; i != words.size(); ++i) {
			if (words[i].size() == max_len) {
				cout << words[i] << "\t"; // \t 制表符，输出对齐
			}
		}
		cout << endl;
		cout << "shortest: ";
		for (vector<string>::size_type i = 0; i != words.size(); ++i) {
			if (words[i].size() == min_len) {
				cout << words[i] << "\t"; // \t 制表符，输出对齐
			}
		}
		cout << endl;
	} else {
		cout << "No word is entered." << endl;
	}

	return 0; 
}
