//Topological sorting

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

vector<int>g[N];
vector<int>result;
bool visited[N];
void dfs(int vertex)
{
    visited[vertex]=1;
    for(int i=0 ; i<g[vertex].size(); i++)
    {
        int next = g[vertex][i];
        if(visited[next]==0)
        {
            dfs(next);
        }
    }
    result.push_back(vertex);
}

int main()
{
    int v,e;
    cin>>v>>e;
    for(int i=0 ; i<e ; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    //int t,y;
    //cin>>t>>y;


    for(int i=0 ; i< v ; i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
        }
    }
    reverse(result.begin(),result.end());
    //cout<<"Topological order:";
    for(int i=0 ; i<result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;

}

/*

#include<bits/stdc++.h>
using namespace std;
#define li long long int


void dfs(int s,vector<bool>&vis,vector<int>&ans,vector<int>adj[])
{
    vis[s] = true;
    for(int i=0; i<adj[s].size(); i++){
        if(!vis[i])
            dfs(i,vis,ans,adj);
    }
    ans.push_back(s);
}

void topological_sort(int n,vector<bool>&vis,vector<int>&ans,vector<int>adj[])
{
    vis.assign(n,false);
    ans.clear();
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i,vis,ans,adj);
        }
    }
    reverse(ans.begin(),ans.end());

}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    vector<bool>vis;
    vector<int>ans;

    for(int i=1; i<=m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    topological_sort(n,vis,ans,adj);

    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
*/

