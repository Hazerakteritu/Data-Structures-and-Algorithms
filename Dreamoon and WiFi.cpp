#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
const int INF = 1e17;
#define mx 200000+6


void solve(int indx, int pos, string rcv, vector<int>&ans)
{
    if(indx == rcv.length())
    {
        ans.pb(pos);
        return;
    }

    if(rcv[indx]=='+')
    {
        solve(indx+1, pos+1, rcv, ans);
    }
    else if(rcv[indx]=='-')
    {
        solve(indx+1, pos-1, rcv, ans);
    }
    else if(rcv[indx]=='?')
    {
        solve(indx+1, pos+1, rcv, ans);
        solve(indx+1, pos-1, rcv, ans);
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
        string send, recve;
        cin>>send>>recve;
        int des = 0;
        for(int i=0; i<send.size(); i++)
        {
            if(send[i]=='+') des++;
            else des--;
        }
        vector<int>ans;
        solve(0, 0, recve, ans);

        int cnt = 0;
        for(auto it: ans)
            if(it==des) cnt++;

        cout<<fixed<<setprecision(12)<< (float)cnt/ans.size() <<endl;
    }

    return 0;
}
