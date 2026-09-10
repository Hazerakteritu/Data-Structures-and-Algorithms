
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
const int INF = 1e17;
#define MX 100000+6
#define mod 998244353


int vec[100000000]= {0};


int solve(int n)
{
    if(n==0)
    {
        vec[n] = 1;
        return 1;
    }

    if(n==1)
    {
        vec[n] = 2;
        return 2;
    }

    if(vec[n]!=0) return vec[n];

    return vec[n] = (solve(n-1)*solve(n-2))% mod;
}

int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int t=1, cs = 1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int ans;
        if(n==0) ans = 1;
        else if(n==1) ans = 2;
        else{
            ans = solve(n-1)*solve(n-2);
            ans = ans%mod;
        }


        cout<<ans<<endl;

    }

}
