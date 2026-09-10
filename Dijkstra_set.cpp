//Dijkstra using set
//takeuforward
//find shortest dist of all the vertics form the source vertex
//Function to find the shortest distance of all the vertices
//from the source vertex S.
//Comparison b/w PQ and set :
//Incase of PQ, the maximum heap size can go upto E = number of edges, leading to complexity = O(E*logE).
//Incase of set, the maximum set size can go upto V =. number of vertices, leading to complexity = O(E*logV).

#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define pii pair<int,int>

vector <int> dijkstra(int V, vector<vector<pii>>&adj, int S)
{
    set<pair<int,int>> st;
    vector<int> dist(V, 1e9);
    st.insert({0, S});
    dist[S] = 0;

    while(!st.empty())
    {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for(auto it : adj[node])
        {
            int adjNode = it.first;
            int edgW = it.second;

            if(dis + edgW < dist[adjNode])
            {
                // erase if it was visited previously at a greater cost.
                if(dist[adjNode] != 1e9)
                    st.erase({dist[adjNode], adjNode});

                dist[adjNode] = dis + edgW;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main()
{
    int n,m,a,b,w;
    cin>>n>>m;

    vector<vector<pii>>adj(n);
    while(m--)
    {
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    int sourse;
    cin>>sourse;

    vector<int> dist = dijkstra( n, adj, sourse);

    for(int i=1; i<=n; i++) cout<<dist[i]<<" ";


    return 0;
}
