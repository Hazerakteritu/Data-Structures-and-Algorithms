#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
{
    // Code here
    //vector<vector<int>> ans = vector<vector<int>> image;
    int n = image.size();
    int m = image[0].size();

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int,int>>q;
    q.push({sr,sc});
    vis[sr][sc] = 1;

    int precolor = image[sr][sc];
    image[sr][sc] = newColor;

    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {

            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && image[nrow][ncol] == precolor)
            {
                vis[nrow][ncol] = 1;
                image[nrow][ncol] = newColor;
                q.push({nrow, ncol});
            }

        }
    }
    return image;
}
