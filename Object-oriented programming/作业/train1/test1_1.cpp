#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() { 
	string line;
	getline(cin, line); // 可输入多个单词

	stringstream ss(line);
	vector<string> words;
	string word;
	while (ss >> word) {
		words.push_back(word);
	}
	for (vector<string>::size_type i = words.size(); i > 0; --i) {
		cout << words[i - 1];
		if (i > 1) {
			cout << " ";
		}
	}
	cout << endl;
	return 0; 
}
