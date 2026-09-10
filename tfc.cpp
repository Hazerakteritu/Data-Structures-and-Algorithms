#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define INF LONG_MAX
#define pii pair<int,int>

/*
bool comp(pii a, pii b)
{
    if(a.first<b.first) return true;
    else if(a.second<b.second) return true;
    return false;
}
*/

void solve()
{
    int n,q;
    cin>>n>>q;
    vector<pii>vec;
    for(int i=0; i<q; i++)
    {
        int a,b;
        cin>>a>>b;
        vec.pb({a,b});
    }
    //sort(vec.begin(),vec.end(),comp);
    sort(vec.begin(), vec.end());

    for(auto it: vec)
    {
        // cout<<it.first<<" "<<it.second<<endl;
    }

    int i = 1;
    for(int j=0; j<vec.size() && i<=n; j++)
    {
        int vl = vec[j].first;
        int vr = vec[j].second;

       // cout<<vl<<" "<<vr<<endl;

        if(i< vl )
        {
            cout<<"No"<<endl;
            return;
        }else{
            i = vr;
        }

    }


    if(i>=n)
        cout<<"Yes"<<endl;
    else cout<<"No"<<endl;


    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    //cin>>t;
    for(int cs = 1; cs<=t; cs++)
    {
        //cout<<"Case "<<cs<<": ";
        solve();

        //if(solve()) cout<<"YES"<<endl;
        //else cout<<"NO"<<endl;
    }
    return 0;
}
