// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    TreeNode *solve(int &ind, vector<int> &preorder, int upperbound)
    {
        if (ind >= preorder.size() || preorder[ind] > upperbound)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[ind++]);
        root->left = solve(ind, preorder, root->val);
        root->right = solve(ind, preorder, upperbound);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int ind = 0;
        return solve(ind, preorder, INT_MAX);
    }
};
// general method
class Solution
{
public:
    TreeNode *solve(int &ind, int n, int i, int j, vector<int> &inorder, vector<int> &preorder)
    {
        if (ind >= n)
            return NULL;
        if (i > j)
            return NULL;
        TreeNode *root = new TreeNode(preorder[ind]);
        int k = i;
        for (; k <= j; k++)
        {
            if (inorder[k] == preorder[ind])
            {
                break;
            }
        }
        ind++;
        root->left = solve(ind, n, i, k - 1, inorder, preorder);
        root->right = solve(ind, n, k + 1, j, inorder, preorder);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        int ind = 0;
        return solve(ind, preorder.size(), 0, inorder.size() - 1, inorder, preorder);
    }
} int main()
{

    return 0;
}