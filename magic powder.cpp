#include<bits/stdc++.h>
using namespace std;
#define li long long int

int main()
{
    int n,k;
    cin>>n>>k;
    int ary[n],bry[n];
    for(int i=0; i<n; i++) cin>>ary[i];
    for(int i=0; i<n; i++)
    {
        cin>>bry[i];
    }
    int need = 0,val = 0;
    while(1)
    {
        for(int i=0; i<n; i++)
        {
            if(bry[i]>=ary[i]) bry[i]-= ary[i];
            else
            {
                k -= (ary[i]-bry[i]);
                bry[i]=0;
            }
        }
        if(k>=0) val++;
        else break;
    }
    cout<<val<<endl;

    return 0;
}
