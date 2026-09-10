#include<bits/stdc++.h>
using namespace std;

#define block 555 //square root of maximum Number of element
struct query
{
    int l;
    int r;
    int i;
};
query Q[200001];
int ar[30001], ans[200001];
int freq[1000001];
int cnt=0;

bool comp(query a, query b)
{
    if(a.l/block != b.l/block)
        return a.l/block<b.l/block;
    return a.r< b.r;
}
void add(int pos)
{
    freq[ar[pos]]++;
    if(freq[ar[pos]]==1)
        cnt++;
}
void remove(int pos)
{
    freq[ar[pos]]--;
    if(freq[ar[pos]]== 0)
        cnt--;
}

int main()
{
    int n,q;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>ar[i];

    cin>>q;
    for(int i=0; i<q; i++)
    {
        cin>>Q[i].l;
        cin>>Q[i].r;
        Q[i].i = i;
        Q[i].l--;
        Q[i].r--;
    }
    sort(Q, Q+q, comp);

    int ml = 0, mr = -1;
    for(int i=0; i<q; i++)
    {
        int L = Q[i].l;
        int R = Q[i].r;

        while(ml > L)
            ml--, add(ml);

        while(ml < L)
            remove(ml),ml++;

        while(mr > R)
            remove(mr),mr--;

        while(mr < R)
            mr++, add(mr);

        ans[Q[i].i] = cnt;
    }

    for(int i=0; i<q; i++)
        cout<<ans[i]<<endl;

    return 0;
}
