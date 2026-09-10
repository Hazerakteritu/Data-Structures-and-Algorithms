//Time Complexity: O(V+E) + O(V+E) + O(V+E) ~ O(V+E)

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj,adj_rev;
vector<bool>vis;
vector<int> order, component;

void dfs1(int u)
{
    vis[u] = true;

    for(auto v: adj[u])
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

    adj.resize(n+1);
    adj_rev.resize(n+1);

    while(m--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }
    vis.assign(n,false);

    for(int i=0; i<n; i++)
        if(!vis[i]) dfs1(i);

    vis.assign(n,false);
    reverse(order.begin(),order.end());

    int scc = 0;
    for(auto u : order)
        if(!vis[u])
        {
            scc++;
            ans.push_back(u);
            dfs2(u);

            for(int i=0; i<component.size(); i++)
            {
                cout<<component[i]<<" ";
            }
            cout<<endl;

            component.clear();
        }

    return 0;
}
