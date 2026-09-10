//find the farthest nodes in the tree.

#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000

vector<int>adj[30000];
vector<int>weight[30000];
int n,vis[30000];
int dis[30000];

void bfs(int s)
{
    memset(vis, 0, sizeof(vis));
    memset(dis, inf, sizeof(dis));

    queue<int>Q;
    Q.push(s);
    vis[s] = 1;
    dis[s] = 0;

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(vis[v]==0)
            {
                vis[v] = 1;
                dis[v] = dis[u] + weight[u][i];
                Q.push(v);
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
        cin>>n;
        for(int i=0; i<n-1; i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back(v);
            adj[v].push_back(u);
            weight[u].push_back(w);
            weight[v].push_back(w);
        }
        bfs(0); //for find farthest node
        int mxdis=0,strt=0;
        for(int i=0; i<n; i++)
        {
            if(dis[i]>mxdis)
            {
                strt=i;
                mxdis=dis[i];
            }
        }
        //for find another farthest node from strt
        bfs(strt);
        mxdis=0; int src1;
        for(int i=0; i<n; i++)
        {
            if(dis[i]>mxdis)
                mxdis=dis[i];
        }

        cout<<"Case "<<tt<<": "<<mxdis<<endl;

        for(int i=0; i<n; i++)
        {
            adj[i].clear();
            weight[i].clear();
        }
    }
}

