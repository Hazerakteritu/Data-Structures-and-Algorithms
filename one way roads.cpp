#include<bits/stdc++.h>
using namespace std;

int Lvis[101];
int Rvis[101];

int main()
{
    int t;
    cin>>t;

    for(int tt = 1; tt <= t; tt++)
    {
        int n,ans=0;
        cin>>n;

        int Lvis[n+1]={0};
        int Rvis[n+1]={0};

        int lweight = 0, rweight = 0;
        for(int i = 0; i < n; i++)
        {
            int a,b,c;
            cin>>a>>b>>c;

            if(Lvis[a]==0 && Rvis[b]==0)
            {
                Lvis[a] = 1;
                Rvis[b] = 1;
                lweight += c;
            }
            else
            {
                Rvis[a] = 1;
                Lvis[b] = 1;
                rweight += c;
            }
        }
        ans = min(lweight,rweight);
        cout<<"Case "<<tt<<": "<<ans<<endl;
    }

    return 0;
}
