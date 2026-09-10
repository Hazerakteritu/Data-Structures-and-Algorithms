#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mod 1000000007

vector<int>coins;
int n,x;

int solve()
{
    vector<int>dp(x + 1, 0);
    dp[0] = 1;
    for (int i=0; i<n; i++)
    {
        for (int j=coins[i]; j<=x; j++)
        {
            dp[j] = (dp[j]+dp[j-coins[i]])%mod;
        }
    }

    return dp[x];
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
