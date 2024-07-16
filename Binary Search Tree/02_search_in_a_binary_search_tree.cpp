// https://leetcode.com/problems/search-in-a-binary-search-tree/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (val == root->val)
        {
            return root;
        }
        else if (val < root->val)
        {
            return searchBST(root->left, val);
        }
        else if (val > root->val)
        {
            return searchBST(root->right, val);
        }
        return NULL;
    }
};
int main()
{

    return 0;
}