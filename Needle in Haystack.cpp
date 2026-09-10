#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int>createlps(string pattern)
{
    vector<int>lps(pattern.length());
    int indx = 0;
    for(int i=1; i<pattern.length(); )
    {
        if(pattern[indx]==pattern[i])
        {
            lps[i] = indx + 1;
            indx++;
            i++;
        }
        else if(indx == 0)
        {
            lps[i] = 0;
            i++;
        }
        else
        {
            indx = lps[indx-1];
        }
    }
    return lps;
}
void kmp(string text, string pattern)
{
    bool found = false;

    vector<int>lps = createlps(pattern);
    int i=0, j=0;      //i->text , j->pattern
    while(i<text.length())
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0) j= lps[j-1];
            else i++;
        }

        if(j == pattern.length())
        {
            //cout<<"Found"<<endl;
            found = true;
            cout<< i-pattern.length() <<endl;
            //break;
            j = lps[j-1];
        }
    }

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, f=0;
    while(cin>>n){
        string pattern, text;
    cin>>pattern>>text;

    //getline(cin, pattern);
    //getline(cin, text);

    if(f){
       cout<<endl;
    }

    kmp(text, pattern);
    f = 1;
    }

    return 0;
}

