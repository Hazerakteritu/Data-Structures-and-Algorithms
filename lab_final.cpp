#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
const int INF = 1e18;
#define mx 1000000000
#define mod 100000007



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for(int tt=1; tt<=t; tt++)
    {
        int n,W;
        cin>>n>>W;
        vector<int>coins(n);
        for(int i=0; i<n; i++)
        {
            cin>>coins[i];
        }

        vector<int>dp(W + 1, 0);
        dp[0] = 1;
        for (int i=0; i<n; i++)
        {
            for (int j=coins[i]; j<=W; j++)
            {
                dp[j] = (dp[j] + dp[j-coins[i]])%mod;
            }
        }


        cout<<"Case "<<tt<<": "<<dp[W] <<endl;
    }

    return 0;
}
