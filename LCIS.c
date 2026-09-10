#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define INF LONG_MAX
#define pii pair<int,int>


void solve()
{
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1; i<=n; i++) cin>>arr[i];
    int m;
    cin>>m;
    int b[m+1];
    for(int i=1; i<=m; i++) cin>>b[i];

    vector<int>dp(m+1,0) , par(m+1,0);
    for(int i=1; i<=n; i++){
        int prev = 0;
        for(int j=1; j<=m;  j++){
            if(arr[i]==b[j]){
                dp[j] =  dp[prev]+1;
                par[j] = prev;
            }else if(arr[i]> b[j] && dp[prev]<dp[j]){
                prev = j;
            }
        }
    }
    //for(auto it: dp) cout<<it<<" ";
    int last = 0;
    for(int i=1; i<=m; i++){
        if(dp[i]>dp[last]) last = i;
    }
    //cout<<last<<endl;
    vector<int>v;
    for(int i=last; i>0; i=par[i]){
        v.pb(b[i]);
    }

    reverse(v.begin(), v.end());
    cout<<v.size()<<endl;
    for(auto it: v) cout<<it<< " ";
    cout<<endl;


}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
        //int ans = solve();
        //cout<<ans<<endl;

        // if(solve()) cout<<"YES"<<endl;
        //else cout<<"NO"<<endl;
    }
    return 0;
}
