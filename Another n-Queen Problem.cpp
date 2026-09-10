#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
const int INF = 1e17;
#define mx 200000+6

int ans;

void nqueen(int col, vector<string>&obs, vector<int>&lrow, vector<int>&upD, vector<int>&low, int n)
{
    if(col==n){
        ans++;
        return;
    }
    for(int row =0; row<n; row++){
        if(lrow[row]==0 && upD[n-1+col-row]==0 && low[row+col]==0 && obs[row][col]=='.'){
            obs[row][col] = 'Q';
            lrow[row] = 1;
            upD[n-1+col-row]=1;
            low[row+col]=1;

            nqueen(col+1, obs, lrow, upD, low, n);

            obs[row][col] = '.';
            lrow[row] = 0;
            upD[n-1+col-row]=0;
            low[row+col]=0;
        }
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, cs=1;
    while(cin>>n && n)
    {
        vector<string>obs;
        for(int i=0; i<n; i++)
        {
            string st;
            cin>>st;
            obs.pb(st);
        }

        vector<int>leftrow(2*n+1,0), upDiagonal(2*n+1, 0), lowDiagonal(2*n+1, 0);
        ans = 0;

        nqueen(0, obs, leftrow, upDiagonal, lowDiagonal, n);
        cout<<"Case "<<cs<<": "<<ans<<endl;
        cs++;
    }

    return 0;
}
