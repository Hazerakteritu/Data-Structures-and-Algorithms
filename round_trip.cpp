#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>


vector<int> adj[100005];
bool vis[100005];
vector<int>cyc;

bool dfs(int s, int p)
{
    vis[s] = true;
    for (auto i : adj[s])
    {
        cyc.push_back(i);
        if (!vis[i])
        {
            if (dfs(i, s)) return true;
        }
        else if (i != p)
        {
            return true;
        }
        cyc.pop_back();
    }
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        cyc.push_back(i);
        if (!vis[i] && dfs(i, 0))
        {
            vector<int> ans = {*cyc.rbegin()};
            for (auto j = cyc.rbegin() + 1; j != cyc.rend(); j++)
            {
                ans.push_back(*j);
                if (*j == *cyc.rbegin()) break;
            }
            cout << ans.size() << '\n';
            for (auto i : ans) cout << i << " ";
            return;
        }
        cyc.pop_back();
    }
    cout << "IMPOSSIBLE";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--)
    {
        solve();
    }
}
