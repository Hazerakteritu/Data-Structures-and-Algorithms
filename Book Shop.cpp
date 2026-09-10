#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, vector<int>& wt, vector<int>& val)
{
    vector<int> dp(W + 1, 0);

    for (int i = 1; i <= wt.size(); i++)
    {
        for (int w = W; w >= 0; w--)
        {
            if (wt[i - 1] <= w)
                dp[w] = max(dp[w], dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W];
}

int main()
{
    int n,P;
    cin>>n>>P;
    vector<int>price(n), pages(n);
    for(int i=0; i<n; i++) cin>>price[i];
    for(int i=0; i<n; i++) cin>>pages[i];

    cout << knapSack(P, price, pages) << endl;
    return 0;
}
