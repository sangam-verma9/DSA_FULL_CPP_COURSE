// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else if (root->val == p->val || root->val == q->val)
        {
            return root;
        }
        TreeNode *leftans = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightans = lowestCommonAncestor(root->right, p, q);
        if (leftans != NULL && rightans != NULL)
        {
            return root;
        }
        else if (leftans != NULL && rightans == NULL)
        {
            return leftans;
        }
        else if (leftans == NULL && rightans != NULL)
        {
            return rightans;
        }
        else
        {
            return NULL;
        }
    }
};
int main()
{

    return 0;
}