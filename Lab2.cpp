#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mx 100005
#define INF 10000000

int arr[mx];
int seg[4*mx],lazy[4*mx];

void build(int si,int ss,int se)
{
    if(ss == se)
    {
        seg[si] = arr[ss];
        return;
    }
    int mid = (ss + se)/2;
    build(si*2+1, ss, mid);
    build(si*2+2, mid+1, se);

    seg[si] = min( seg[2*si+1], seg[2*si+2]);
}


int query(int node, int low, int high, int qs, int qe)
{

    if( low>qe || high<qs) return INF;

    if(low>=qs && high<=qe) return seg[node];

    int mid = (low+high)/2;
    int a = query(2*node+1, low, mid, qs, qe);
    int b = query(2*node+2, mid+1, high, qs, qe);
    return min(a,b);
}


int32_t main()
{
    int t;
    cin>>t;
    //string s;
    //cin>>s;

    for(int tt=1; tt<=t; tt++)
    {
        int n,c;
        cin>>n>>c;

        for(int i=0; i<n; i++) cin>>arr[i];

        build(0,0,n-1);
        //for(int i=0; i<10; i++) cout<<seg[i]<<" ";
        cout<<"Case "<<tt<<":"<<endl;

        while(c--)
        {
            int l,r;
            cin>>l>>r;
            cout<<query(0,0,n-1,l-1,r-1)<<endl;
        }
    }
}
