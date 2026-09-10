#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back


void perm(int indx, string str, vector<string>&ans)
{
    if(indx == str.size())
    {
        ans.pb(str);
        return;
    }
    for(int i=indx; i<str.size(); i++)
    {
        swap(str[i], str[indx]);
        perm(indx+1, str, ans);
        swap(str[i], str[indx]);
    }
    return;
}

int32_t main()
{
    int t=1;
    //cin>>t;
    while(t--)
    {
        string str;
        cin>>str;

        vector<string>ans;
        perm(0, str, ans);

        cout<<ans.size()<<endl;
        for(auto it: ans) cout<<it<<endl;
        cout<<endl;
    }

    return 0;
}
