#include<bits/stdc++.h>
using namespace std;
#define int long long

int mark[3002]={0};

void prime(int n)
{
    int limit = sqrt(n)+2;

    mark[1]=1;
    for(int i=4; i<=n; i+=2 )
        mark[i]=1;

    for(int i=3; i<= limit; i+=2){
        if(mark[i]==0){
            for(int j=i*i; j<=n; j+=i*2)
                mark[j] = 1;
        }
    }
}

bool isalmostprime(int n)
{
    if(mark[n]==0) return false; //prime

    int limit = sqrt(n);

    int pdivisor = 0; //prime divisor

    for(int i=1; i<=limit; i++){
        if(n%i==0){
            int a = i;
            int b = n/i;
            if(a==b && mark[a]==0) pdivisor++;
            if(a!=b && mark[a]==0) pdivisor++;
            if(a!=b && mark[b]==0) pdivisor++;
        }
    }
    if(pdivisor == 2) return true;
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, cnt=0;
    cin>>n;
    prime(n);

    for(int i=1; i<=n; i++){
        if(isalmostprime(i)){
            cnt++;
        }
    }
    cout<<cnt<<endl;

    return 0;
}
