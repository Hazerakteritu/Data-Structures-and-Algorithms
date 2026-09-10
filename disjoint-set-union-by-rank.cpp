#include <bits/stdc++.h>
using namespace std;

vector<int> rnk, parent;
void DisjointSet(int n)
{
    rnk.resize(n + 1, 0);
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
}

int findUPar(int node)
{
    if (node == parent[node])
        return node;
    return parent[node] = findUPar(parent[node]);
}

void unionByRank(int u, int v)
{
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v) return;
    if (rnk[ulp_u] < rnk[ulp_v])
    {
        parent[ulp_u] = ulp_v;
    }
    else if (rnk[ulp_v] < rnk[ulp_u])
    {
        parent[ulp_v] = ulp_u;
    }
    else
    {
        parent[ulp_v] = ulp_u;
        rnk[ulp_u]++;
    }
}

int main()
{
    DisjointSet(7);
    unionByRank(1, 2);
    unionByRank(2, 3);
    unionByRank(4, 5);
    unionByRank(6, 7);
    unionByRank(5, 6);
    // if 3 and 7 same or not
    if (findUPar(3) == findUPar(7))
    {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    unionByRank(3, 7);

    if (findUPar(3) == findUPar(7))
    {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}
