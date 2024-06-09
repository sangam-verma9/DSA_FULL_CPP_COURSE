// https://leetcode.com/problems/binary-tree-preorder-traversal
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->left == NULL)
            {
                ans.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                TreeNode *prev = cur->left;
                while (prev->right && prev->right != cur)
                {
                    prev = prev->right;
                }
                if (prev->right == NULL)
                {
                    prev->right = cur;
                    ans.push_back(cur->val);
                    cur = cur->left;
                }
                else
                {
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}