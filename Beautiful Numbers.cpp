#include<bits/stdc++.h>
using namespace std;
#define int long long

int mod=1e9+7;
int a,b,n;
int ans,result=1;

bool check(int s)
{
    while(s)
    {
        if(s%10!=a && s%10!=b)
            return 0;
        s/=10;
    }
    return 1;
}

int Pow(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)
            ans = ans*a%mod;
        a=a*a%mod;
        b=b/2;
        //cout<<a<<endl;
    }
    //cout<<endl;
    return ans;
}

int32_t main()
{
    cin>>a>>b>>n;
    for(int i=0; i<=n; i++)
    {
        int sum=i*a+(n-i)*b;

        if(check(sum))
        {
            ans+=result;
            ans%=mod;
        }
        result=result*(n-i)%mod;
        result=result*Pow(i+1,mod-2)%mod;
    }
    cout<<ans<<endl;
}
