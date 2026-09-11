#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char> > a, ans;
    a.resize(n + 1);
    ans.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i].resize(m + 1);
        ans[i].resize(m + 1);
    }

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            a[i][j] = s[j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '*') {
                ans[i][j] = '*';
                continue;
            }

            int cnt = 0;
            if (i > 1 && j > 1 && a[i - 1][j - 1] == '*') cnt++;
            if (i > 1 && a[i - 1][j] == '*') cnt++;
            if (i > 1 && j < m && a[i - 1][j + 1] == '*') cnt++;
            if (j > 1 && a[i][j - 1] == '*') cnt++;
            if (j < m && a[i][j + 1] == '*') cnt++;
            if (i < n && j > 1 && a[i + 1][j - 1] == '*') cnt++;
            if (i < n && a[i + 1][j] == '*') cnt++;
            if (i < n && j < m && a[i + 1][j + 1] == '*') cnt++;

            ans[i][j] = char('0' + cnt);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
