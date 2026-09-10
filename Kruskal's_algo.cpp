#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 1e5 + 10;

ll parent[N], sz[N]; //sz -> size
void make(ll v){
    parent[v] = v;
    sz[v] = 1;
}
ll find(ll v){
    if(parent[v] == v)
        return parent[v];
    return parent[v] = find(parent[v]);
}

void Union(ll a, ll b)
{
    a = find(a);
    b = find(b);
    if(a!=b){
        if(sz[a] < sz[b])
            swap(a,b);
        parent[b] = a;
        sz[a]+= sz[b];
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair< ll, pair<ll,ll> > > edges;
    for(int i=0; i<m; i++){
        ll u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({ wt, {u, v} });
    }
    sort(edges.begin(), edges.end());

    for(ll i=1; i<=n; ++i) make(i);

    ll total_cost = 0;
    for(auto edge: edges){
        ll wt = edge.first;
        ll u = edge.second.first;
        ll v = edge.second.second;
        if(find(u) == find(v)) continue;
        Union(u,v);
        total_cost+= wt;
        n--;
    }
    if(n == 1) cout<<total_cost<<endl;
    else cout<<"IMPOSSIBLE"<<endl;

    return 0;
}
