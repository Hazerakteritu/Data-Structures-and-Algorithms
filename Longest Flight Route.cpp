#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(n) n.begin(), n.end()
const ll INF = -1e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> graph(n + 1); // {to, weight}
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back({b, 1});
    }

    vector<ll> indegree(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        for (auto edge : graph[i]) {
            indegree[edge.first]++;
        }
    }

    queue<ll> q;
    for (ll i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<ll> topo;
    while (!q.empty()) {
        ll node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto edge : graph[node]) {
            ll to = edge.first;
            indegree[to]--;
            if (indegree[to] == 0) q.push(to);
        }
    }

    vector<ll> dist(n + 1, INF);
    vector<ll> parnt(n + 1, -1);
    dist[1] = 0;

    for (auto node : topo) {
        if (dist[node] == INF) continue;
        for (auto edge : graph[node]) {
            ll to = edge.first, weight = edge.second;
            if (dist[node] + weight > dist[to]) {
                dist[to] = dist[node] + weight;
                parnt[to] = node;
            }
        }
    }

    if (dist[n] == INF) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<ll> path;
        for (ll i = n; i != -1; i = parnt[i]) {
            path.push_back(i);
        }
        reverse(all(path));

        cout << dist[n] + 1 << endl;
        for (ll i : path) cout << i << " ";
        cout << endl;
    }
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
