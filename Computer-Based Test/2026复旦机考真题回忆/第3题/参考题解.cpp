#include <bits/stdc++.h>
using namespace std;

struct Node {
    int nxt; // 这个数下一次出现的位置
    int c;   // 当前占据的缓存编号
    int n;   // 当前数的编号（离散化之后）
    bool operator<(const Node& other) const {
        if (nxt != other.nxt) return nxt < other.nxt;
        return c > other.c;
    }
};

int a[1000005];
int pre[1000005], nxt[1000005];
int cache_pos[1000005];    // 这个数当前在哪个缓存中，0 表示不在
int cache_num[1000005];    // 这个缓存里当前放的是哪个数
int cache_nxt[1000005];    // 这个缓存里当前这个数下一次出现的位置

int main() {
    int q, k;
    cin >> q >> k;

    vector<long long> raw(q + 1);
    vector<long long> all;
    all.reserve(q);
    for (int i = 1; i <= q; i++) {
        cin >> raw[i];
        all.push_back(raw[i]);
    }

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    for (int i = 1; i <= q; i++) {
        a[i] = lower_bound(all.begin(), all.end(), raw[i]) - all.begin() + 1;
    }

    unordered_map<int, int> last;
    last.reserve(q * 2);

    for (int i = 1; i <= q; i++) {
        if (last.count(a[i])) pre[i] = last[a[i]];
        else pre[i] = 0;
        last[a[i]] = i;
    }

    last.clear();
    const int INF = q + 1;
    for (int i = q; i >= 1; i--) {
        if (last.count(a[i])) nxt[i] = last[a[i]];
        else nxt[i] = INF;
        last[a[i]] = i;
    }

    priority_queue<Node> que;
    int now = 0;

    for (int i = 1; i <= q; i++) {
        int x = a[i];

        if (cache_pos[x] != 0) {
            int c = cache_pos[x];
            cout << "hit " << c << endl;
            cache_nxt[c] = nxt[i];
            que.push({cache_nxt[c], c, x});
            continue;
        }

        if (now < k) {
            now++;
            cache_pos[x] = now;
            cache_num[now] = x;
            cache_nxt[now] = nxt[i];
            que.push({cache_nxt[now], now, x});
            cout << "miss " << now << endl;
            continue;
        }

        while (!que.empty()) {
            Node t = que.top();
            if (cache_num[t.c] == t.n && cache_nxt[t.c] == t.nxt) break;
            que.pop();
        }

        Node t = que.top();
        
        if (nxt[i] >= t.nxt) {
            cout << "miss 0" << endl;
            continue;
        }

        que.pop();
        int c = t.c;
        cache_pos[cache_num[c]] = 0;

        cache_pos[x] = c;
        cache_num[c] = x;
        cache_nxt[c] = nxt[i];
        que.push({cache_nxt[c], c, x});

        cout << "miss " << c << endl;
    }

    return 0;
}
