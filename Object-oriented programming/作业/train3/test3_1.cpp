#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
	// 第2课学过 map，可用
	map<string, int> word_count;
	string word;

	while (cin >> word) {
		++word_count[word];
	}

	// map 自动按照 key 排序，输出必有序
	for (auto it = word_count.begin(); it != word_count.end(); ++it) {
		cout << it->first << " " << it->second << endl;
	}

	return 0; 
}
