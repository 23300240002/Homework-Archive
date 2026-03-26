#include <iostream>
#include <string>
#include <vector>
using namespace std;

int strToInt(const std::string s, int k) {
	if (s.empty()) return 0;

	int sign = 1;
	string::size_type start = 0;
	if (s[0] == '-') {
		sign = -1;
		start = 1;
	}
	int value = 0;
	for (string::size_type i = start; i != s.size(); ++i) {
		value = value * k + (s[i] - '0');
	}
	return sign * value;
}

int main() { 
	string s;
	int k;
	cin >> s >> k;
	cout << strToInt(s, k) << endl;
	return 0; 
}
