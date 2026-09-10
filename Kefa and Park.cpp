#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100005

int n,m, ans =0;
int a[N];
vector<int>adj[N];

void dfs(int u, int p, int concat, int mxC)
{
    if(a[u]) concat++;
    else concat = 0;    //consecutive cat

    mxC = max(concat, mxC); //maximum consecutive cat

    int node = 0;
    for(auto v: adj[u])
    {
        if(v!= p){
            dfs(v, u, concat, mxC);
            node++;
        }
    }

    if(node == 0 && mxC <= m) ans++;
}


int32_t main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];

    for(int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0, 0);
    cout<<ans<<endl;

    return 0;
}
