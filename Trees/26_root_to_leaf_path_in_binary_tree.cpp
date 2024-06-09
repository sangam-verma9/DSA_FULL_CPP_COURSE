// https://www.naukri.com/code360/problems/all-root-to-leaf-paths-in-binary-tree._983599
#include <bits/stdc++.h>
using namespace std;
void solve(BinaryTreeNode<int> *root, string s, vector<string> &ans)
{
    if (root == NULL)
        return;
    s += to_string(root->data) + " ";
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(s);
        return;
    }
    solve(root->left, s, ans);
    solve(root->right, s, ans);
}
vector<string> allRootToLeaf(BinaryTreeNode<int> *root)
{
    // Write your code here.
    vector<string> ans;
    solve(root, "", ans);
    return ans;
}
int main()
{

    return 0;
}