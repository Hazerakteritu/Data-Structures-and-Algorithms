#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
const int INF = 1e17;
#define mx 100000+6
#define mod 998244353

int extended_gcd(int m,int n,int &p,int &q)
{
    if(!n)
    {
        p=1;
        q=0;
        return m;
    }
    int g = extended_gcd(n,m%n,p,q);
    int t=p;
    p=q;
    q=t-(m/n)*q;
    return g;
}


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    cin>>t;

    for(int cs=1; cs<=t; cs++)
    {
        int a,b,c,p,x,y,ans=0;
        cin>>a>>b>>c>>p;
        int g=extended_gcd(a,b,x,y);

        int da=b/g;
        int db=a/g;

        for(int k=0;; k++)
        {
            int k0=p-k*c;
            if(k0<0) break;
            if(k0%g!=0) continue;

            int X=x*k0/g,Y=y*k0/g;

            X=(X%da + da)%da;
            Y=(k0 - X*a)/b;

            if(Y>=0) ans++;
            ans+=Y/db;
        }
        cout<<"Case "<<cs<<": "<<ans<<endl;
    }

    return 0;
}
