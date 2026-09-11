#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, w;
};

struct Node {
    long long d;
    int u, c;
    bool operator<(const Node& other) const {
        return d > other.d;
    }
};

vector<Edge> edge[100005];
long long price[100005];
long long dis[100005][45];

int main() {
    int n, m, s, C;
    cin >> n >> m >> s >> C;

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
    }

    for (int i = 1; i <= n; i++) {
        int id;
        cin >> id >> price[id];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= C; j++) {
            dis[i][j] = (1LL << 60);
        }
    }

    priority_queue<Node> que;
    dis[1][s] = 0;
    que.push({0, 1, s});

    while (!que.empty()) {
        Node t = que.top();
        que.pop();

        int u = t.u;
        int c = t.c;
        long long d = t.d;

        if (d != dis[u][c]) continue;

        // 如果当前城市有充电桩，可以多充 1 格电
        if (price[u] > 0 && c < C) {
            if (dis[u][c + 1] > d + price[u]) {
                dis[u][c + 1] = d + price[u];
                que.push({dis[u][c + 1], u, c + 1});
            }
        }

        // 如果当前电量足够，则可以沿边走到下一个城市
        for (int i = 0; i < (int)edge[u].size(); i++) {
            int v = edge[u][i].to;
            int w = edge[u][i].w;
            if (c < w) continue;
            if (dis[v][c - w] > d) {
                dis[v][c - w] = d;
                que.push({dis[v][c - w], v, c - w});
            }
        }
    }

    long long ans = (1LL << 60);
    for (int i = 0; i <= C; i++) {
        ans = min(ans, dis[n][i]);
    }

    if (ans == (1LL << 60)) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
