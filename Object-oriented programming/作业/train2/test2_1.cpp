#include <iostream>
#include <string>
#include <vector>
using namespace std;

std::vector<string> split(const std::string & s) {
	vector<string> ans;
	vector<char> temp;
	for(string::size_type i = 0; i < s.size(); i++) {
		if(s[i] != ' ') {
			temp.push_back(s[i]);
		} else {
			if(!temp.empty()) {
				string str = "";
				for(auto c : temp) {
					str += c;
				}
				temp.clear();
				ans.push_back(str);
			}
		}
	}
	if(temp.size() != 0) { // 最后一个词
		string str = "";
		for(auto c : temp) {
			str += c;
		}
		temp.clear();
		ans.push_back(str);
	}
	return ans;
}

int main() 
{ 
	string s;
	getline(cin, s);
	vector<string> ans = split(s);
	for(string::size_type i = 0; i < ans.size(); i++) {
		cout << "\"" << ans[i] << "\"" << endl;
	}
	return 0; 
}
