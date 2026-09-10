#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
#define piii pair<pii, int>
#define f first
#define s second
#define MX 100000+6
#define N 200000
#define inf 1e18
const int INF = INT_MAX;
const int mod = 10000007;


int minw[N+1][N+1];
int mxw[N+1][N+1];

void solve()
{
    int n;
    cin>>n;

    vector<vector<pii>>adj;

    for(int i=1; i<n; i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b, w});
        adj[b].push_back({a,w});
        //        minw[a][b] = w;
//        mxw[b][a] = w;
    }




    for(int i=1; i<=n; i++)
    {
        for(int j= i+1; j<=n; j++)
        {
            // bfs(i, n);
        }
    }

//    for(int i=1; i<=n ; i++)
//    {
//        for(int j=1; j<=n; j++) cout<<minw[i][j]<<" ";
//        cout<<endl;
//    }



}

int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1, cs = 1;
    cin>>t;

    while(t--)
    {

//        int ans = solve();
        //cout<<"Case "<<cs++<<":"<<endl;
        solve();
    }

}
