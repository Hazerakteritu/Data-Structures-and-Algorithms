#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 10000010
#define pi pair<int,int>

void solve()
{
    ll x;
    cin>>x;
    //int d = sqrt(1- 4*3*(-x*2));

    //int ans = (1 + d)/(2*3);
    ll ans =0;

    while(x>= (3*(ans+1)-1)){
        ans++;
        x-=3*ans -1;
    }
    cout<<ans<<endl;

}


int main()
{
    string str;
    getline(cin,str);
    cout<<

    return 0;
}

