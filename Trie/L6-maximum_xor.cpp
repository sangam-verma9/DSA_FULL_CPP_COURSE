// https://www.codingninjas.com/studio/problems/maximum-xor_973113
class Node
{
public:
    Node *links[2];
    bool isContains(int i)
    {
        return (links[i] != NULL);
    }
    Node *get(int i)
    {
        return links[i];
    }
    void set(int i, Node *node)
    {
        links[i] = node;
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
    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->isContains(bit))
            {
                node->set(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getmax(int num)
    {
        Node *node = root;
        int maxi = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = !((num >> i) & 1);
            if (node->isContains(bit))
            {
                maxi = maxi | (1 << i);
                node = node->get(bit);
            }
            else
            {
                node = node->get(!bit);
            }
        }
        return maxi;
    }
};
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    // Write your code here.
    Trie trie;
    for (auto it : arr1)
    {
        trie.insert(it);
    }
    int maxXOR = 0;
    for (auto it : arr2)
    {
        maxXOR = max(maxXOR, trie.getmax(it));
    }
    return maxXOR;
}
