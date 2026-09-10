#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int mxN=1e5+5;
vector<int>divisors[mxN];
ll sum[mxN],f[mxN];

void computeDivisors()
{
    for(int i=1; i<mxN; i++)
    {
        for(int j=i; j<mxN; j+=i)
        {
            divisors[j].pb(i);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    cin>>t;
    const int N = 1e5;
    vector<vector<int>> dv(N + 1);
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
        {
            dv[j].emplace_back(i);
        }
    }
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        const int N = 1e5;
        vector<int> nums(N + 1);
        vector<ll> cnt(N + 1);
        for (int i = 0; i < n; i++)
        {
            for (auto d : dv[a[i]])
            {
                cnt[d] += (n - i - 1) * nums[d];
                nums[d]++;
            }
        }
        ll ans = 0;
        for (int i = N; i >= 1; i--)
        {
            for (int j = i * 2; j <= N; j += i)
            {
                cnt[i] -= cnt[j];
            }
            ans += cnt[i] * i;
        }
        cout << ans << '\n';
    }
}
