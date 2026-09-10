#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;

ll const maxn=1e5+10, mod=1e9+7, INF=1e18, LOG=30, sq=65;

ll poww(ll a, ll b, ll mod)
{
    if (b == 0) return 1;
    return 1 * poww(1 * a * a % mod, b / 2, mod) * ((b % 2 == 1) ? a : 1) % mod;
}


int n, h[maxn], par[LOG][maxn], stt[maxn], timer, ver[maxn];
vector<pii> g[maxn];
set<int> st;
ll dis[maxn], ans;

void DFS(int v, int p=0)
{
    stt[v]=++timer;
    ver[stt[v]]=v;
    for(auto [u, w]:g[v])
    {
        if(u==p) continue;
        h[u]=h[v]+1;
        dis[u]=dis[v]+w;
        par[0][u]=v;
        DFS(u, v);
    }
}

void Set_Par()
{
    for(int i=1; i<LOG; i++)
    {
        for(int j=1; j<=n; j++)
        {
            par[i][j]=par[i-1][par[i-1][j]];
        }
    }
}

int Jump(int v, int k)
{
    for(int i=LOG-1; i>=0; i--)
    {
        if(k&(1<<i)) v=par[i][v];
    }
    return v;
}

int LCA(int v, int u)
{
    if(h[v]<h[u]) swap(v, u);
    v=Jump(v, h[v]-h[u]);
    if(v==u) return v;
    for(int i=LOG-1; i>=0; i--)
    {
        if(par[i][v]!=par[i][u]) v=par[i][v], u=par[i][u];
    }
    return par[0][v];
}

ll Calc(int v, int u)
{
    int lca=LCA(v, u);
    return dis[v]+dis[u]-2*dis[lca];
}

void Add(int v)
{
    st.insert(stt[v]);
    auto t=st.find(stt[v]);
    auto prv=t, nxt=t;
    if(t==st.begin()) prv=prev(st.end());
    else prv=prev(t);
    nxt=next(t);
    if(nxt==st.end()) nxt=st.begin();
    int a=ver[*prv], b=ver[*nxt];
    ans+=Calc(a, v)+Calc(v, b)-Calc(a, b);
}

void Del(int v)
{
    auto t=st.find(stt[v]);
    auto prv=t, nxt=t;
    if(t==st.begin()) prv=prev(st.end());
    else prv=prev(t);
    nxt=next(t);
    if(nxt==st.end()) nxt=st.begin();
    int a=ver[*prv], b=ver[*nxt];
    ans-=(Calc(a, v)+Calc(v, b)-Calc(a, b));
    st.erase(stt[v]);
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1; i<n; i++)
    {
        int v, u, w;
        cin>>v>>u>>w;
        g[v].pb({u, w});
        g[u].pb({v, w});
    }

    DFS(1);
    Set_Par();

    int q;
    cin>>q;
    while(q--)
    {
        char t;
        cin>>t;
        if(t=='?')
        {
            cout<<(ans/2)<<"\n";
        }
        else if(t=='+')
        {
            int v;
            cin>>v;
            Add(v);
        }
        else
        {
            int v;
            cin>>v;
            Del(v);
        }
    }
}

