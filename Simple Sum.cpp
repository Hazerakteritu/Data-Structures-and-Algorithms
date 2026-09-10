#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 10000002
#define SIZE 664580
#define LIMIT 3165

int prime[SIZE], w[MAX];

void generate()
{
    int k=1, i, j, x;
    prime[0] = 2;
    for(i=2; i<MAX; i+=2)
        w[i] = 2;
    for(i=3; i<=LIMIT; i+=2)
    {
        if(w[i]==0)
        {
            prime[k++] = i;
            w[i] = i;
            for(j=i*i, x=i<<1; j<MAX; j+=x)
            {
                if (w[j]==0)
                    w[j] = i;
            }
        }
    }
    for(; i<MAX; i+=2)
    {
        if (w[i]==0)
        {
            prime[k++] = i;
            w[i] = i;
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    generate();
    int t, n, val, count;
    cin>>t;
    int ans, magic, temp, temp1, temp2;
    while (t--)
    {
        cin>>n;
        ans = 1;
        while (n!=1)
        {
            count = 0;
            val = w[n];
            magic = 1LL*val*val;
            while (n%val==0)
            {
                n /= val;
                count+=1;
            }
            temp = 0;
            temp1 = val;
            temp2 = magic;
            for(int j=0; j<count; j++)
            {
                temp += temp2 - temp1;
                temp1 = temp1*magic;
                temp2 = temp2*magic;
            }
            ans = ans*(temp+1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
