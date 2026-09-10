#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int dist[1001][1001];
int n,m;
int vis[1001][1001];

bool isValid(int x,int y)
{
    if(x<1 || x>n || y<1 || y>m) return false;

    if(vis[x][y]== 1) return false;

    return true;
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int sx, int sy)
{
    queue<pii>q;
    q.push({sx,sy});
    vis[sx][sy] = 1;
    dist[sx][sy]=0;

    while(!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;

        for(int i=0; i<4; i++)
        {
            int newx = cx + dx[i];
            int newy = cy + dy[i];

            if(isValid(newx, newy))
            {
                q.push({newx, newy});
                vis[newx][newy] = 1;
                dist[newx][newy] = dist[cx][cy] + 1;
            }
        }
        cout<<"Distance";
        for(int i=1; i<=n; i++) cout<<dist[i]<<" ";
    }
}
int main()
{
    cin>>n>>m;
    int x,y;
    cin>>x>>y;
    bfs(x,y);

    return 0;
}





/*|2|2|2|2|3|
  |1|1|1|2|3|
  |1|0|1|2|2|
  |1|1|1|2|3|
*/





