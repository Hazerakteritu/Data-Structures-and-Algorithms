#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define mx 100005
int arr[mx],st[4*mx]; //st -> segment tree

//si->segment index , ss->segment start, se->segment end
void buildst(int si,int ss,int se)
{
    if(se==ss)
    {
        st[si] = arr[ss];
        return;
    }
    int mid = (ss+se)/2;

    buildst(si*2+1,ss,mid);
    buildst(si*2+2,mid+1,se) ;

    st[si] = min( st[si*2+1], st[si*2+2] );
}


int getmin(int si,int ss,int se,int qs,int qe)
{
    if(qs> se || qe< ss ||qs>qe) return INF;
    if(ss>=qs && se<=qe) return st[si];

    int mid = (se + ss)/2;
    return min( getmin(si*2+1, ss, mid, qs, qe ), getmin(si*2+2,mid+1,se, qs,qe));
}


int main()
{
    int t;
    cin>>t;
    for(int tt=1; tt<=t; tt++)
    {
        int n,q;
        cin>>n>>q;
        //int arr[n+1],st[4*n];
        fill(arr, arr+mx, 0);
        fill(st, st+ 4*mx, 0);

        for(int i=0; i<n; i++) cin>>arr[i];
        buildst(0,0,n-1);
        //for(int i=0; i<10; i++) cout<<st[i]<<" ";
        cout<<"Case "<<tt<<":"<<endl;
        while(q--)
        {
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            cout<<getmin(0,0,n-1,a,b)<<endl;
        }
    }
    return 0;
}
