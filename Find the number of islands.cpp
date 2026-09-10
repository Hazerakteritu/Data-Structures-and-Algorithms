#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

//8 directions
void bfs(int x, int y, vector<vector<char>> &grid, vector<vector<int>> &vis)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int,int>>q;
    q.push({x, y});
    vis[x][y] = 1;

    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i = -1; i<=1; i++)
        {
            for(int j = -1; j<=1; j++)
            {
                int newr = row + i;
                int newc = col + j;
                if(newr>=0 && newr<n && newc >=0 && newc<m && grid[newr][newc]=='1' && !vis[newr][newc])
                {
                    vis[newr][newc] = 1;
                    q.push({newr, newc});
                }
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    //int vis[n][m] = {0};
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if( !vis[i][j] && grid[i][j] == '1')
            {
                cnt++;
                bfs( i, j, grid, vis);
            }
        }
    }
    return cnt;
}

int32_t main()
{


    return 0;
}
