#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
const int INF = 1e17;
#define mx 200000+6

int mn=45;

void queen(int col, vector<string>&board, vector<vector<int>>&ans, vector<int>&leftrow, vector<int>&upperDiagonal, vector<int>&lowerDiagonal, int givenclm)
{
    if (col == 8)
    {
        vector<int>temp;
        for(int c=0; c<8; c++)//clm
        {
            for(int r=0; r<8; r++)//row
            {
                if(board[r][c]=='Q') temp.pb(r+1);
            }
        }
        ans.pb(temp);

        return;
    }

    if(col== givenclm)
    {
        queen(col+1, board, ans, leftrow, upperDiagonal, lowerDiagonal, givenclm);
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

            queen(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, givenclm);

            board[row][col] = '.';
            leftrow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[8 - 1 + col - row] = 0;
        }
    }
}



int32_t main()
{
    int t=1, first = 0;
    cin>>t;
    for(int cs=1; cs<=t; cs++)
    {
        int r,c;
        cin>>r>>c;
        r--;
        c--;
        int n = 8;
        //Each dataset is separated by a blank line.
        if(first) cout<<endl;
        first = 1;

        vector<int>leftrow(n, 0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n - 1, 0);
        vector<string>board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        board[r][c]='Q';
        leftrow[r]=1;
        lowerDiagonal[r + c] = 1;
        upperDiagonal[n - 1 + c - r] = 1;

        vector<vector<int>>ans;

        queen(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, c);


        cout<<"SOLN       COLUMN"<<endl;
        cout<<" #      1 2 3 4 5 6 7 8"<<endl<<endl;
        int cnt = 1;

        for(auto it: ans)
        {
            printf("%2d     ",cnt++);
            //cout<<" "<<cnt++<<"     ";
            for(auto j: it) cout<<" "<<j;
            cout<<endl;
        }

    }
    return 0;
}
