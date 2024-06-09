// https://leetcode.com/problems/count-complete-tree-nodes
#include <bits/stdc++.h>
using namespace std;
// TC--- O(log(n)^2)
class Solution
{
public:
    int findlefth(TreeNode *root)
    {
        int ans = 0;
        while (root)
        {
            ans++;
            root = root->left;
        }
        return ans;
    }
    int findrighth(TreeNode *root)
    {
        int ans = 0;
        while (root)
        {
            ans++;
            root = root->right;
        }
        return ans;
    }
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int lefth = findlefth(root);
        int righth = findrighth(root);
        if (lefth == righth)
            return (1 << lefth) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
int main()
{

    return 0;
}