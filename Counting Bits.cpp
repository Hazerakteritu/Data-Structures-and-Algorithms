#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll count_ones(ll n)
{
    if (n == 0) return 0;

    ll x = 0;
    while ((1LL << (x + 1)) <= n)
    {
        x++;
    }

    ll power = (1LL << x);
    ll ones_till_2x = x * (power / 2);
    ll msb_to_n = n - power + 1;
    ll remaining = count_ones(n - power);

    return ones_till_2x + msb_to_n + remaining;
}

int main()
{
    ll n;
    cin >> n;
    cout << count_ones(n) << endl;
    return 0;
}
