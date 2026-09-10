#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
const int INF = 1e17;
#define mx 200000+6

void solve(int n, int a,int b, int c)
{
    //base case
    if(n==0) return;

    solve(n-1, a, c, b);
    cout<<a<<" "<<c<<endl;
    solve(n-1, b, a, c);
}


int32_t main()
{
    int t=1;
    //cin>>t;
    for(int cs=1; cs<=t; cs++)
    {
        int n;
        cin>>n;
        cout<<pow(2,n)-1 <<endl;
        solve(n, 1, 2, 3);
    }
    return 0;
}

