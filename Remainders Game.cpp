#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll lcm(int x,int y)
{
    return (x*y)/__gcd(x,y);
}


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll c[n];
        for(int i=0; i<n; i++)
            cin>>c[i];
        ll remainder=1;
        for(int i=0; i<n; i++)
        {
            remainder=lcm(remainder,c[i])%k;
        }
        if(remainder==0)
            cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}
