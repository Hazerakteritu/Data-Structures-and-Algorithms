#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
#define piii pair<pii, int>
#define f first
#define s second
#define MX 1000000+6
#define N 2000000 + 2
#define inf 1e18
const int mod = 1000000007;


vector<int>fact(N + 5);
vector<int>invFact(N + 5);

int binExpo(int base, int p)
{
    int ans = 1;
    while(p)
    {
        if(p & 1)
        {
            ans = (ans*base)%mod;
            p--;
        }
        else
        {
            base = (base*base)%mod;
            p/=2;
        }
    }
    return ans;
}

void facto()
{
    fact[0] = fact[1] = 1;
    for(int i=2; i<N; i++)
    {
        fact[i] = ((fact[i-1]%mod)*(i%mod))%mod;
    }

    invFact[N-1] = binExpo(fact[N-1], mod -2);

    for(int i=N-1; i>0; i--)
    {
        invFact[i-1] = ((invFact[i]%mod) * (i%mod))%mod;
    }
}


int nCr(int n, int r)
{
    if(r>n) return 0;

    int up = fact[n];
    int down = ((invFact[r]%mod) * (invFact[n-r]%mod))%mod;

    int ans = ((up%mod)* (down % mod))%mod;

    return ans;
}

void solve()
{
    int n,m;
    cin>>n>>m;


    int sum = n+m-1;


    int ans = nCr(sum,m);

    cout<<ans<<endl;
}

int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    facto();

    int t = 1, cs = 1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
}



//vector<int>primes;
//vector<int>isPrime(N+10, 1);
//
//void pre()
//{
//    isPrime[0] =  isPrime[1] = 0;
//    for(int i = 4; i<=N; i+=2)
//    {
//        isPrime[i] = 0;
//    }
//
//    for(int i=3; i*i<=N; i+=2)
//    {
//        if(isPrime[i])
//        {
//            for(int j= i*i; j<=N; j+=i)
//            {
//                isPrime[j] = 0;
//            }
//        }
//    }
//    primes.pb(2);
//
//    for(int i=3; i<=N; i+=2)
//    {
//        if(isPrime[i])
//        {
//            primes.pb(i);
//            //cout<<i<<" ";
//        }
//    }
//}
