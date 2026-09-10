#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> v;

        for (int i = 0; i < m; i++)
        {
            int x, y, t;
            cin >> x >> y >> t;
            v.push_back({x, y, t});
        }

        vector<int> dis(n + 1, INT_MAX);
        dis[0] = 0;
        bool update;

        for (int i = 0; i < n - 1; i++)
        {
            update = false;
            for (auto j : v)
            {
                int x = j[0];
                int y = j[1];
                int t = j[2];
                if (dis[x] != INT_MAX && dis[x] + t < dis[y])
                {
                    dis[y] = dis[x] + t;
                    update = true;
                }
            }
            if (update == false)
            {
                break;
            }
        }

        bool f = true;
        for (auto j : v)
        {
            int x = j[0];
            int y = j[1];
            int t = j[2];
            if (dis[x] != INT_MAX && dis[x] + t < dis[y])
            {
                f = false;
                break;
            }
        }

        if (f)
        {
            cout << "possible" << endl;
        }
        else
        {
            cout << "not possible" << endl;
        }

        dis.clear();
        v.clear();
    }

    return 0;
}
