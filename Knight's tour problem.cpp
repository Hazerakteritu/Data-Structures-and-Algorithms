#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
const int INF = 1e17;
#define mx 200000+6

int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};


bool knight(int r, int c, int step, vector<vector<int>>&board, int n)
{
    if(step == n*n-1)
    {
        return true;
    }

    for(int i=0; i<8; i++)
    {
        int newr = r + dx[i];
        int newc = c + dy[i];

        if(newr>=0 && newr<n && newc>=0 && newc<n && board[newr][newc] == -1)
        {
            step++;
            board[newr][newc] = step;

            if( knight(newr, newc, step, board, n) )
                return true;

            step--;
            board[newr][newc] = -1;
        }
    }

    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    //cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>>board(n, vector<int>(n, -1));
        board[0][0] = 0;

        if( knight(0, 0, 0, board, n) )
        {

            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++) cout<<board[i][j]<<"  ";
                cout<<endl;
            }
        }
        else cout<<-1<<endl;
    }

    return 0;
}
