// https://www.codingninjas.com/studio/problems/max-xor-queries_1382020
#include <bits/stdc++.h>
class Node
{
public:
    Node *links[2];
    Node()
    {
    }
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
vector<int> maxXorQueries(vector<int> &nums, vector<vector<int>> &queries)
{
    //	Write your coode here.
    sort(nums.begin(), nums.end());
    vector<vector<int>> que;
    for (int i = 0; i < queries.size(); i++)
    {
        vector<int> temp = {queries[i][1], queries[i][0], i};
        que.push_back(temp);
    }
    sort(que.begin(), que.end());
    vector<int> ans(queries.size(), -1);
    int ind = 0;
    Trie trie;
    for (int i = 0; i < que.size(); i++)
    {
        while (ind < nums.size() && nums[ind] <= que[i][0])
        {
            trie.insert(nums[ind]);
            ind++;
        }
        if (ind == 0)
        {
            ans[que[i][2]] = -1;
        }
        else
        {
            ans[que[i][2]] = trie.getmax(que[i][1]);
        }
    }
    return ans;
}
