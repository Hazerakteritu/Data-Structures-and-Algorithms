#include <bits/stdc++.h>
using namespace std;

int n, x;
multiset<int> s;
//multiset<int>::iterator it;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x - i > 0)
        {
            cout<<x<< " ";
            //this part is fastest way (code-wise) i know of finding
            //longest non-decreasing subsequence
            //if you simply want longest increasing, replace multiset with set
            x -= i;
            s.insert(x);
            auto it = upper_bound(s.begin(), s.end(), x);
            if (it != s.end()) s.erase(it);
        }
    }
    //for(auto i: s) cout<<i<<" ";
    //cout<<endl;
    cout << n - s.size() << endl;
    return 0;
}
