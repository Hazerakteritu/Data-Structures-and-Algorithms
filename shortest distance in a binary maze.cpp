//https://takeuforward.org/data-structure/g-36-shortest-distance-in-a-binary-maze/
//Shortest Distance in a Binary Maze

#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
{
    if (source.first == destination.first && source.second == destination.second)
        return 0;

    // in the form {dist,{cell coordinates pair}}.
    queue<pair<int, pair<int, int>>> q;
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 1e9));  //2D
    dist[source.first][source.second] = 0;
    q.push({0, {source.first, source.second}});

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;

        for (int i = 0; i < 4; i++)
        {
            int newr = r + dr[i];
            int newc = c + dc[i];

            if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc])
            {
                dist[newr][newc] = 1 + dis;

                if (newr == destination.first && newc == destination.second)
                    return dis + 1;
                q.push({1 + dis, {newr, newc}});
            }
        }
    }
    // If no path is found from source to destination.
    return -1;
}


int main()
{
    // Driver Code.

    pair<int, int> source, destination;
    source.first = 0;
    source.second = 1;
    destination.first = 2;
    destination.second = 2;

    vector<vector<int>> grid = {{1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
        {1, 0, 0, 1}
    };

    int res = shortestPath(grid, source, destination);

    cout << res;
    cout << endl;

    return 0;
}
