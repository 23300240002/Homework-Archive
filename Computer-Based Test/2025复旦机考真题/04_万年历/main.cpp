#include <bits/stdc++.h>
using namespace std;

long long count(long long y, long long m, long long d) {
    // 计算和 0 年 1 月 0 日 相差多少天
    long long total = 0;
    // 年
    long long r4 = (y + 3) / 4; // 4 的倍数
    long long r100 = (y + 99) / 100; // 100 倍数
    long long r400 = (y + 399) / 400; // 400 倍数
    long long r = r4 - r100 + r400; // 闰年个数
    long long p = y - r; // 平年个数
    total += r * 366 + p * 365;

    // 月
    if(m >= 2) total += 31;
    if(m >= 3) {
        if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) total += 29;
        else total += 28;
    }
    if(m >= 4) total += 31;
    if(m >= 5) total += 30;
    if(m >= 6) total += 31;
    if(m >= 7) total += 30;
    if(m >= 8) total += 31;
    if(m >= 9) total += 31;
    if(m >= 10) total += 30;
    if(m >= 11) total += 31;
    if(m >= 12) total += 30;

    // 日
    total += d;
    return total;
}

void solve() {
    long long y, m, d;
    cin >> y >> m >> d;
    long long diff1 = count(y, m, d);
    long long diff2 = count(2025, 8, 26);

    long long diff = diff1 - diff2;
    long long x = 0;
    if(diff >= 0) {
        x = diff % 7;
        if(x == 0) cout << "Tue\n";
        if(x == 1) cout << "Wed\n";
        if(x == 2) cout << "Thu\n";
        if(x == 3) cout << "Fri\n";
        if(x == 4) cout << "Sat\n";
        if(x == 5) cout << "Sun\n";
        if(x == 6) cout << "Mon\n";
    } else {
        x = (-diff) % 7;
        if(x == 0) cout << "Tue\n";
        if(x == 1) cout << "Mon\n";
        if(x == 2) cout << "Sun\n";
        if(x == 3) cout << "Sat\n";
        if(x == 4) cout << "Fri\n";
        if(x == 5) cout << "Thu\n";
        if(x == 6) cout << "Wed\n";
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
