#include <bits/stdc++.h>
using namespace std;
void solve(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
vector<int> inorder(TreeNode *root)
{
    vector<int> ans;
    solve(root, ans);
    return ans;
}
int main()
{

    return 0;
}