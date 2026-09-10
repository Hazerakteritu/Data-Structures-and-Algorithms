#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
const int INF = 1e17;
#define mx 200000+6

int mn=45;

void queen(int col, vector<string>&given, vector <string>&board, vector<int>&leftrow, vector < int >& upperDiagonal, vector < int > & lowerDiagonal)
{
    if (col == 8)
    {
        int cnt = 0;
       // cout<<given[0]<<endl;
       // cout<<board[0]<<endl;
        for(int i=0; i<8; i++){

            if( board[i] == given[i]) cnt++;
        }

        //cout<<cnt<<endl;
        //cout<<endl;
        int notmatcth = 8 - cnt;
        mn = min(mn, notmatcth);

        return;
    }

    for(int row = 0; row < 8; row++)
    {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[8 - 1 + col - row] == 0)
        {
            board[row][col] = 'q';
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
    int t;
    cin>>t;
    for(int cs=1; cs<=t; cs++)
    {
        int n=8;
        vector<string>given(n);
        for(int i=0; i<n; i++){
            cin>>given[i];
        }

        vector<string>board(n, string(n, '.'));

        vector<int>leftrow(n, 0), upperDiagonal(2*n - 1, 0), lowerDiagonal(2*n - 1, 0);

        mn = 45;

        queen(0, given, board, leftrow, upperDiagonal, lowerDiagonal);

        cout<<"Case "<<cs<<": "<<mn<<endl;

    }
    return 0;
}
