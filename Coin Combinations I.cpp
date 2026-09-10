#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mod 1000000007

vector<int>coins;
int n,x;

int solve()
{
    int dp[x+1] = {};
    dp[0] = 1;
    for (int i=1; i<=x; i++)
    {
        for (int j=0; j<n; j++)
        {
            if(coins[j]>i) continue;

            dp[i] = (dp[i]+ dp[i-coins[j]])%mod;
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
