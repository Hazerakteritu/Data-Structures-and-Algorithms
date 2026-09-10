//Time Complexity: O(V+E) + O(V+E) + O(V+E) ~ O(V+E)

#include <bits/stdc++.h>
using namespace std;


void dfs(int node, vector<vector<int>>&adj, vector<int>&vis, stack<int>&st)
{
    vis[node]=1;

    for(auto it: adj[node])
    {
        if(!vis[it])
            dfs(it, adj, vis, st);
    }
    st.push(node);
}

void dfs2(int node, vector<vector<int>>&adjT, vector<int>&vis)
{
    vis[node] =  1;
    for(auto it: adjT[node])
    {
        if(!vis[it])
        {
            dfs2(it, adjT, vis);
        }
    }
}

//Function to find number of strongly connected components in the graph.
void kosaraju(int V, vector<vector<int>>&adj)
{
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }

    vector<vector<int>>adjT(V);
    for (int i = 0; i < V; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            // i -> it
            // it -> i
            adjT[it].push_back(i);
        }
    }
    int scc = 0;
    vector<int>ans;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            scc++;
            ans.push_back(node+1);

            dfs2(node, adjT, vis);
        }
    }
    if(scc>=2){
        cout<<"NO"<<endl;
        cout<<ans[1]<<" "<<ans[0]<<endl;
    }else cout<<"YES"<<endl;

    return ;
}


int main()
{
    int t = 1;
    //cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        vector<vector<int>>adj(n);
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].push_back(v);
        }
        kosaraju( n, adj);
    }

    return 0;
}
