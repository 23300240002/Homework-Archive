#include <iostream>
#include <string>
#include <vector>
using namespace std;

std::vector<string> frame(const std::vector<string> & v) {
	// 先找最大长度
	string::size_type maxi = 0;
	for(string::size_type i = 0; i < v.size(); i++) {
		if(v[i].size() > maxi) maxi = v[i].size();
	}
	maxi += 4; // 左右空格和星号
	vector<string> ans;
	string temp = "";
	// 先加上边框
	for(string::size_type i = 0; i < maxi; i++) temp += "*";
	ans.push_back(temp);
	// 再加主体部分
	for(string::size_type i = 0; i < v.size(); i++) {
		temp = "";
		temp += "* ";
		temp += v[i];
		// 右侧空格数量
		for(int j = 1; j <= maxi - 3 - v[i].size(); j++) {
			temp += " ";
		}
		temp += "*";
		ans.push_back(temp);
	}
	// 最后加下边框
	temp = "";
	for(string::size_type i = 0; i < maxi; i++) temp += "*";
	ans.push_back(temp);
	return ans;
}

int main() 
{ 	
	vector<string> input;
	string s;
	while(getline(cin, s)) {
		if(!s.empty()) input.push_back(s);
	}
	vector<string> ans = frame(input);
	for(string::size_type i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	return 0; 
}
