#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mx 27

vector<int>adj[mx];
int vis[mx];

void bfs(int s)
{
    queue<int>q;
    q.push(s);
    vis[s] = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v: adj[u])
        {
            if(!vis[v])
            {
                vis[v]=1;
                q.push(v);
            }
        }
    }
}

int32_t main()
{
    int t;
    cin>>t;
    cin.ignore();
    cin.ignore();

    while(t--)
    {
        string lchar;
        getline(cin, lchar);
        int n = lchar[0] - 'A' + 1;

        for(int i=1; i<=n; i++)
        {
            adj[i].clear();
            vis[i] = 0;
        }

        string str;
        while(getline(cin, str) && !str.empty())
        {
            int a = str[0]-'A' + 1;
            int b = str[1]-'A' + 1;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int cnt = 0;
        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                cnt++;
                bfs(i);
            }
        }
        cout<<cnt<<endl;
        if(t) cout<<endl;
    }

    return 0;
}
