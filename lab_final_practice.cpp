#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi pair<int,int>
#define pll pair<ll,ll>
#define mxn 100006

vector<pll>adj[mxn];
ll dist[mxn];
vector<ll>ans;
int n,m,k;
queue<ll>q;
int vis[mxn] = {0};

void dfs(int s)
{
    if(s == n){
        ans.push_back(dist[s]);
        return;
    }
    dist[1] = 0;
    vis[s] = 1;

    while(!q.empty())
    {
        int u = q.front();

        for(auto it: adj[u]){
            int v = it.first;
            int vw = it.second;

            if(!vis[v]){
                dist[v] = dist[u] + vw;
                vis[v] = 1;
                q.push(v);
                dfs(v);
                vis[v] = 0;
            }
        }
    }
    vis[s] = 0;
}

int main()
{
    //int n,m,k;
    cin>>n>>m>>k;

    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    q.push(1);

    dfs(1);
    sort(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
