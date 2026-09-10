#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
const int INF = 1e17;

void solve()
{
    int x,y,z,k;
    cin>>x>>y>>z>>k;

    vector<int>a(x),b(y),c(z);
    for(auto &i : a) cin>>i;
    for(auto &i : b) cin>>i;
    for(auto &i : c) cin>>i;

    vector<int>ab;
    for(auto i : a)
        for(auto j : b)
            ab.push_back(i + j);

    sort(ab.rbegin(), ab.rend());
    if(ab.size()>k)ab.resize(k);

    vector<int>abc;
    for(auto i : ab)
        for(auto j : c)
            abc.push_back(i + j);

    sort(abc.rbegin(), abc.rend());
    for(int i=0; i<k; i++)
        cout<<abc[i]<<endl;
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

