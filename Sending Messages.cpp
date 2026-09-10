#include<bits/stdc++.h>;
using namespace std;
#define lli long long int

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        /* four integers n, f, a, and b — the number of messages, the initial phone's charge,
         the charge consumption per unit of time, and the consumption when turned off and on sequentially.
        */
        lli n,f,a,b;
        cin>>n>>f>>a>>b;
        lli m[n+1];  //including 0
        m[0]=0;
        for(int i=1; i<=n; i++){
            cin>>m[i];
            lli d = abs(m[i]-m[i-1]);
            if(d*a<b) f-=d*a;
            else f-=b;
        }
        if(f>0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }

    return 0;
}
