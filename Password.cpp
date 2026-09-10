#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string pat, int M, vector<int>& lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void findSubstring(string s)
{
    int n = s.length();
    vector<int> lps(n, 0);

    computeLPSArray(s, n, lps);

    int len = lps[n - 1];

    if (len == 0)
    {
        cout << "Just a legend" << endl;
        return;
    }

    while (len > 0)
    {

        for (int i = 0; i < n - 1; i++)
        {
            if (lps[i] == len)
            {
                cout << s.substr(0, len) << endl;
                return;
            }
        }
        // If not found, reduce the length and check again
        len = lps[len - 1];
    }

    cout << "Just a legend" << endl;
}

int main()
{
    string s;
    cin >> s;
    findSubstring(s);
    return 0;
}
