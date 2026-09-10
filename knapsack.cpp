#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int n, W;
    cin >> n >> W;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }

    bitset<10001> can; // Adjust size if necessary
    vector<int> maxValue(10001, 0); // Track maximum value for each weight
    can[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int w = W; w >= wt[i]; w--) {
            if (can[w - wt[i]]) {
                can[w] = 1;
                maxValue[w] = max(maxValue[w], maxValue[w - wt[i]] + val[i]);
            }
        }
    }

    int answer = 0;
    for (int w = 0; w <= W; w++) {
        answer = max(answer, maxValue[w]);
    }

    cout << answer << endl;
    return 0;
}
