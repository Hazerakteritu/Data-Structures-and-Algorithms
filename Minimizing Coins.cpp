#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define INF LONG_MAX

vector<int>coins;
int n,x;

int solve()
{
    vector<int>dp(x+1,INF);
    dp[0] = 0;

    for (int i=1; i<=x; i++)
    {
        for (int j=0; j<n; j++)
        {
            int d = i - coins[j];
            if(coins[j]>i || dp[d]==INF) continue;

            dp[i] = min(dp[i], dp[d]+1);
        }
    }
    if(dp[x]!=INF) return dp[x];

    return -1;
}

int32_t main()
{
    cin>>n>>x;

    for(int i=0; i<n; i++){
        int ele;
        cin>>ele;
        coins.pb(ele);
    }

    cout<<solve()<<endl;
}
