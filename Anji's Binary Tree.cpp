#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 2;
vector<vector<int>> adj(N, vector<int>(2));
int ans;
string s;

void dfs(int node, int sum)
{
    if (!adj[node][0] && !adj[node][1])
        ans = min(ans, sum);
    if (adj[node][0])
    {
        if (s[node - 1] != 'L')
            dfs(adj[node][0], sum + 1);
        else
            dfs(adj[node][0], sum);
    }
    if (adj[node][1])
    {
        if (s[node - 1] != 'R')
            dfs(adj[node][1], sum + 1);
        else
            dfs(adj[node][1], sum);
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, i, u, v;
        cin >> n >> s;
        for (i = 1; i <= n; i++)
        {
            cin >> u >> v;
            adj[i][0] = u;
            adj[i][1] = v;
        }
        ans = INT_MAX;
        dfs(1, 0);
        cout << ans << endl;
    }
    return 0;
}
