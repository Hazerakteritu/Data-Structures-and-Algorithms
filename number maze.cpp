#include <bits/stdc++.h>

using namespace std;

bool isvalid(int x, int y, int n, int m)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>>val(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> val[i][j];
            }
        }

        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        res[0][0] = val[0][0];

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({val[0][0], {0, 0}});

        while (!pq.empty())
        {
            auto [dist, xy] = pq.top();
            pq.pop();

            int x = xy.first;
            int y = xy.second;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (isvalid(nx, ny, n, m) && res[nx][ny] > res[x][y] + val[nx][ny])
                {
                    res[nx][ny] = res[x][y] + val[nx][ny];
                    pq.push({res[nx][ny], {nx, ny}});
                }
            }
        }

        cout << res[n - 1][m - 1] << endl;
    }

    return 0;
}
