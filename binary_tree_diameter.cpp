#include <bits/stdc++.h>
using namespace std;
//-------------
int height(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lefth = height(root->left);
    int righth = height(root->right);
    int ans = max(lefth, righth);
    return ans + 1;
}
int diameter(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int option1 = diameter(root->left);
    int option2 = diameter(root->right);
    int option3 = height(root->left) + 1 + height(root->right);
    int ans = max(option1, max(option2, option3));
    return ans;
}
//-----------------
// pair of first present diameter and second present height
pair<int, int> diameterfast(TreeNode *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = diameterfast(root->left);
    pair<int, int> right = diameterfast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + 1 + right.second;
    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
int diameter(TreeNode *root)
{
    return diameterfast(root).first;
}
//-------------
int main()
{

    return 0;
}