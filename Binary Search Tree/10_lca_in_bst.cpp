// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if ((root->val > p->val) && (root->val > q->val))
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        if ((root->val < p->val) && (root->val < q->val))
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};
// general method
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else if (root->val == p->val)
        {
            return p;
        }
        else if (root->val == q->val)
        {
            return q;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left == NULL && right == NULL)
        {
            return NULL;
        }
        else if (left != NULL && right == NULL)
        {
            return left;
        }
        else if (left == NULL && right != NULL)
        {
            return right;
        }
        else
        {
            return root;
        }
    }
};
int main()
{

    return 0;
}