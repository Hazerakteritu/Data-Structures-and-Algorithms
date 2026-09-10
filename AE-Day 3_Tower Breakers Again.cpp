#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

const int N=100000+1;
vector<int>divs[N];

void sieve()
{
    for(int i=2; i<N; i++)
    {
        for(int j = i; j<N; j=j+i)
            divs[j].push_back(i);
    }
}

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
    if(s == 1) return 0;
    if(grndy[s]!= -1) return grndy[s];

    set<int>st;
    for(int i=0; i<divs[s].size(); i++){
        int y = divs[s][i];
        int z = s/y;
        if(y%2==0) st.insert(0);
        else st.insert(calGrundy(z));
    }
    grndy[s] = calMex(st);
    return grndy[s];
}

int32_t main()
{

    sieve();
    memset(grndy, -1, sizeof(grndy));

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

        if(gsum != 0) cout<<1<<endl;
        else cout<<2<<endl;
    }

    return 0;
}
