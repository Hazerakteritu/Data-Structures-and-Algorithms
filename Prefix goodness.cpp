#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 2; // Binary strings (0, 1)

struct trieNode
{
    bool isEndOfWord;
    int count; // Number of strings passing through this node
    trieNode *children[ALPHABET_SIZE];
};

struct trieNode *getNode()
{
    struct trieNode *pNode = new trieNode;
    pNode->isEndOfWord = false;
    pNode->count = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        pNode->children[i] = NULL;
    }
    return pNode;
}

void insert(trieNode *root, const string &key)
{
    struct trieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - '0';
        if (!pCrawl->children[index])
        {
            pCrawl->children[index] = getNode();
        }
        pCrawl = pCrawl->children[index];
        pCrawl->count++;
    }
    pCrawl->isEndOfWord = true;
}

int calculateGoodness(trieNode *node, int depth)
{
    if (!node) return 0;

    int currentGoodness = depth * node->count;

    int leftGoodness = calculateGoodness(node->children[0], depth + 1);
    int rightGoodness = calculateGoodness(node->children[1], depth + 1);

    return max({currentGoodness, leftGoodness, rightGoodness});
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;

        struct trieNode *root = getNode();

        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            insert(root, s);
        }

        int maxGoodness = calculateGoodness(root, 0);
        cout << maxGoodness << "\n";

        delete root;
    }

    return 0;
}
