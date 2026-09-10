#include<bits/stdc++.h>
using namespace std;

vector<int>adj[510];
vector<int>cost[510];
int dis[510];
int n;

void bfs(int s)
{
    //for(int i=0; i<sizeof(dis); i++) dis[i]=INT_MAX;
    for(int i=0; i<n; i++) dis[i]=INT_MAX;
    queue<int>q;
    q.push(s);
    dis[s]=0;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            int temp = max(dis[u], cost[u][i]);
            if(temp < dis[v])
            {
                dis[v] = temp;
                q.push(v);
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int tt=1; tt<=t; tt++)
    {
        int m;
        cin>>n>>m;

        for(int i=0; i<m; i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        int s;
        cin>>s;

        bfs(s);
        cout<<"Case "<<tt<<":"<<endl;
        for(int i=0; i<n; i++)
        {
            if(dis[i]==INT_MAX)cout<<"Impossible"<<endl;
            else cout<<dis[i]<<endl;
        }
        for(int i=0; i<n; i++)
        {
            adj[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
