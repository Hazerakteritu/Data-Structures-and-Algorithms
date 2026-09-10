#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
const int INF = 1e17;
#define mx 200000+6

bool isSafe(int node, int color[], vector<vector<int>>&graph, int n, int clr)
{
    for(auto it: graph[node])
    {
        if(it!=node && color[it]==clr)
            return false;
    }
    return true;
}

bool solve(int node, int color[], int m, int N, vector<vector<int>>&graph)
{
    //base case
    if(node == N) return true;

    for(int i=1; i<=m; i++)
    {
        if( isSafe(node, color, graph, N, i))
        {
            color[node] = i;
            if(solve(node+1, color, m, N, graph))
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
    cout.tie(0);

    int t=1;
    cin>>t;
    while(t--)
    {
        int n,b;
        cin>>n>>b;
        vector<vector<int>>adj(n+1);
        while(b--)
        {
            int x, y;
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }


        int f=0;
        for(int i=1; i<=4; i++)
        {
            int color[n]= {0};
            if(solve(0, color, i, n, adj))
            {
                cout<<i<<endl;
                f=1;
                break;
            }
        }
        if(!f)
            cout<<"many"<<endl;

    }

    return 0;
}
