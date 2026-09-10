#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 30000

vector<vector<char>> adj(MAX);

// Depth-Limited Search
bool dls(char u, char des, int limit, unordered_map<char, bool>& vis)
{
    if (limit < 0) return false;

    vis[u] = true;
    cout << u;

    if (u == des)
    {
        cout << " : Goal state found!" << endl;
        return true;
    }

    bool anyChild = false;
    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            cout << ", ";
            if (dls(v, des, limit - 1, vis))
                return true;
            anyChild = true;
        }
    }

    if (!anyChild) cout << "," << endl;
    return false;
}

// Iterative Deepening Search
bool iterativeDeepeningSearch(char src, char des, int maxDepth)
{
    for (int limit = 0; limit <= maxDepth; limit++)
    {
        cout << "\n--- Depth Limit = " << limit << " ---" << endl;
        unordered_map<char, bool> vis; // reset visited for each depth
        if (dls(src, des, limit, vis))
            return true;
    }
    cout << "Goal not found within depth limit." << endl;
    return false;
}

int32_t main()
{
    cout << "Enter number of nodes: ";
    int n;
    cin >> n;
    cout << "Enter edges: " << endl;
    for (int i = 0; i < n - 1; i++)
    {
        char u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }

    char src, des;
    int maxDepth;
    cout << "Enter source, destination, and maximum depth limit: " << endl;
    cin >> src >> des >> maxDepth;

    iterativeDeepeningSearch(src, des, maxDepth);

    return 0;
}

/*
Sample Input:
15
A B
A C
A D
A E
B F
B G
C H
D I
D J
G K
G L
I M
J N
L O
A O 4

Sample Output:
--- Depth Limit = 0 ---
A,
--- Depth Limit = 1 ---
A, B, C, D, E,
--- Depth Limit = 2 ---
A, B, F, G,
C, H,
D, I, J,
E,
--- Depth Limit = 3 ---
A, B, F, G, K, L,
C, H,
D, I, M, J, N,
E,
--- Depth Limit = 4 ---
A, B, F, G, K, L, O : Goal state found!
*/



/*
15 , 14


A B
A C
A D
A E
B F
B G
C H
D I
D J
G K
G L
I M
J N
L O

*/


/*
#include<bits/stdc++.h>
using namespace std;
vector<int> nei[1005];
bool vis[1005];
bool Dls(int src, int target, int depthLimit)
{
    if (depthLimit < 0)
    {
        return false;
    }
    if (src == target)
    {
        vis[src] = true;
        cout << char(src + 'A') << " -> ";
        return true;
    }
    vis[src] = true;
    cout << char(src + 'A') << " -> ";
    for (int adj : nei[src])
    {
        if (!vis[adj] && Dls(adj, target, depthLimit - 1))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int e = n - 1;
    for (int i = 0; i < e; i++)
    {
        char p, q;
        cin >> p >> q;
        nei[p - 'A'].push_back(q - 'A');
        nei[q - 'A'].push_back(p - 'A');
    }
    char source, target;
    int depthLimit;
    cin >> source >> target >> depthLimit;
    int src = source - 'A';
    int tgt = target - 'A';
    if (Dls(src, tgt, depthLimit))
    {
        cout << "\nTarget found within depth limit." <<
             endl;
    }
    else
    {
        cout << "\nTarget not found within depth limit." <<
             endl;
    }
    return 0;
}
*/
