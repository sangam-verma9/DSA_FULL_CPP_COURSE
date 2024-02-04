// https://www.codingninjas.com/studio/problems/count-distinct-substrings_985292
class Node
{
private:
    Node *links[26];

public:
    Node()
    {
    }
    bool isContain(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void set(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
};
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    Node *root = new Node();
    int count = 0;

    for (int i = 0; i < s.length(); i++)
    {
        Node *node = root;
        for (int j = i; j < s.length(); j++)
        {
            if (!node->isContain(s[j]))
            {
                count++;
                node->set(s[j], new Node());
            }
            node = node->get(s[j]);
        }
    }
    return count + 1;
}