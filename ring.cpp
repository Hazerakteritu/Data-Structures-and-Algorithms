#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int str[n+5] = {0},des[n+5]= {0};
    int ans1=0,ans2=0;
    while(n--)
    {
        int a,b,c;
        cin>>a>>b>>c;

        if(str[a]==0 && des[b]==0)
        {
            ans1+=c;
            str[a]=1;
            des[b]=1;
        }
        else
        {
            ans2+=c;
            str[b]=1;
            des[a] = 1;
        }
    }
    int ans = min(ans1,ans2);
    cout<<ans<<endl;

    return 0;
}
