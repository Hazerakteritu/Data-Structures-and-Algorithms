#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//vector<string>ar(100);

ll dp[200100],dis[200100],tim[200100];
pair<ll,ll>cnv[200100];


//int wt[251];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int i,j,i1,i2;
    ll x,t,b,k,a,h,m,l,r,z,a1,b1,c1,y,n,x1,d,c,f,u,w;

    cin>>n;

    for(i=1; i<=n; i++)
        cin>>dis[i]>>tim[i];

    cin>>x;

    for(i=1; i<=n; i++)
        cnv[i].first = dis[i]+ x*tim[i], cnv[i].second=x*tim[i]-dis[i];

    sort(cnv+1,cnv+1+n);

    dp[0]=-1e18;
    c=0;
    for(i=1; i<=n; i++)
    {
        if(cnv[i].first>=0&&cnv[i].second>=0)
            if(cnv[i].second>=dp[c]) dp[++c]=cnv[i].second;
            else dp[upper_bound(dp+1,dp+c+1,cnv[i].second)-dp]=cnv[i].second;
    }
    cout<<c<<" ";
    memset(dp,0,sizeof(dp));
    c=0;
    for(i=1; i<=n; i++)
        if(cnv[i].second>=dp[c]) dp[++c]=cnv[i].second;
        else dp[upper_bound(dp+1,dp+c+1,cnv[i].second)-dp]=cnv[i].second;
    cout<<c;

    return 0;
}
