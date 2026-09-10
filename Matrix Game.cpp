#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin>>t;
    for(int tt=1; tt<=t; tt++)
    {
        int m,n;
        cin>>m>>n;
        int ans=0;
        for(int i=1; i<=m; i++)
        {
            int sum=0;
            for(int j=1; j<=n; j++)
            {
                int ele;
                cin>>ele;
                sum+=ele;
            }
            ans ^= sum;
        }
        //cout<<ans<<endl;

        cout<<"Case "<<tt<<": ";
        if(ans==0) cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }

    return 0;
}
