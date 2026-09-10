#include<bits/stdc++.h>
using namespace std;
#define maxN 2005

vector<int>adjlist[maxN];
int n,path;

int bfs(int s)
{
    bool vis[maxN]= {0};
    queue<pair<int,int>>q;
    //vis[s] = 1;
    q.push(make_pair(0,s));

    while(!q.empty())
    {
        int u = q.front().second;
        int dis = q.front().first;
        q.pop();

        for(int i=0; i<adjlist[u].size(); i++)
        {
            int v = adjlist[u][i];

            if(vis[v]==0)
            {
                vis[v] = 1;
                //dis++;
                if(v == s)
                    return dis+1;

                q.push(make_pair(dis+1,v));
            }
        }
    }
    return -1;
}

int main()
{
    cin>>n;
    int adjM[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>adjM[i][j];

    //adjmatrix to adjList
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(adjM[i][j]!=0)
                adjlist[i].push_back(j);
        }

    for(int i=0; i<n; i++)
    {
        int path = -1;

        if(adjlist[i].size()){
            path = bfs(i);
        }

        if(path!= -1) cout<<path<<endl;
        else cout<<"NO WAY"<<endl;
    }

    return 0;
}
