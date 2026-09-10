#include<bits/stdc++.h>
using namespace std;
#define int long long

char adj[102][102];
int n,m;

int dx[8]= {0, 0, 1,-1, 1, 1, -1,-1};
int dy[8]= {1,-1, 0, 0, 1,-1, -1, 1};

void dfs(int i,int j)
{
    if(i<0 || i>n || j<0 || j>m)
    {
        return;
    }
    if(adj[i][j]!='@')
    {
        return;
    }
    adj[i][j]='*';
    for(int k=0; k<8; k++)
    {
        int newi = i+ dx[k];
        int newj = j+ dy[k];

        dfs(newi, newj);
    }
}

int32_t main()
{
    while(cin>>n>>m && n!=0)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>adj[i][j];
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(adj[i][j]=='@')
                {
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
}
