#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mx = 10000009;

struct TrieNode
{
    int next[2];
    int cnt;

    TrieNode()
    {
        next[0] = next[1] = -1;
        cnt = 1;
    }
};

TrieNode trie[mx];
int c_node, lNode, mxlen, mxval, mxsubstr, result;
string bstr;

void initializeNode(int index)
{
    trie[index] = TrieNode();
}

void insertString()
{
    mxlen = bstr.size();
    c_node = 0;

    for (int i = 0; i < mxlen; i++)
    {
        int bit = bstr[i] - '0';

        if (trie[c_node].next[bit] == -1)
        {
            trie[c_node].next[bit] = lNode;
            initializeNode(lNode++);
            c_node = trie[c_node].next[bit];
        }
        else
        {
            c_node = trie[c_node].next[bit];
            trie[c_node].cnt++;
            mxval = (i + 1) * trie[c_node].cnt;
            result = max(result, mxval);
        }
    }

    mxsubstr = max(mxlen, mxsubstr);
}

int32_t main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        result = 0, mxval = 0, lNode = 1, mxsubstr = 0;
        initializeNode(0);

        cin >> n;
        while (n--)
        {
            cin >> bstr;
            insertString();
        }

        cout << max(result, mxsubstr) << endl;
    }

    return 0;
}
