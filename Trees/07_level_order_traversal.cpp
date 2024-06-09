// https://leetcode.com/problems/binary-tree-level-order-traversal
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void levelorder(TreeNode *root, vector<vector<int>> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> result;
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            if (front == NULL)
            {
                ans.push_back(result);
                result.clear();
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                result.push_back(front->val);
                if (front->left != NULL)
                {
                    q.push(front->left);
                }
                if (front->right != NULL)
                {
                    q.push(front->right);
                }
            }
        }
    }
    vector<vector<int>> levelOrder(TreeNode *root)
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