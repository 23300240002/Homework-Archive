#include <bits/stdc++.h>
using namespace std;

int n;
long long power[55];

void solve() {
    long long x, y;
    cin >> x >> y;
    // 从 2^n 开始依次往下锁定，直到 2^1
    long long ans = 1;
    for(int i = n; i >= 1; i--) {
        if(x <= power[i - 1] && y <= power[i - 1]) { // 左上
            // 什么都不用干
        }
        if(x <= power[i - 1] && y > power[i - 1]) { // 右上
            y -= power[i - 1];
            ans += power[i - 1 + i - 1];
        }
        if(x > power[i - 1] && y <= power[i - 1]) { // 左下
            x -= power[i - 1];
            ans += 2 * power[i - 1 + i - 1];
        }
        if(x > power[i - 1] && y > power[i - 1]) { // 右下
            x -= power[i - 1];
            y -= power[i - 1];
            ans += 3 * power[i - 1 + i - 1];
        }
    }
    cout << ans << '\\n';
}

int main() {
    long long base = 1;
    for(int i = 0; i < 55; i++) {
        power[i] = base;
        base *= 2;
    }
    int T;
    cin >> n >> T;
    while(T--) solve();
    return 0;
}
