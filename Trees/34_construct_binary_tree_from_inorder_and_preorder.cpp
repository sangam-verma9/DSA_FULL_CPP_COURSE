// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findposition(int node, vector<int> inorder, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (inorder[i] == node)
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode *solve(vector<int> preorder, vector<int> inorder, int &index, int inorderstart, int inorderend, int n)
    {
        if (index >= n || inorderstart > inorderend)
        {
            return NULL;
        }
        int node = preorder[index];
        index++;
        TreeNode *root = new TreeNode(node);
        int position = findposition(node, inorder, n);
        root->left = solve(preorder, inorder, index, inorderstart, position - 1, n);
        root->right = solve(preorder, inorder, index, position + 1, inorderend, n);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        int preorderindex = 0;
        TreeNode *ans = solve(preorder, inorder, preorderindex, 0, n - 1, n);
        return ans;
    }
};
int main()
{

    return 0;
}