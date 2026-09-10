#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

const int N=10000+2;
vector<int>mve;
int k;

int calMex(set<int> st)
{
    int cnt = 0;
    while(st.find(cnt) != st.end())
        cnt++;

    return cnt;
}
int grndy[N];
int calGrundy(int s)
{
    if(s < mve[0]) return 0;
    if(grndy[s]!= -1) return grndy[s];

    set<int>st;
    for(int i=0; i< k ; i++){
        int y = s - mve[i];

        if(y >= 0)
          st.insert(calGrundy(y));
    }
    grndy[s] = calMex(st);
    return grndy[s];
}

int32_t main()
{
    memset(grndy, -1, sizeof(grndy));
    cin>>k;
    for(int i=0; i<k; i++){
        int ele;
        cin>>ele;
        mve.push_back(ele);
    }
    sort(mve.begin(), mve.end());
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];

        int gsum = calGrundy(arr[0]);
        for(int i=1; i<n; i++){
            gsum^= calGrundy(arr[i]);
        }

        if(gsum != 0) cout<<"W";
        else cout<<"L";
    }

    return 0;
}
