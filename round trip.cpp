#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

vector<int>graph[N],v;
int vis[N], from[N], color[N], till;

int dfs(int p, int c) {
    if (vis[p] != -1) {
        till = p;
        v.push_back(p);
        return 1;
    }
    vis[p] = 1;
    for (int aa : graph[p]) {
        if (aa == c) continue;
        int x = dfs(aa, p);
        if (x == 1) {
            v.push_back(p);
            if (till == p) {
                return 2;
            } else {
                return 1;
            }
        } else if (x == 2) return 2;
    }
    vis[p] = 2;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    memset(vis, -1, sizeof(vis));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == -1) {
            if (dfs(i, -1) == 2) {
                reverse(v.begin(), v.end());
                cout << v.size() << '\n';
                for (int node : v) cout << node << ' ';
                cout << '\n';
                return 0;
            }
            v.clear();
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
