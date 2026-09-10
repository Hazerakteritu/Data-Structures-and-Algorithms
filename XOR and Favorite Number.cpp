#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 1e5 + 5;
const int B_SIZE = 320;  // sqrt(MAX)

struct query
{
    int l, r, id;
};

query Q[MAX];
int ar[MAX], fre[MAX * 100], k;
int cnt = 0, ans[MAX];

bool cmp(query a, query b)
{
    if (a.l / B_SIZE == b.l / B_SIZE)
        return a.r < b.r;
    return a.l / B_SIZE < b.l / B_SIZE;
}

void add(int pos)
{
    cnt += fre[ar[pos] ^ k];
    fre[ar[pos]]++;
}

void sub(int pos)
{
    fre[ar[pos]]--;
    cnt -=  fre[ar[pos] ^ k];
}


void Mos(int q)
{
    sort(Q, Q + q, cmp);

    int cur_l = 0, cur_r = -1;
    for (int i = 0; i < q; i++)
    {
        int L = Q[i].l - 1; // Convert to 0-based indexing
        int R = Q[i].r;

        while (cur_l > L) add(--cur_l);
        while (cur_r < R) add(++cur_r);

        while (cur_l < L) sub(cur_l++);
        while (cur_r > R) sub(cur_r--);

        ans[Q[i].id] = cnt;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, L, R;
    cin >> n >> q >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> ar[i];
        ar[i] ^= ar[i - 1];
    }

    for (int i = 0; i < q; i++)
    {
        cin >> L >> R;
        Q[i].id = i;
        Q[i].l = L;
        Q[i].r = R;
    }

    Mos(q);

    for (int i = 0; i < q; i++)
        cout << ans[i] << endl;

    return 0;
}
