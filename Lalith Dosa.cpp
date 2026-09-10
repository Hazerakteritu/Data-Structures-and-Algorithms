#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 100000000;

int n;
int arr[MAX_N];
int bit[MAX_N];

void add(int pos, int val)
{
    for (; pos <= n; pos += (pos & -pos))
    {
        bit[pos] = max(bit[pos], val);
    }
}

int get(int pos)
{
    int best = 0;
    for (; pos > 0; pos -= (pos & -pos))
    {
        best = max(best, bit[pos]);
    }
    return best;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<int> fits;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] >= i) fits.push_back(arr[i] - i);
    }

    vector<int> vals = fits;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for (int &i : fits)
    {
        i = (int)(lower_bound(vals.begin(), vals.end(), i) - vals.begin()) + 1;
    }

    int lis = 0;
    for (int i : fits)
    {
        int curLis = get(i) + 1;
        lis = max(lis, curLis);
        add(i, curLis);
    }

    cout << n - lis << endl;
    return 0;
}
