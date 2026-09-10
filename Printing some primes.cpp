#include<bits/stdc++.h>
using namespace std ;
#define int long long
const int mx = 1000000000;

map<int,int>mp;
set<int>prime;

void isprime()
{
    mp[1]=1;
    for(int i=4; i<=mx; i+=2) mp[i]=1;
    for(int i=3; i*i<=mx; i+=2)
    {
        if(mp[i]==0)
        {
            for(int j = i*i ; j<=mx; j+=i) mp[j]=1;
        }
    }
   // for(int i=2; i<=mx; i++)
     //   if(mp[i]==0) prime.insert(i);
}


void solve()
{
    int m,n;
    cin>>m>>n;

    for(int i=m; i<=n; i++)
    {
        if(mp[i]==0) cout<<i<<endl;
    }

    cout<<endl;

    return;
}

int32_t main()
{
    isprime();
    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}
