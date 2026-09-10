// Best Picnic Ever - LightOJ - 1111


#include<bits/stdc++.h>
using namespace std;

int person[100],cnt[1009],vs[1009],ans,k;
vector<int>adj[1009];

void bfs(int s)
{
    memset(vs,0,sizeof(vs));
    //for(int i=0; i<=n; i++) vs[i]=0;
    vs[s]=1;
    queue<int>q;
    q.push(s);
    cnt[s]++;
    if(cnt[s]==k) ans++;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int j=0; j<adj[x].size(); j++){
            int y = adj[x][j];
            if(vs[y]==0){
                q.push(y);
                vs[y] = 1;
                cnt[y]++;
                if(cnt[y]==k) ans++;
            }
        }
    }

}

int main()
{
    int t;
    cin>>t;
    for(int tt=1; tt<=t; tt++)
    {
        int n,m,u,v;
        cin>>k>>n>>m;

        for(int i=0; i<k; i++)
        {
            cin>>person[i];
        }
        for(int i=1; i<=m; i++){
            cin>>u>>v;
            adj[u].push_back(v);
        }
        memset(cnt,0,sizeof(cnt));
        ans=0;

        for(int i=0; i<k; i++){
            bfs(person[i]);
        }
        //int ans=0;
        /*for(int i=1; i<=n; i++){
            if(cnt[i]==k) ans++;
        }*/
        cout<<"Case "<<tt<<": "<<ans<<endl;
        for(int i=0; i<=n; i++) adj[i].clear();
    }

    return 0;
}
