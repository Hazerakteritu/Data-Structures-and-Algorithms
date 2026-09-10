#include<bits/stdc++.h>
using namespace std;
#define li long long int

int main()
{
    li a,b;
    cin>>a>>b;
    // li n = b,cnt = 0;
    set<li>s;
    s.insert(b);

    while(b>=a)
    {
        if(b%2 == 0)
        {
            b=b/2;
            if(b>=a) s.insert(b);
        }
        else if(b%10 ==1)
        {
            b--;
            b/=10;
            if(b>=a) s.insert(b);
        }
        else break;
    }
    auto it = s.begin();
    int n = *it;

    if(n == a)
    {
        cout<<"YES"<<endl;
        cout<<s.size()<<endl;
        for(auto i: s) cout<< i <<" ";
    }
    else
        cout<<"NO"<<endl;

    return 0;
}
