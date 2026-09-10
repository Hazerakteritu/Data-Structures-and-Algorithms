#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> in, res;

void toposort(int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        if (in[i] == 0)
        {
            pq.push(i);
        }
    }

    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        res.push_back(cur);

        for (int child : graph[cur])
        {
            in[child]--;
            if (in[child] == 0)
            {
                pq.push(child);
            }
        }
    }
}

int main()
{

    int cs = 0;

    while (1)
    {
        int n;
        if(!(cin>>n)) break;
        cin.ignore();

        cs++;
        map<string, int> mp1;
        map<int, string> mp2;

        for (int i = 0; i < n; i++)
        {
            string beverage;
            getline(cin, beverage);
            mp1[beverage] = i;
            mp2[i] = beverage;
        }

        int m;
        cin >> m;

        graph.assign(n, vector<int>());
        in.assign(n, 0);
        res.clear();

        for (int i = 0; i < m; i++)
        {
            string b1, b2;
            cin >> b1 >> b2;
            int u = mp1[b1];
            int v = mp1[b2];
            graph[u].push_back(v);
            in[v]++;
        }

        toposort(n);

        cout << "Case #" << cs << ": Dilbert should drink beverages in this order:";
        for (int i = 0; i < res.size(); i++)
        {
            cout << " " << mp2[res[i]];
        }
        cout << ".\n\n";
    }

    return 0;
}
