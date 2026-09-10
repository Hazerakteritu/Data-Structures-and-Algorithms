#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generate(const string& rule, const vector<string>& dictionary, string current, int pos)
{
    if (pos == rule.size())
    {
        cout << current << endl;
        return;
    }

    if (rule[pos] == '#')
    {
        for (const string& word : dictionary)
        {
            generate(rule, dictionary, current + word, pos + 1);
        }
    }
    else if (rule[pos] == '0')
    {
        for (char digit = '0'; digit <= '9'; ++digit)
        {
            generate(rule, dictionary, current + digit, pos + 1);
        }
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<string> dictionary(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> dictionary[i];
        }

        // Next line: number of rules
        int m;
        cin >> m;
        vector<string> rules(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> rules[i];
        }

        cout << "--" << endl;

        for (const string& rule : rules)
        {
            generate(rule, dictionary, "", 0);
        }
    }

    return 0;
}
