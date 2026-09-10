#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mx 1000000

bool mark[mx+1];
vector<int>primes;

void sieve()
{
    fill(mark, mark+mx+1, true);

    mark[0]=mark[1]=false;
    for(int i = 2; i <= mx; i++)
    {
        if(mark[i])
        {
            primes.push_back(i);
            for(int j = i * 2; j <= mx; j += i)
                mark[j] = false;
        }
    }
}

void solve()
{
    int n;
    cin>>n;
    int mxcnt = 0;
    for(int p : primes)
    {
        if(p > n) break;
        int cnt = 0;
        while (n % p == 0) cnt++, n /= p;
        mxcnt = max(mxcnt, cnt);
    }
    cout << mxcnt <<endl;
}

int32_t main()
{
    sieve();
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
