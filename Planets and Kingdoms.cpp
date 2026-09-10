#include<bits/stdc++.h>
using namespace std;
#define li long long int
#define mx 100005

vector<int> adj[mx], adj_rev[mx];
vector<bool>vis;
vector<int> order, component;
int lebel[mx];

void dfs1(int u)
{
    vis[u] = true;

    for(int v: adj[u])
        if(!vis[v])
            dfs1(v);

    order.push_back(u);
}

void dfs2(int u)
{
    vis[u] = true;
    component.push_back(u);

    for(auto v: adj_rev[u])
        if(!vis[v])
            dfs2(v);
}

int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }
    vis.assign(n,false);

    for(int i=1; i<=n; i++)
        if(!vis[i]) dfs1(i);

    int lbl = 0;

    vis.assign(n+1,false);
    reverse(order.begin(),order.end());

    for(auto u : order)
    if(!vis[u]){
        dfs2(u);
        lbl++;
        /*for(int i=0; i<component.size(); i++){
            cout<<component[i]<<" ";
        }
        cout<<endl;
        */
        for(int i=0; i<component.size(); i++){
            int v = component[i];
            lebel[v] = lbl;
        }

        component.clear();
    }

    cout<<lbl<<endl;
    for(int i=1; i<=n; i++)
        cout<<lebel[i]<<" ";

    return 0;
}
