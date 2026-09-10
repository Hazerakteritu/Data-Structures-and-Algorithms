/*
    AUTHOR:         BHUVNESH JAIN
    INSTITUTION:    BITS PILANI, PILANI
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio          ios_base::sync_with_stdio(false)
#define LL              long long
#define MAX             10000002
#define SIZE            664580
#define LIMIT           3165
#define MOD             1000000007
#define REP(i, n)       for (int i = 0; i < n; ++i)
#define REP1(i, n)      for (int i = 1; i <= n; ++i)
#define SET(a, b)       memset(a, b, sizeof(a))

int prime[SIZE], w[MAX];

void generate()
{
    int k = 1;
    prime[0] = 2;
    for (int i = 2; i < MAX; i += 2)
        w[i] = 2;
    for (int i = 3; i <= LIMIT; i += 2)
    {
        if (w[i] == 0)
        {
            prime[k++] = i;
            w[i] = i;
            for (int j = i * i, x = i << 1; j < MAX; j += x)
            {
                if (w[j] == 0)
                    w[j] = i;
            }
        }
    }
    for (int i = LIMIT + 1; i < MAX; i += 2)
    {
        if (w[i] == 0)
        {
            prime[k++] = i;
            w[i] = i;
        }
    }
}

int main()
{
    fastio;
    generate();
    int t, n, val, count;
    LL ans, magic, temp, temp1, temp2;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ans = 1;
        while (n != 1)
        {
            count = 0;
            val = w[n];
            magic = 1LL * val * val;
            while (n % val == 0)
            {
                n /= val;
                count += 1;
            }
            temp = 0;
            temp1 = val;
            temp2 = magic;
            REP(j, count)
            {
                temp += temp2 - temp1;
                temp1 *= magic;
                temp2 *= magic;
            }
            ans *= (temp + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}
