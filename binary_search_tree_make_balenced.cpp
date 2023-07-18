#include <bits/stdc++.h>
using namespace std;
void inorder(TreeNode<int> *root, vector<int> &inorderval)
{
    if (root == NULL)
        return;
    inorder(root->left, inorderval);
    inorderval.push_back(root->data);
    inorder(root->right, inorderval);
}
TreeNode<int> *inorderToBST(vector<int> inorderval, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    TreeNode<int> *root = new TreeNode<int>(inorderval[mid]);
    root->left = inorderToBST(inorderval, 0, mid - 1);
    root->right = inorderToBST(inorderval, mid + 1, e);
    return root;
}
TreeNode<int> *balancedBst(TreeNode<int> *root)
{
    vector<int> inorderval;
    inorder(root, inorderval);
    return inorderToBST(inorderval, 0, inorderval.size() - 1);
}
int main()
{

    return 0;
}