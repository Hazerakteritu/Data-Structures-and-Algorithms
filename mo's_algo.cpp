#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define block 600 //square root of maximum Number of element
struct query
{
    int l;
    int r;
    int i;
};
query Q[200001]; //array of query
int ar[30001], ans[200001];
int freq[1000005];
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
    fast_io;
    int n,q;
    cin>>n;

    /*map<int,int> coordinateCompress;
   int compressed_Num = 1;

   for(int i = 0; i < n; i++)
   {
       cin >> ar[i];
       if(coordinateCompress.find(ar[i]) != coordinateCompress.end()){
        ar[i] = coordinateCompress[ar[i]];
       }
       else{
        coordinateCompress[ar[i]] = compressed_Num;
        ar[i] = compressed_Num++;
       }
   }*/
   for(int i=0; i<n; i++) cin>>ar[i];

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
