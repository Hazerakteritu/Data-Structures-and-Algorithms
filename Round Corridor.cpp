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
    int n,m,q;
    cin>>n>>m>>q;

    vector<int>vec(3);
    vec[1]=n/__gcd(n,m);
    vec[2]=m/__gcd(n,m);

    while(q--)
    {
        int a1,a2,b1,b2;
        cin>>b1>>a1>>b2>>a2;
        int x=(a1-1)/vec[b1];
        int y=(a2-1)/vec[b2];

        if(x==y) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
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
