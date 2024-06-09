// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        map<int, int> topnode;
        queue<pair<Node *, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty())
        {
            pair<Node *, int> temp = q.front();
            q.pop();
            Node *frontNode = temp.first;
            int hd = temp.second;
            if (topnode.find(hd) == topnode.end())
            {
                topnode[hd] = frontNode->data;
            }
            if (frontNode->left != NULL)
            {
                q.push(make_pair(frontNode->left, hd - 1));
            }
            if (frontNode->right != NULL)
            {
                q.push(make_pair(frontNode->right, hd + 1));
            }
        }
        for (auto i : topnode)
        {
            ans.push_back(i.second);
        }
    }
};
int main(){

return 0;
}