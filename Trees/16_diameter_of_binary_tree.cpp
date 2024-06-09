// https://leetcode.com/problems/diameter-of-binary-tree
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int height(TreeNode *root, int &d)
    {
        if (root == NULL)
        {
            return 0;
        }
        int lefth = height(root->left, d);
        int righth = height(root->right, d);
        d = max(d, lefth + righth);
        return 1 + max(lefth, righth);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int d = 0;
        height(root, d);
        return d;
    }
};
int main()
{

    return 0;
}