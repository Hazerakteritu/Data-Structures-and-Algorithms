#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
const int INF = 1e17;
#define MX 100000+6
#define mod 998244353

bool isSafe(int node, int clr, int color[], vector<vector<int>>&adj, int n)
{
    for(auto it: adj[node]){
        if(it!= node && color[it]== clr )
            return false;
    }
    return true;
}

bool solve(int node, int color[], vector<vector<int>>&adj, int n, int m)
{
    if(node == n)
    {
        return true;
    }

    for(int i=1; i<=m; i++)
    {
        if(isSafe(node, i, color, adj, n))
        {
            color[node] = i;
            if(solve(node+1, color, adj, n, m)== true)
                return true;
            color[node] = -1;

        }
    }
    return false;
}

int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    //cin>>t;
    while(t--)
    {
        int n, edj, m;
        cin>>n>>edj>>m;

        vector<vector<int>>adj(n);

        while(edj--)
        {
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        int color[n] = {-1};

        cout<<solve(0, color, adj, n, m)<<endl;

    }
}
