// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void levelorder(TreeNode *root, vector<vector<int>> &ans)
    {
        vector<int> temp;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        bool ltor = true;
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            if (front == NULL)
            {
                if (ltor)
                {
                    ans.push_back(temp);
                }
                else
                {
                    reverse(temp.begin(), temp.end());
                    ans.push_back(temp);
                }
                temp.clear();
                ltor = !ltor;
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                temp.push_back(front->val);
                if (front->left)
                {
                    q.push(front->left);
                }
                if (front->right)
                {
                    q.push(front->right);
                }
            }
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }
        vector<vector<int>> ans;
        levelorder(root, ans);
        return ans;
    }
};
int main()
{

    return 0;
}