#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define pii pair<int, int>
#define mx 30000+2

void solve()
{
    string s,t;
    cin>>s>>t;

    int a = abs(s[0] - t[0]);
    int b = abs(s[1] - t[1]);
    int ans = max(a, b);
    cout<<ans<<endl;
    int dig = min(a,b);

    if(t[0]>s[0] && t[1]<s[1]) {
            for(int i=1; i<=dig; i++) cout<<"RD"<<endl;
            a-=dig;
            b-=dig;
    }else if(t[0]>s[0] && t[1]>s[1]){
        for(int i=1; i<=dig; i++) cout<<"RU"<<endl;
            a-=dig;
            b-=dig;
    }else if(t[0]<s[0] && t[1]<s[1]){
        for(int i=1; i<=dig; i++) cout<<"LD"<<endl;
            a-=dig;
            b-=dig;
    }else if(t[0]<s[0] && t[1]>s[1]){
        for(int i=1; i<=dig; i++) cout<<"LU"<<endl;
            a-=dig;
            b-=dig;
    }
    if(a!=0){
        if(s[0])
    }


    return;
}

int32_t main()
{
    int t=1, cs =1;
    //cin>>t;
    while(t--){
        solve();
    }

}
