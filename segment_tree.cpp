#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int arr[mx],st[4*mx]; //st -> segment tree

//si->segment index , ss->segment start, se->segment end
int buildst(int si,int ss,int se)
{
    if(se==ss)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = (ss+se)/2;
    st[si] = buildst(si*2+1,ss,mid) +
             buildst(si*2+2,mid+1,se);
    return st[si];
}


int getSum(int si,int ss,int se,int qs,int qe)
{
    if(qs>qe) return 0;
    if(qs==ss && qe==se) return st[si];

    int mid = (se + ss)/2;
    return getSum(si*2+1,ss,mid,qs,min(qe,mid)) + getSum(si*2+2,mid+1,se,max(qs,mid+1),qe);
}

void update(int si,int ss,int se,int pos,int diff)
{
    if(ss==se) st[si]= st[si] + diff;
    else
    {
        int mid = (ss+se)/2;
        if(pos <= mid)
            update(si*2+1, ss, mid, pos, diff);
        else
            update(si*2+2, mid+1, se, pos, diff);

        st[si] = st[si*2+1]+ st[si*2+2];
    }

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
            int x;
            cin>>x;
            if(x==1)
            {
                int a;
                cin>>a;
                cout<<getSum(0,0,n-1,a,a)<<endl;
                int value = getSum(0,0,n-1,a,a);
                int diff = value - 2*value;
                update(0,0,n-1,a,diff);
            }
            else if(x == 2)
            {
                int pos,v;
                cin>>pos>>v;
                update(0,0,n-1,pos,v);
            }
            else if(x==3)
            {
                int a,b;
                cin>>a>>b;
                cout<<getSum(0,0,n-1,a,b)<<endl;
            }
        }
    }
    return 0;
}
