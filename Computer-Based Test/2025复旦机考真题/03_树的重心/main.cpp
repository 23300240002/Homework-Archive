#include <bits/stdc++.h>
using namespace std;

vector<int> edge[200005];
int ans = INT_MAX;
int node = 0;
int n;

int dfs(int i, int fa) { // 计算子树大小
    int cost = 0;
    int total = 1;
    for(auto j : edge[i]) {
        if(j == fa) continue; // 上面不再重新计算
        int x = dfs(j, i);
        if(x > cost) cost = x;
        total += x;
    }
    if(n - total > cost) cost = n - total; // 上面部分

    if(cost < ans || (cost == ans && i < node)) {
        node = i;
        ans = cost;
    }
    return total; // 子树大小
}

int main() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    int x = dfs(1, 0);
    cout << node << " " << ans << endl;
    return 0;
}