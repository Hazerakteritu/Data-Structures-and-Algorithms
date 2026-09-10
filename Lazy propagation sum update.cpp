#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mx 100006

int arr[mx], st[mx*4], lazy[mx*4];

void buildst(int si, int ss, int se)
{
    if(ss==se)
    {
        st[si] = arr[ss];
        return;
    }
    int mid = (ss+se)/2;
    buildst(si*2 + 1, ss, mid);
    buildst(si*2 + 2, mid+1, se);

    st[si] = st[si*2+1] + st[si*2+2];
}

int query(int si, int ss, int se, int qs, int qe)
{
    if(lazy[si]!=0)
    {
        int dx = lazy[si];
        lazy[si] = 0;
        st[si] += dx*(se-ss+1);

        if(ss!=se)
        {
            lazy[2*si+1] += dx;
            lazy[2*si+2] += dx;
        }
    }

    if(se < qs || ss>qe) return 0;

    if(ss>=qs && se<=qe) return st[si];

    int mid = (ss + se)/2;
    return query(2*si + 1, ss, mid, qs, qe) + query(2*si + 2, mid+1, se, qs, qe);

}
void update(int si, int ss, int se, int qs, int qe, int val)
{
    if(lazy[si]!=0){
        int dx = lazy[si];
        lazy[si] = 0;
        st[si] += dx*(se-ss+1);

        if(ss!=se){
            lazy[2*si+1] += dx;
            lazy[2*si+2] += dx;
        }
    }
    if(ss > qe || se<qs) return;
    if(ss>=qs && se<=qe)
    {
        int dx = (se - ss + 1)*val;
        st[si] += dx;

        if(ss!=se)
        {
            lazy[2*si+1]+= val;
            lazy[2*si+2]+= val;
        }
        return;
    }
    int mid = (ss + se )/2;
    update(2*si+1, ss, mid, qs, qe, val);
    update(2*si+2, mid+1, se, qs, qe, val);

    st[si] = st[2*si+1] + st[2*si+2];
}

int32_t main()
{
    int n,q;
    cin>>n>>q;

    for(int i=0; i<n; i++) cin>>arr[i];
    buildst(0, 0, n-1);
    // for(int i=0; i<4*n; i++) cout<<st[i]<<" ";
    while(q--){
        int code;
        cin>>code;
        if(code==1){
            int l,r;
            cin>>l>>r;
            l--, r--;
            cout<<query(0,0, n-1, l, r)<<endl;
        }else{
            int l,r,val;
            cin>>l>>r>>val;
            update(0, 0, n-1, l-1, r-1, val);
        }
    }


    return 0;
}
