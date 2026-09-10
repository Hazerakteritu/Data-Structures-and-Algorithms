#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
typedef long long ll;
#define mx 200

struct Edge
{
    int  st;
    int en;
    int w;
} ;
vector<int>second;
Edge edge[mx+5];
bool inmst[mx+5];
bool insmst[mx+5];
int nodes,e;
int pre[mx+5];

bool comp(Edge a,Edge b)
{
    return a.w < b.w;
}
int findPre(int u)
{
    if(pre[u]==u)return u;
    else return pre[u] = findPre(pre[u]);
}
void resetPre()
{
    for(int i=1; i<=nodes; i++)
        pre[i] = i;
}
void secondMST(int offEdge)
{
    int taknene=0,smstw=0;
    resetPre();
    for(int i=0; i<e; i++)
    {
        if(i==offEdge) continue; //skip this edge
        int stp,enp;
        stp = findPre(edge[i].st);
        enp = findPre(edge[i].en);
        if(stp!=enp )
        {
            smstw +=edge[i].w;
            pre[stp] = enp;
            taknene++;
        }
    }
    if(taknene==nodes-1)second.push_back(smstw);
}
int main()
{
    int i,takene,t;
    int mstw;
    cin>>t;
    for(int cs = 1; cs<=t; cs++)
    {
        cin>>nodes>>e;

        for(i=0; i<e; i++)
        {
            int u,v,c;
            cin>>u>>v>>c;
            edge[i].st = u;
            edge[i].en = v;
            edge[i].w = c;

            inmst[i] = false;
        }
        sort(edge,edge+e,comp);
        resetPre();
        mstw = takene= 0;

        for(i=0; i<e; i++)
        {
            int stp,enp;
            stp = findPre(edge[i].st);
            enp = findPre(edge[i].en);
            if(stp!=enp)
            {
                mstw +=edge[i].w;
                pre[stp] = enp;
                inmst[i]=true;
                takene++;
            }
        }
        cout<<"Case #"<<cs<<" : ";

        if(takene!=nodes-1)
        {
            cout<<"No way"<<endl;
            continue;
        }
        second.clear();
        for(i=0; i<e; i++)
            if(inmst[i])
                secondMST(i);

        if(second.size()==0)
            cout<<"No second way";
        else
        {
            sort(second.begin(),second.end());
            cout<<second[0];
        }
        cout<<endl;
    }
    return 0;
}
