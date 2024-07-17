// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(TreeNode *root, int k, unordered_map<int, bool> &mp, bool &ans)
    {
        if (root == NULL)
            return;
        solve(root->left, k, mp, ans);
        if (mp.find(k - root->val) != mp.end())
        {
            ans = true;
            return;
        }
        mp[root->val] = 1;
        solve(root->right, k, mp, ans);
    }
    bool findTarget(TreeNode *root, int k)
    {
        unordered_map<int, bool> mp;
        bool ans = false;
        solve(root, k, mp, ans);
        return ans;
    }
};
int main(){

return 0;
}