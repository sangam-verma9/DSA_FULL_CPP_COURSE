// https://leetcode.com/problems/maximum-depth-of-binary-tree/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
int main()
{

    return 0;
}