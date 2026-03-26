#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    vector<double> num; // 数
    double ans = 0; // 最终答案
    for(string::size_type i = 0; i < s.size(); i++) {
        // 如果是数，完整读取
        double temp = 0;
        if(s[i] <= '9' && s[i] >= '0') {
            while(s[i] <= '9' && s[i] >= '0') {
                temp *= 10; // 进位
                temp += (s[i] - '0');
                i++;
            }
            if(s[i] == '.') { // 有小数点
                i++;
                double k = 10;
                while(s[i] <= '9' && s[i] >= '0') {
                    temp += (s[i] - '0') / k;
                    k *= 10;
                    i++;
                }
            }
            num.push_back(temp);
            // cout << "push " << temp << endl;
        }

        // 如果是符号，取后两个数运算
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            vector<double>::size_type l = num.size();
            if(l < 2) continue; // 出错
            double n1 = num[l - 1];
            double n2 = num[l - 2];
            // cout << "erase " << n1 << endl;
            // cout << "erase " << n2 << endl;
            auto it = num.begin() + l - 2;
            it = num.erase(it);
            it = num.erase(it);
            // 运算
            double new_num = 0;
            if(s[i] == '+') {
                new_num = n1 + n2;
            }
            if(s[i] == '-') {
                new_num = n2 - n1;
            }
            if(s[i] == '*') {
                new_num = n1 * n2;
            }
            if(s[i] == '/') {
                new_num = n2 / n1;
            }
            num.push_back(new_num);
            // cout << "push " << new_num << endl;
        }
    }

    ans = num[0]; // 最后应该只剩一个数
    cout << "result = " << ans << endl;
    return 0;
}
