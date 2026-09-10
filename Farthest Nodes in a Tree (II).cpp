#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000

vector<int>adj[30000];
vector<int>weight[30000];
int n,visited[30000];
int dis1[30000];
int dis2[30000];

void bfs(int s)
{
    for(int i=0; i<n; i++)
    {
        visited[i]=0;
        dis1[i]=inf;
    }
    queue<int>Q;
    Q.push(s);
    visited[s] = 1;
    dis1[s] = 0;

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(visited[v]==0)
            {
                visited[v] = 1;
                dis1[v] = dis1[u] + weight[u][i];
                Q.push(v);
            }
        }
    }
}

void bfs1(int s)
{
    for(int i=0; i<n; i++)
    {
        visited[i]=0;
        dis2[i]=inf;
    }
    queue<int>Q;
    Q.push(s);
    visited[s] = 1;
    dis2[s] = 0;

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(visited[v]==0)
            {
                visited[v] = 1;
                dis2[v] = dis2[u] + weight[u][i];
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
        int mxdis=0,strt;
        for(int i=0; i<n; i++)
        {
            if(dis1[i]>mxdis)
            {
                strt=i;
                mxdis=dis1[i];
            }
        }
        //for find another farthest node from star
        bfs(strt);
        mxdis=0; int src1;
        for(int i=0; i<n; i++)
        {
            if(dis1[i]>mxdis)
            {
                src1=i;
                mxdis=dis1[i];
            }
        }
        bfs1(src1);

        //mxdis=0;
        //for(int i=0; i<n; i++)
          //  if(dis[i]>mxdis) mxdis=dis[i];
        //for(int i=0; i<n; i++) cout<<dis[i]<<" ";
        //cout<<endl;

        cout<<"Case "<<tt<<":"<<endl;
        //adj.clear();
        //weight.clear();
        for(int i=0; i<n; i++)
        {
            cout<<max(dis1[i],dis2[i])<<endl;
            adj[i].clear();
            weight[i].clear();
        }
    }
}

