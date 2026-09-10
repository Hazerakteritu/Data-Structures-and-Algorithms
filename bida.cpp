#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
#define piii pair<pii, int>
#define f first
#define s second
#define MX 100000+6
#define N 1000 + 2
#define inf 1e18
const int mod = 1000000007;



void solve()
{
    map<int,int>mp;
    multiset<int>st;
    st.insert(-1);

    vector<int>vec1, vec2;


    int q;
    cin>>q;

    while(q--)
    {
        int tp;
        cin>>tp;

        if(tp == 1)
        {
            int ele;
            cin>>ele;

            mp[ele]++;
            st.insert(ele);


        }
        else if(tp == 2)
        {
            int x, k;
            cin>>x>>k;

            int ans = -1;

            auto it = st.upper_bound(x);

            while(k--)
            {
                it--;
                if(it == st.begin()) break;
            }

            if(it == st.begin())
                cout<<-1<<endl;
            else
                cout<<*it<<endl;
        }
        else if(tp == 3)
        {
            int x, k;
            cin>>x>>k;

            int ans = -1;

            auto it = st.lower_bound(x);
            //cout<<*it<<endl;

            for(int i=1; i<k; i++)
            {
                if(it == st.end())
                {
                    break;
                }
                it++;
            }

            if(it == st.end()) cout<<-1<<endl;
            else
                cout<<*it<<endl;

        }
    }
}

int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int t = 1, cs = 1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
}




