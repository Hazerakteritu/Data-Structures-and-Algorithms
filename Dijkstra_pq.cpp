//Dijkstra using Priority Queue
//CodeNCode
//single source shortest path

#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define pii pair<int,int>

vector<pii>adj[1001];

int main()
{
    int n,m,a,b,w;
    cin>>n>>m;

    while(m--)
    {
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    priority_queue< pii, vector<pii>, greater<pii> > pq;

    vector<int>dist(n+1, INF);
    pq.push({0,1}); //source Node 1; {weight, source node}
    dist[1]=0;

    while(!pq.empty())
    {
        int curr = pq.top().second;
        int c_dis = pq.top().first;
        pq.pop();

        for(pair<int,int>edges: adj[curr])
        {
            if(c_dis + edges.second < dist[edges.first])
            {
                dist[edges.first] = c_dis + edges.second;
                pq.push({dist[edges.first],edges.first});
            }
        }
    }
    for(int i=1; i<=n; i++) cout<<dist[i]<<" ";


    return 0;
}
