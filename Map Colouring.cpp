#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back


bool isSafe(int node, int clr, int color[], vector<vector<int>>&adj, int n)
{
    for(auto it: adj[node])
    {
        if(it!= node && color[it]== clr) return false;
    }
    return true;

}

bool solve(int node, int color[], vector<vector<int>>&adj, int n, int m)
{
    if(node == n)
        return true;

    for(int i=1; i<=m; i++)
    {
        if(isSafe(node, i, color, adj, n))
        {
            color[node] = i;
            if(solve(node+1, color, adj, n, m))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int c,b;
        cin>>c>>b;
        vector<vector<int>>adj(c);
        while(b--)
        {
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        int fnd = 0;
        for(int i=1; i<=4; i++)
        {
            int color[c] = {0};
            if(solve(0, color, adj, c, i))
            {
                fnd = i;
                break;
            }
        }
        if(fnd) cout<<fnd<<endl;
        else cout<<"many"<<endl;
    }


    return 0;
}

