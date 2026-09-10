#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>

void solve()
{
    int n,w;
    cin>>n>>w;
    vector<int>weight(n),value(n);
    for(int i=0; i<n; i++)
        cin>>weight[i]>>value[i];

    int mxval = 0;
    for(auto it: value) mxval += it;
    vector<int>dp(mxval+1, INT_MAX);
    dp[0]=0;

    for(int i=0; i<n; i++)
    {
        int s = mxval-value[i];
        for(int j= s; j>=0; j--)
        {
            dp[j+value[i]] = min(dp[j+value[i]], dp[j]+weight[i]);
        }
    }
    int ans = INT_MIN;
    for(int i=0; i<=mxval; i++)
    {
        if(dp[i]<=w) ans = max(ans,i);
    }
    cout<<ans<<endl;

    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin>>t;
    while(t--)
    {
        solve();
        //if(solve()) cout<<"YES"<<endl;
        //else cout<<"NO"<<endl;
    }

    return 0;
}
