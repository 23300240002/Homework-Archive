#include <bits/stdc++.h>
using namespace std;

int a[1000005], b[1000005], pos[1000005];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        pos[b[i]] = i;
    }

    vector<int> seq;
    seq.reserve(n);

    for (int i = 1; i <= n; i++) {
        int x = pos[a[i]];
        // 两个排列求 LCS，可以转化成一个位置序列的 LIS
        auto it = lower_bound(seq.begin(), seq.end(), x);
        if (it == seq.end()) {
            seq.push_back(x);
        } else {
            *it = x;
        }
    }

    cout << seq.size() << endl;
    return 0;
}
