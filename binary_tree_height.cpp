#include <bits/stdc++.h>
using namespace std;
int height(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    int ans = max(leftheight, rightheight) + 1;
    return ans;
}
int main()
{

    return 0;
}