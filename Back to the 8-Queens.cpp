#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
const int INF = 1e17;
#define mx 200000+6

int match = 0;

void queen(int col, vector<string>&given, vector <string>&board, vector<int>&leftrow, vector < int >& upperDiagonal, vector < int > & lowerDiagonal)
{
    if (col == 8)
    {
        int cnt = 0;
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
                if( board[i][j] == given[i][j] && board[i][j]=='Q') cnt++;
        }
        //cout<<cnt<<endl;

        match = max(match, cnt);
        return;
    }

    for(int row = 0; row < 8; row++)
    {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[8 - 1 + col - row] == 0)
        {
            board[row][col] = 'Q';
            leftrow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[8 - 1 + col - row] = 1;

            queen(col + 1, given, board, leftrow, upperDiagonal, lowerDiagonal);

            board[row][col] = '.';
            leftrow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[8 - 1 + col - row] = 0;
        }
    }
}



int32_t main()
{
    //int t=1000;
    //cin>>t;

    int cs = 1;
    vector<int>g(8);
    while(cin>>g[0]>>g[1]>>g[2]>>g[3]>>g[4]>>g[5]>>g[6]>>g[7])
    {
        int n=8;

        //vector<string>board(n, string(n, '.'));
        vector<string>given(n), board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            given[i] = s;
            board[i] = s;
        }

        for(int c=0; c<n; c++)
        {
            int r = g[c];
            //cin>>r;
            r--;
            given[r][c]='Q';
        }

        vector<int>leftrow(n, 0), upperDiagonal(2*n - 1, 0), lowerDiagonal(2*n - 1, 0);
        match = 0;

        queen(0, given, board, leftrow, upperDiagonal, lowerDiagonal);

        int ans = n-match;
        cout<<"Case "<<cs++<<": "<<ans<<endl;

    }
    return 0;
}
