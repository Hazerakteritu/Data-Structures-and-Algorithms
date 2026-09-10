#include<bits/stdc++.h>
using namespace std;

char str[40][40];
int control_x[4] = {0,0,1,-1};
int control_y[4] = {1,-1,0,0};
int mark[40][40],fx,fy,m,n,ans=0;

void dfs(int x,int y,int k)
{
    if(x==fx && y==fy && k>=0)
    {
        ans = 1;
        return;
    }
    for(int i=0; i<4; i++)
    {
        int next_x = x + control_x[i];
        int next_y = y + control_y[i];

        if(next_x<0 || next_x >=n || next_y<0 || next_y>=m || mark[next_x][next_y]==1 || str[next_x][next_y]=='#') continue;
        if(str[next_x][next_y]=='s')
        {
            mark[next_x][next_y] = 1;
            dfs(next_x,next_y,k-1);
            mark[next_x][next_y] = 0;
        }
        else
        {
            mark[next_x][next_y] = 1;
            dfs(next_x, next_y, k);
            mark[next_x][next_y]= 0;
        }
    }
}

int main()
{
    int j,sx,sy;
    cin>>n>>m>>j;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>str[i][j];

            if(str[i][j] == '@')
            {
                sx = i;
                sy = j;
            }

            if(str[i][j] == 'x')
            {
                fx = i;
                fy = j;
            }
        }
    }
    mark[sx][sy] = 1;
    dfs(sx,sy,j/2);

    if(ans==1) cout<<"SUCCESS"<<endl;
    else cout<<"IMPOSSIBLE"<<endl;

    return 0;
}
