#include <bits/stdc++.h>
using namespace std;
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
TreeNode *solve(vector<int> postorder, vector<int> inorder, int &index, int inorderstart, int inorderend, int n)
{
    if (index < 0 || inorderstart > inorderend)
    {
        return NULL;
    }
    int node = postorder[index];
    index--;
    TreeNode *root = new TreeNode(node);
    int position = findposition(node, inorder, n);
    // here right tree build first so right call first
    root->right = solve(postorder, inorder, index, position + 1, inorderend, n);
    root->left = solve(postorder, inorder, index, inorderstart, position - 1, n);
    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int n = postorder.size();
    int postorderindex = n - 1;
    TreeNode *ans = solve(postorder, inorder, postorderindex, 0, n - 1, n);
    return ans;
}
int main()
{

    return 0;
}