#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin>>n;
    int a[n+1];
    int b[n+1];
    int pasum[n+1];
    int pbsum[n+1];
    a[0] = 0;
    b[0] = 0;
    pasum[0] = 0;
    pbsum[0] = 0;

    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b, b+n+1);

    for(int i=1; i<=n; i++)
    {
        pasum[i] = pasum[i-1] + a[i];
        pbsum[i] = pbsum[i-1] + b[i];
    }
    /*for(int i=1; i<=n; i++)
    {
        cout<<pasum[i]<<" ";
    }*/

    int m;
    cin>>m;
    while(m--)
    {
        int type, l,r;
        cin>>type>>l>>r;

        if(type==1)
        {
            int ans = pasum[r]- pasum[l-1];
            cout<<ans<<endl;
        }
        else
        {
            int ans = pbsum[r]- pbsum[l-1];
            cout<<ans<<endl;
        }
    }

    return 0;
}
