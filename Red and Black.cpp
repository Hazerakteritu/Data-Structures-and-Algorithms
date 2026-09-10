#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back


int n,m;
vector<string> ans;
int dx[4] = {0, 0, 1,-1};
int dy[4] = {1,-1, 0, 0};
int cnt = 1;

void solve(int x, int y, vector<string>&board)
{
    for(int i=0; i<4; i++){
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(newx>=0 && newx<n && newy>=0 && newy<m &&  board[newx][newy]== '.' ){
            board[newx][newy] = '@';
            cnt++;
            solve(newx, newy, board);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    while(cin>>m && cin>>n)
    {
        if(n==0 && m==0) break;

        vector<string>board(n);
        for(int i=0; i<n; i++)
        {
            string str;
            cin>>str;
            board[i] = str;
        }
        //for(int i=0; i<n; i++) cout<<board[i]<<endl;
        int mx=0, my=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]=='@')
                {
                    mx = i, my = j;
                    break;
                }
            }
        }
        cnt = 1;

        solve(mx, my, board);

        //for(auto it: board) cout<<it<<endl;
        cout<<cnt<<endl;

    }

    return 0;
}
