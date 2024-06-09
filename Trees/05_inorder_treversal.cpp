// https://leetcode.com/problems/binary-tree-inorder-traversal
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
        return ans;
    }
};
int main()
{

    return 0;
}