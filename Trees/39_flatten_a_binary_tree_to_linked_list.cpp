// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    TreeNode *findrightmost(TreeNode *root)
    {
        if (root->right == NULL)
            return root;
        return findrightmost(root->right);
    }
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;
        TreeNode *nextright, *rightmost;
        while (root)
        {
            if (root->left)
            {
                rightmost = findrightmost(root->left);
                nextright = root->right;
                root->right = root->left;
                root->left = NULL;
                rightmost->right = nextright;
            }
            root = root->right;
        }
    }
};
int main()
{

    return 0;
}