#include <bits/stdc++.h>
using namespace std;
void solve(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    preorder(root->left, ans);
    preorder(root->right, ans);
    ans.push_back(root->data);
}
vector<int> preorder(TreeNode *root)
{
    vector<int> ans;
    solve(root, ans);
    return ans;
}
int main()
{

    return 0;
}