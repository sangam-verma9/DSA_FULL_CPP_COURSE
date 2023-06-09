#include <bits/stdc++.h>
using namespace std;
//------------
int height(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}

bool isBalanced(TreeNode *root)
{
    if (root == NULL)
        return true;
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool op3 = abs(height(root->left) - height(root->right)) < 2 ? true : false;
    return (left && right && op3);
}
//------------
pair<bool, int> isBalancedfast(TreeNode *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> left = isBalancedfast(root->left);
    pair<bool, int> right = isBalancedfast(root->right);

    bool op1 = left.first;
    bool op2 = right.first;
    bool op3 = abs(left.second - right.second) < 2 ? true : false;
    pair<bool, int> ans;
    ans.first = (op1 && op2 && op3);
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
bool isBalanced(TreeNode *root)
{
    return isBalancedfast(root).first;
}
//------------
int main()
{

    return 0;
}