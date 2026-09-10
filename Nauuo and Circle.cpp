#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
const int INF = 1e17;
#define mx 100000+6
#define mod 998244353


void solve()
{
    int n;
    cin>>n;

    map<int,int>mp;
    int ans=n;
    n--;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        mp[x]++;
        mp[y]++;
        ans = ((ans*mp[x])% mod)*mp[y]%mod;
    }
    cout<<ans<<endl;
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
        solve();
    }

    return 0;
}
