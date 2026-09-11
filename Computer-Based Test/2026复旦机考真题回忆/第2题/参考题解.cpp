#include <bits/stdc++.h>
using namespace std;

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    string s;
    cin >> s;

    map<string, long long> ans;
    stack<long long> st;

    long long total_mul = 1;
    long long pending = 0; // 当前数字，尚未被消费

    for (int i = (int)s.size() - 1; i >= 0; ) {
        if (is_digit(s[i])) {
            long long val = 0;
            long long base = 1;
            int j = i;
            while (j >= 0 && is_digit(s[j])) {
                val += (s[j] - '0') * base;
                base *= 10;
                j--;
            }
            pending = val;
            i = j;
        } else if (s[i] == ')') {
            long long mul = (pending == 0 ? 1 : pending);
            st.push(mul);
            total_mul *= mul;
            pending = 0;
            i--;
        } else if (s[i] == '(') {
            long long mul = st.top();
            st.pop();
            total_mul /= mul;
            pending = 0;
            i--;
        } else {
            int j = i;
            while (j >= 0 && s[j] >= 'a' && s[j] <= 'z') {
                j--;
            }
            string elem = s.substr(j, i - j + 1);
            long long cnt = (pending == 0 ? 1 : pending);
            ans[elem] += cnt * total_mul;
            pending = 0;
            i = j - 1;
        }
    }

    for (auto it = ans.begin(); it != ans.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
