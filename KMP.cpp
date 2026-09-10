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
            cout<<"Index -> "<< i-pattern.length() <<endl;
            //break;
            j = lps[j-1];
        }
    }
    if(found) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string text, pattern;
    //cin>>text>>pattern;
    getline(cin, text);
    getline(cin, pattern);

    kmp(text, pattern);

    return 0;
}

/*_____input_____
This is a test
is
_____output_____
Index -> 2
Index -> 5
Found
*/
