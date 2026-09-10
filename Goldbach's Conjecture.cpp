#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7+10;

vector<int> prime;
bool mark[N];

void sieve()
{
    for(int i=2; i*i<=N; i++)
    {
        if(!mark[i])
        {
            for(int j=i*i; j<=N; j+=i)
            {
                mark[j]=1;
            }
        }
    }
    for(int i=2; i<=N; i++)
    {
        if(mark[i]==0) prime.push_back(i);
    }

}


int32_t main()
{
    sieve();

    int t;
    cin>>t;
    for(int tt=1; tt<=t; tt++)
	{
		int n;
        cin>>n;
        int cnt=0;
        for(int i= 0; prime[i]<=(n/2); i++)
		{
            int a = prime[i];
			int b = n - a;

            if(mark[b]==0) cnt++; //if b prime cnt++;
        }
		cout<<"Case "<<tt<<": "<<cnt<<endl;
    }

}
