#include<bits/stdc++.h>
using namespace std;

vector<int>adj[1000];
vector<int>weight[1000];
int dis[100];

void bfs(int n)
{
    for(int i=0; i<100; i++) dis[i]=INT_MAX;
    queue<int>q;
    q.push(0);
    dis[0] = 0; //source node distace = 0

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            int vw = weight[u][i] + dis[u];

            if(dis[v]> vw)
            {
                dis[v] = vw;
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
        int n,e;
        cin>>n>>e;

        for(int i=0; i<e; i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            weight[u].push_back(w);
            weight[v].push_back(w);
        }
        bfs(n);

        cout<<"Case "<<tt<<": ";
        if(dis[n-1]==INT_MAX) cout<<"Impossible"<<endl;
        else cout<<dis[n-1]<<endl;

        for(int i=0; i<n; i++)
        {
            adj[i].clear();
            weight[i].clear();
        }

    }


    return 0;
}

