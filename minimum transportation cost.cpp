#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define mx 10005
#define INF 1e18

vector<pii>adj[mx];

int dijkstra(int s, int des, int n)
{
    vector<int>dist(n+1, INF);
    priority_queue< pii, vector<pii>, greater<pii> > pq;
    pq.push({0,s});
    dist[s]=0;

    while(!pq.empty()){
        int u = pq.top().second;
        int uw = pq.top().first;
        pq.pop();
        if(u == des) return dist[u];

        for(auto edges: adj[u]){
            int v = edges.first;
            int w = edges.second;

            if(dist[v]> w + uw){
                dist[v]= w + uw;
                pq.push({dist[v], v});
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        unordered_map<string,int>mp;
        for(int i=1; i<=n; i++)
        {
            string str;
            cin>>str;
            mp[str] = i;
            int p;
            cin>>p;
            while(p--){
                int v,cost;
                cin>>v>>cost;
                adj[i].push_back({v,cost});
            }
        }
        int r;
        cin>>r;
        while(r--)
        {
            string str1,str2;
            cin>>str1>>str2;
            int a,b;
            a = mp[str1];
            b = mp[str2];
            cout<<dijkstra(a,b,n)<<endl;
        }
        for(int i=1; i<=n; i++) adj[i].clear();
    }


    return 0;
}

