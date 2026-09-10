#include<bits/stdc++.h>
using namespace std;
#define li long long int

const int inf = 1e7;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<vector<pair<int,int>>>graph(n+1);
        vector<int>dist(n+1,inf);

        while(k--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            graph[u].push_back({v,w});
            //graph[v].push_back({u,w});
        }
        int ss,d ;
        cin>>ss>>d;
        dist[ss] = 0;
        set<pair<int,int>>s;
        s.insert({0,ss});

        while(!s.empty())
        {
            auto x = *(s.begin());

            s.erase(x);

            for(auto it: graph[x.second])
            {
                if(dist[it.first] > dist[x.second]+ it.second)
                {
                    s.erase({dist[it.first],it.first});
                    dist[it.first] = dist[x.second]+ it.second;

                    s.insert({dist[it.first],it.first});
                }
            }
        }
        if(dist[d]>=inf) cout<<"NO"<<endl;
        else cout<<dist[d]<<endl;

        //for(long long i = 1; i <= nodes; i++) adj[i].clear();

    }

    return 0;
}
