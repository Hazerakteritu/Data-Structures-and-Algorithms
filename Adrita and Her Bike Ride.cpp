#include<bits/stdc++.h>
using namespace std;
const int INF = LLONG_MAX;
#define mx 10000010
#define li long long int
#define endl "\n"

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        li n,m,ss,des;
        cin>>n>>m>>ss>>des;

        vector<li>dist(n+1,INF);
        vector<vector<pair<li,li>>>graph(n+1);
        while(m--)
        {
            li u,v,w;
            cin>>u>>v>>w;
            //w+=12;
            bool edgeExists = false;
            for(auto &p: graph[u])
            {
                if(p.first == v)
                {
                    p.second = min(p.second, w);
                    edgeExists = true;
                    break;
                }
            }

            if(!edgeExists)
            {
                graph[u].push_back({v,w});
                graph[v].push_back({u,w});
            }
        }

        dist[ss] = 0;
        set<pair<li,li>>s;
        s.insert({0,ss});

        while(!s.empty())
        {
            auto x = (*s.begin());

            s.erase(x);

            for(auto it: graph[x.second])
            {
                if(dist[it.first] > dist[x.second]+ it.second +12)
                {
                    s.erase({dist[it.first],it.first});
                    dist[it.first] = dist[x.second]+ it.second +12;

                    s.insert({dist[it.first],it.first});
                }
            }
        }
        cout<<dist[des]<<endl;
    }
    return 0;
}
