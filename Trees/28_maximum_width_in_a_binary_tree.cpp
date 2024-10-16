// https://leetcode.com/problems/maximum-width-of-binary-tree/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        if (root == NULL)
            return ans;
        queue<pair<TreeNode *, long long>> q; // node,index
        q.push({root, 0});
        while (!q.empty())
        {
            int s = q.size();
            long long left = 0, right = 0;
            long long minIndex = q.front().second; //parent index
            for (int i = 0; i < s; i++)
            {
                auto [node, index] = q.front();
                q.pop();
                index -= minIndex; // do this for overflowing values => make reference to 0
                if (i == 0)
                    left = index;
                if (i == s - 1)
                    right = index;

                if (node->left)
                {
                    q.push({node->left, 2 * index});
                }
                if (node->right)
                {
                    q.push({node->right, 2 * index + 1});
                }
            }
            ans = max(ans, int(right - left + 1));
        }
        return ans;
    }
};
int main(){

return 0;
}