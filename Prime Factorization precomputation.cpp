
/*
// ...........Calculating SPF (Smallest Prime Factor) for every number till MAXN................
// Time Complexity : O(nloglogn)
vector<int>spf(N + 1, 1);
void sieve()
{
    // stores smallest prime factor for every number
    spf[0] = 0;
    for (int i = 2; i <= N; i++)
    {
        if (spf[i] == 1)   // if the number is prime ,mark
        {
            // all its multiples who havent gotten their spf yet
            for (int j = i; j <= N; j += i)
            {
                if (spf[j]== 1) // if its smallest prime factor is
                    // 1 means its spf hasnt been
                    // found yet so change it to i
                    spf[j] = i;
            }
        }
    }
}


// A O(log n) function returning primefactorization
vector<int>getFactorization(int x)
{
    vector<int> ret;

    set<int>st;
    while (x != 1)
    {
        //ret.push_back(spf[x]);
        st.insert(spf[x]);
        x = x / spf[x];
    }
    for(auto it: st) ret.pb(it);

    return ret;
}

int main(int argc, char const* argv[])
{
    // precalculating Smallest Prime Factor
    sieve();
    int x = 12246;
    cout << "prime factorization for " << x << " : ";

    // calling getFactorization function
    vector<int> p = getFactorization(x);

    for (int i = 0; i < p.size(); i++)
        cout << p[i] << " ";
    cout << endl;
    return 0;
}

*/




//................compare funtion............

//bool comp(pii a, pii b)
//{
//    if(a.first == b.first)
//        return a.second < b.second;
//    return a.first < b.first;
//}







//.................prime generate....................

//int mark[N];
//vector<int>prime;
//
//void primefact()
//{
//    int limit = sqrt(N+1);
//    mark[0] = 1;
//    mark[1] = 1;
//    for(int i = 4; i<N; i+=2)
//        mark[i] = 1;
//
//    for(int i=3; i<=limit; i+=2)
//    {
//        if(mark[i] == 0)
//        {
//            for(int j=i*i; j<N; j+=i)
//            {
//                mark[j]=1;
//            }
//        }
//    }
//    for (int i=2; i<N; i++)
//    {
//        if (mark[i] == 0)
//        {
//            prime.pb(i);
//            //cout<<i<<endl;
//        }
//    }
//
//
//    //for(int i=0; i<1000; i++) cout<<prime[i]<<endl;
//}
