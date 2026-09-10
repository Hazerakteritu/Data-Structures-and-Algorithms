#include<bits/stdc++.h>
using namespace std;
#define li long long int

#define block 1000 //square root of maximum Number of element
struct query
{
    int l;
    int r;
    int i;
};
query Q[200008]; //array of query
int ar[200008];
li ans[200008];
li freq[1000008];
li cnt=0, sum = 0;

bool comp(query a, query b)
{
    if(a.l/block != b.l/block)
        return a.l/block<b.l/block;
    return a.r< b.r;
}
void add(int pos)
{
    int ele = ar[pos];
    sum -= freq[ele]*freq[ele]*ele;

    freq[ele]++;
    sum += freq[ele]*freq[ele]*ele;
}
void remove(int pos)
{
    int ele = ar[pos];
    sum -= freq[ele]*freq[ele]*ele;

    freq[ele]--;
    sum += freq[ele]*freq[ele]*ele;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin>>n>>q;
    for(int i=0; i<n; i++)
        cin>>ar[i];

    for(int j=0; j<q; j++)
    {
        cin>>Q[j].l;
        cin>>Q[j].r;
        Q[j].i = j;
        Q[j].l--;
        Q[j].r--;
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

        ans[Q[i].i] = sum;
    }

    for(int i=0; i<q; i++)
       cout<<ans[i]<<"\n";

    return 0;
}
