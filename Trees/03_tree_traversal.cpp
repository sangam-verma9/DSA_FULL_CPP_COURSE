// https://www.naukri.com/code360/problems/tree-traversal_981269
#include <bits/stdc++.h>
using namespace std;
void solve1(TreeNode *root, vector<int> &a)
{
    if (root == NULL)
        return;
    solve1(root->left, a);
    a.push_back(root->data);
    solve1(root->right, a);
}
void solve2(TreeNode *root, vector<int> &a)
{
    if (root == NULL)
        return;
    a.push_back(root->data);
    solve2(root->left, a);
    solve2(root->right, a);
}
void solve3(TreeNode *root, vector<int> &a)
{
    if (root == NULL)
        return;
    solve3(root->left, a);
    solve3(root->right, a);
    a.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> inorder, preorder, postorder;
    solve1(root, inorder);
    solve2(root, preorder);
    solve3(root, postorder);
    vector<vector<int>> ans = {inorder, preorder, postorder};
    return ans;
}
int main()
{

    return 0;
}