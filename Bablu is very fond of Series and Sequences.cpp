//Fibonacci Series
//a[0] = a[1] = 0
//For n > 1, a[n] = a[n - 1] + f(n), where f(n) is smallest prime factor of n.

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define N 10000007

int factor[N]= {0};
int res[N];

void sieve()
{
    for(int i=2; i<N; i++)
    {
        if(!factor[i])
        {
            factor[i] = i;
            for(int j= i*i; j<N; j+=i)
            {
                if(!factor[j])
                    factor[j]=i;
            }
        }
        res[i]=res[i-1]+factor[i];
    }
}

int32_t main()
{
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<res[n]<<endl;
    }

    return 0;
}
