
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mx 100000 + 7

int cnt = 0;

int f(int i)
{
    if(i==0) return 0;

    return i+ f(i-1);
}


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    int sum = f(n);
    cout<<sum<<endl;

    return 0;
}

