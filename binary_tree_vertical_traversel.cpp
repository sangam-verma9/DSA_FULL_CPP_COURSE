// Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
// If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.
#include <bits/stdc++.h>
using namespace std;
vector<int> verticalOrder(Node *root)
{
    // Your code here
    map<int, map<int, vector<int>>> nodes; // map of hd ,map of level ,nodes
    queue<pair<Node *, pair<int, int>>> q; // pair of node , pair of hd, level
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();
        Node *frontnode = temp.first;
        int hdis = temp.second.first;
        int level = temp.second.second;
        nodes[hdis][level].push_back(frontnode->data);
        if (temp.first->left)
        {
            q.push(make_pair(temp.first->left, make_pair(hdis - 1, level + 1)));
        }
        if (temp.first->right)
        {
            q.push(make_pair(temp.first->right, make_pair(hdis + 1, level + 1)));
        }
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}
int main()
{

    return 0;
}