#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    multiset<int>st;
    for(int i = 0; i <n; i++)
    {
        int a;
        cin>>a;
        st.insert(a);
        auto it = st.lower_bound(a);
        it++;
        if(it != st.end())
            st.erase(it);
    }
    cout<<st.size()<<endl;
}

