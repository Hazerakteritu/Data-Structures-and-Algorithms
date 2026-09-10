//Minimum Spanning Tree
//Prim's Algorithm - CodeHelp by babbar
//Given a weighted, undirected graph G with n vertices and m edges
//find a spanning tree of this graph which connects all vertices and has the least weight

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int n,m;
    cin>>n>>m;
    //create adjacency list
    unordered_map<int,list<pair<int,int>>>adj;
    //vector<vector<pair<int, int>>> adj;
    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int>key(n+1); //distance or weight or cost
    vector<bool>mst(n+1);  //visited
    vector<int>parent(n+1);

    for(int i=0; i<=n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }
    //Let's start the algo
    key[1] = 0;
    parent[1] = -1;

    for(int i=1; i<n; i++)
    {
        int mini = INT_MAX;
        int u;

        //find the u with minimum value
        for(int v=1; v<=n; v++)
        {
            if(mst[v]== false && key[v]< mini)
            {
                mini = key[v];
                u = v;
            }
        }
        //mark min node as true
        mst[u] = true;
        //check its adj list
        for(auto it: adj[u])
        {
            int v = it.first;
            int w = it.second;

            if(mst[v]==false && w<key[v])
            {
                key[v] = w;
                parent[v] = u;
            }
        }
        //result mst
        // vector<pair<int,int>,int>result; //{{parent, node},cost}

    }
    for(int i=2; i<=n; i++)
    {
        //  result.push_back({{parent[i],i}, key[i]});
        cout<<parent[i]<<" -> "<<i<<" = "<<key[i]<<endl;
    }


    return 0;
}

//Input:
/*
5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4
*/
//output
// parent -> node = cost
