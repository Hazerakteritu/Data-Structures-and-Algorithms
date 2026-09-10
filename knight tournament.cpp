#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,m;
    cin>>n>>m;
    set<int>alive;
    int result[n+1];
    for(int i=1; i<=n; i++)
    {
        alive.insert(i);
        result[i] = 0;
    }

    while(m--)
    {
        int l,r,x;
        cin>>l>>r>>x;

        set<int>::iterator it;
        it = alive.lower_bound(l);
        vector<int>loser;

        while(it!= alive.end())
        {
            int k = *it;

            if(k > r) break;
            else if(k != x)
            {
                loser.push_back(k);
                result[k] = x;
            }
            it++;
        }
        for(int i=0; i<loser.size(); i++){
            int remv = loser[i];
            alive.erase(remv);
        }
        loser.clear();
    }
    for(int i = 1; i<=n; i++) cout<<result[i]<<" ";

    return 0;
}
