#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
const int INF = 1e17;
#define mx 200000+6


void permutation(vector<int>&ds, vector<int>&num, vector<vector<int>>&ans, int freq[])
{
    //base case
    if(ds.size()==num.size()){
        ans.pb(ds);
        return;
    }
    for(int i=0; i<num.size(); i++){
        if(!freq[i]){
            ds.pb(num[i]);
            freq[i] = 1;
            permutation(ds, num, ans, freq);

            freq[i]=0;
            ds.pop_back();
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    //cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>num(n);
        for(int i=0; i<n; i++) cin>>num[i];
        vector<vector<int>>ans;
        vector<int>ds;
        int freq[num.size()];
        for(int i=0; i<num.size(); i++) freq[i]=0;

        permutation(ds, num, ans, freq);

        for(auto it: ans){
            for(auto i: it){
                    cout<<i<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}
