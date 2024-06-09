// https://leetcode.com/problems/binary-tree-maximum-path-sum/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(TreeNode *root, int &ans)
    {
        if (root == NULL)
            return 0;
        int l = solve(root->left, ans);
        int r = solve(root->right, ans);
        int temp = max(max(l, r) + root->val, root->val);
        int thisSubtree = max(temp, root->val + l + r);
        ans = max(ans, thisSubtree);
        return temp;
    }
    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};
int main()
{

    return 0;
}