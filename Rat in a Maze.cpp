#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
const int INF = 1e17;
#define MX 100000+6
#define mod 998244353


int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
string dir = "RLDU";
vector<string>ans;

void solvemz(int x, int y, vector<string>&board, string path)
{
    int n = board.size();
    if(x == n-1 && y == n-1)
    {
        ans.pb(path);
        return;
    }
    board[x][y] = '0';

    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if( nx>=0 && ny>=0 && nx<n && ny<n && board[nx][ny] == '1')
        {
            path.pb(dir[i]);

            solvemz(nx, ny, board, path);

            path.pop_back();
        }
    }
    board[x][y] = '1';
    return;
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
        vector<string>maze(n);
        for(int i=0; i<n; i++)
        {
            string str;
            cin>>str;
            maze[i] = str;
        }

        string path;

        solvemz(0, 0, maze, path);

        for(auto it: ans) cout<<it<<endl;
    }
}
