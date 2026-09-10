#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t, k = 0;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
        if(k > 0) cout << '\n';
        for(int i = 0 ; i < str.length() ; ++i)
        {
            int substr_length = i + 1;
            if(str.length() % substr_length) continue;

            // check if this substring is the one with the smallest period
            string substring(str.substr(0, substr_length));
            int times = str.length() / substring.length();
            string concat;
            for(int i = 0 ; i < times ; ++i)
            {
                concat += substring;
            }
            if(concat == str)
            {
                cout << substring.length() << '\n';
                break;
            }
        }
        ++k;
    }
    return 0;
}
