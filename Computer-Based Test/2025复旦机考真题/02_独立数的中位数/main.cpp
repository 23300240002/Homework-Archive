#include <bits/stdc++.h>
using namespace std;

int a[500005];
map<int, int> m; // 键为数值，值为存在的个数
set<int> small; // 前半部分
set<int> big; // 后半部分

void mpush(int x) {
    // cout << "inserting " << x << endl;
    // 要保证 small 与 big 大小相等或仅多 1
    if(small.size() == big.size()) {
        if(big.empty()) {
            small.insert(x);
            return;
        }
        int s = *(big.begin());
        if(x > s) { // 放入 big
            big.erase(s);
            big.insert(x);
            small.insert(s);
        } else { // 放入 small
            small.insert(x);
        }
    } else { // small 比 big 大 1
        auto it = small.end();
        int s = *(--it);
        if(x > s) { // 放入 big
            big.insert(x);
        } else { // 放入 small
            small.erase(s);
            small.insert(x);
            big.insert(s);
        }
    }
}

void mpop(int x) {
    // cout << "erasing " << x << endl;
    // 要保证 small 与 big 大小相等或仅多 1
    if(small.size() == big.size()) {
        int s = *(big.begin());
        if(x >= s) { // 在 big 中
            big.erase(x);
        } else { // 在 small 中
            big.erase(s);
            small.erase(x);
            small.insert(s);
        }
    } else { // small 比 big 大 1
        if(big.empty()) {
            small.erase(x);
            return;
        }
        auto it = small.end();
        int s = *(--it);
        if(x > s) { // 在 big 中
            big.erase(x);
            small.erase(s);
            big.insert(s);
        } else { // 在 small 中
            small.erase(x);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<int> ans;
    for(int i = 1; i <= k; i++) { // 加入 a[i]
        // cout << "Now: " << i << endl; 
        m[a[i]]++;
        if(m[a[i]] == 1) mpush(a[i]);
        if(m[a[i]] == 2) mpop(a[i]); // 超过 1 了
        // cout << "small size " << small.size() << endl;
        // cout << "big size " << big.size() << endl;
    }
    if(small.empty()) ans.push_back(INT_MAX);
    else {
        auto it = small.end();
        it--;
        ans.push_back(*it);
    }

    for(int i = k + 1; i <= n; i++) {
        // cout << "Now: " << i << endl; 

        // 加入 a[i]，移除 a[i - k]
        m[a[i - k]]--;
        if(m[a[i - k]] == 0) mpop(a[i - k]);
        if(m[a[i - k]] == 1) mpush(a[i - k]);
        
        m[a[i]]++;
        if(m[a[i]] == 1) mpush(a[i]);
        if(m[a[i]] == 2) mpop(a[i]); // 超过 1 了

        // cout << "small size " << small.size() << endl;
        // cout << "big size " << big.size() << endl;

        if(small.empty()) ans.push_back(INT_MAX);
        else {
            auto it = small.end();
            it--;
            ans.push_back(*it);
        }
    }

    for(int x : ans) {
        if(x == INT_MAX) cout << "no" << endl;
        else cout << x << endl;
    }
    return 0;
}