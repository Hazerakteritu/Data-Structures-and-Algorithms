#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d", &a)
#define pb push_back
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define memo(a, b) memset((a), (b), sizeof(a))

vector<int> adj[105];
int color[105][3];

void dfs(int u, int col)
{
    if (col != -1)
        color[u][col] = 1;

    int nextcol = 1;
    if (col == 1)
    {
        nextcol = 2;
    }

    for (int i = 0; i < adj[u].size(); ++i)
    {
        if (!color[adj[u][i]][nextcol])
        {
            dfs(adj[u][i], nextcol);
        }
    }

}

int main()
{
    int cs, T;
    sc(T);

    FOR(cs, 1, T)
    {
        int n, m, u, v, i, one = 0, two = 0, ct = 0, j;

        cin >> n >> m;
        FOR(i, 1, n)
        {
            adj[i].clear();
        }
        FOR(i, 1, m)
        {
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        bool check = true;
        memo(color, 0);
        dfs(1, -1);

        ct = 0;
        FOR(i, 1, n)
        {
            if (color[i][2] == 1)
            {
                ct++;
            }
        }

        printf("Case %d: %d\n", cs, ct);
    }

    return 0;
}
