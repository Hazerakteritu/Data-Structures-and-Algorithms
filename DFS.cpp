#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100008

vector<int>adj[N];
int vis[N]= {0};

int n,m;
int ans=0;


int32_t main()
{
    cin>>n>>m;

    for(int i=1; i<=n; i++) cin>>cat[i];
    for(int i=1; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    return 0;
}
