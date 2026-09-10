#include<bits/stdc++.h>
#define int long long

using namespace std;

int findBest(vector<int>&a,vector<vector<int>>&dp)
{
    int n=a.size();
    for(int len=1;len<=n;len++)
    {
        for(int i=0,j=len-1;j<n;i++,j++)
        {
            if(len==1)
            {
                dp[i][j]=1;
            }
            else
            {
                dp[i][j]= 1+ dp[i+1][j];
                if(a[i]==a[i+1])
                {
                    dp[i][j]=min(dp[i][j], 1+ dp[i+2][j]);
                }
                for(int k=i+2;k<=j;k++)
                {
                    if(a[i]==a[k])
                    {
                        dp[i][j]=min(dp[i][j], dp[i+1][k-1]+ dp[k+1][j]);
                    }
                }
            }
        }
    }
    return dp[0][n-1];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int>a(n);
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }
    cout<<findBest(a,dp);

}



