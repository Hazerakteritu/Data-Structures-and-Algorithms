#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
#define piii pair<pii, int>
#define f first
#define s second
#define MX 100000+6
#define N 2000 + 2
#define inf 1e18
const int mod = 1000000007;


void solve()
{
    int n;
    cin>>n;

    for(int i=1; i<n; i++){
        int a;
        cin>>a;

        if(a%2){
            cout<<a+1<<endl;
        }else cout<<a-1<<endl;

        cout.flush();
    }

}

int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


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
