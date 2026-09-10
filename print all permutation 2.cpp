//using swap instead of using map and ds

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
const int INF = 1e17;
#define mx 200000+6


void permutation(vector<int>&num, vector<vector<int>>&ans, int point)
{
    //base case
    if(point ==num.size())
    {
        ans.pb(num);
        return;
    }
    for(int i=point; i<num.size(); i++)
    {
        swap(num[point],num[i]);
        permutation(num, ans, point+1);
        swap(num[point],num[i]);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin>>n;
    vector<int>num(n);
    for(int i=0; i<n; i++) cin>>num[i];

    vector<vector<int>>ans;
    permutation(num, ans, 0);

    for(auto it: ans)
    {
        for(auto i: it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}
