#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
const int INF = 1e17;


void solve(int a,int b)
{
    int tmp,flag=0;
    int x1=1,y1=0,x2=0,y2=1;

    while(a%b)
    {
        if(flag)
        {
            x2-= a/b*x1;
            y2-= a/b*y1;
        }
        else
        {
            x1-= a/b*x2;
            y1-= a/b*y2;
        }
        tmp=a;
        a=b;
        b=tmp%b;
        flag^=1;
    }

    if(flag)
        cout<<x1<<" "<<y1;
    else
        cout<<x2<<" "<<y2;

    cout<<" "<<b<<endl;

    return;
}

int32_t main()
{
    int a,b;
    while(cin>>a>>b)
        solve(a,b);

    return 0;
}
