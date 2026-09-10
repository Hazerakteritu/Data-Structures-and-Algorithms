#include<bits/stdc++.h>
using namespace std;

const int N=400100;

struct edge
{
    int u,v,d,id;
    bool operator < (const edge&x)const
    {
        return d<x.d;
    }
} egs[N];

int fg[N],ans[N],xb,G[N],to[N],ne[N],par[N],da[N],sz[N],fat[N],dp[N],pp[N],n,m,up[N];


int find(int x)
{
    if( par[x]==x)
        return x;
    else
        return  find(par[x]);
}

int find2(int x)
{
    return par[x]==x?x:par[x]=find2(par[x]);
}

void dfs(int x)
{
    for(int i=G[x]; ~i; i=ne[i])
        if(to[i]!=fat[x])
        {
            fat[to[i]]=x;
            pp[to[i]]=da[i];
            dp[to[i]]=dp[x]+1;
            dfs(to[i]);
        }
}

void add(edge x)
{
    ne[xb]=G[x.u];
    to[xb]=x.v;
    da[xb]=x.id;
    G[x.u]=xb++;
    ne[xb]=G[x.v];
    to[xb]=x.u;
    da[xb]=x.id;
    G[x.v]=xb++;
}

int main()
{
    cin>>n>>m;
    memset(G,-1,sizeof G);
    for(int i=1; i<=m; i++)
    {
        cin>>egs[i].u>>egs[i].v>>egs[i].d;
        egs[i].id=i;
    }
    sort(egs+1,egs+m+1);
    for(int i=1; i<=n; i++)par[i]=i,sz[i]=1,up[i]=INT_MAX;
    for(int i=1; i<=m; i++)
    {
        int x=find(egs[i].u),y=find(egs[i].v);
        if(x!=y)
        {
            if(sz[x]>sz[y])swap(x,y);
            par[x]=y;
            sz[y]+=sz[x];
            up[x]=egs[i].d;
            add(egs[i]);
        }
        else
        {
            int u=egs[i].u,v=egs[i].v;
            for(; u!=v; u=par[u])
            {
                if(up[u]>up[v])swap(u,v);
                ans[egs[i].id]=max(ans[egs[i].id],up[u]);
            }
            fg[i]=1;
        }
    }
    dfs(1);
    for(int i=1; i<=n; i++)par[i]=i;
    for(int i=1; i<=m; i++)
        if(fg[i])
        {
            int x=egs[i].u,y=egs[i].v;
            for(; find2(x)!=find2(y);)
            {
                if(dp[find2(x)]<dp[find2(y)])swap(x,y);
                x=find2(x);
                ans[pp[x]]=egs[i].d;
                par[x]=fat[x];
            }
        }
    for(int i=1; i<=m; i++)printf("%d%c",ans[i]-1,i==m?10:32);
    return 0;
}
