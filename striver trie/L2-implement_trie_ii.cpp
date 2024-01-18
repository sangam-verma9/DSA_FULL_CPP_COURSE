#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
    bool cointainKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    void increasePrefix()
    {
        cntPrefix++;
    }
    void increseEndWith()
    {
        cntEndWith++;
    }
    int getEnd()
    {
        return cntEndWith;
    }
    int getPrefixcnt()
    {
        return cntPrefix;
    }
    void reducePrefix()
    {
        cntPrefix--;
    }
    void deleteEnd()
    {
        cntEndWith--;
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->cointainKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increseEndWith();
    }

    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->cointainKey(word[i]))
            {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->cointainKey(word[i]))
            {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getPrefixcnt();
    }

    void erase(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->cointainKey(word[i]))
            {
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else
                return;
        }
        node->deleteEnd();
    }
};

int main() {

return 0;
}