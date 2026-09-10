//Find shortest path between the vertex 1 and the vertex n.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define INF 1e18
#define mx 1000000004


int32_t main()
{
    int t = 1;
    cin>>t;

    while(t--)
    {

        int n,m;
        cin>>n>>m;

        int arr[n];
        map<int,int>vis;
        queue<int>q;


        for(int i=0; i<n; i++)
        {
            cin>>arr[i];

            vis[arr[i]] = 1;
            q.push(arr[i]);
        }



        vector<vector<pii>>adj;

        while(m--)
        {
            int a,b,w;
            cin>>a>>b>>w;
            adj[a].push_back({b, w});
            adj[b].push_back({a,w});
        }


        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            for(auto [v, z]: adj[u])
            {
                if(vis[v] == 1)
                {
                    vis[z] = 1;
                    q.push(z);
                }
            }
        }

        cout<<vis.size()<<endl;
    }


    return 0;
}
