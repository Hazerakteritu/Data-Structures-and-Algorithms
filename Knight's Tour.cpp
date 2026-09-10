#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

const int N = 8;
vector<vector<int>> board(N, vector<int>(N, 0));

// Moves a knight can make
int xd[8] = {-2, -2, -1, -1, 1,  1, 2,  2};
int yd[8] = { 1, -1,  2, -2, 2, -2, 1, -1};

bool isSafe(int x, int y)
{
    return (x>=0 && x<N && y>=0 && y<N && board[x][y] == 0);
}

// Warnsdorff's heuristic: Get the number of available moves from (x, y)
int getDegree(int x, int y)
{
    int count = 0;
    for(int i=0; i<8; i++)
    {
        int nx = x + xd[i];
        int ny = y + yd[i];
        if(isSafe(nx, ny)) count++;
    }
    return count;
}

// Backtracking with Warnsdorff’s Heuristic
bool backtrack(int pos, int row, int col)
{
    if(pos==N * N + 1)
    {
        for(int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout <<board[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }

    // Sort next moves based on Warnsdorff’s heuristic (fewest onward moves first)
    vector<pair<int, pair<int, int>>> moves;
    for (int i = 0; i < 8; i++)
    {
        int newr = row + xd[i];
        int newc = col + yd[i];
        if (isSafe(newr, newc))
        {
            int degree = getDegree(newr, newc);
            moves.push_back({degree, {newr, newc}});
        }
    }

    // Sort moves in increasing order of degree
    sort(moves.begin(), moves.end());

    // Try moves in order of least onward moves
    for (auto &m : moves)
    {
        int newr = m.second.first;
        int newc = m.second.second;
        board[newr][newc] = pos;

        if (backtrack(pos + 1, newr, newc))
            return true;  // If a solution is found, stop

        board[newr][newc] = 0;  // Backtrack
    }

    return false;  // No solution found from this path
}

int32_t main()
{
    int x, y;
    cin >> y >> x;

    board[x - 1][y - 1] = 1;  // Start position
    backtrack(2, x - 1, y - 1);

    return 0;
}
