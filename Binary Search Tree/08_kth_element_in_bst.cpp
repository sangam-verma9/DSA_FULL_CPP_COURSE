// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void inorder(TreeNode *root, int &num, int &k)
    {
        if (root == NULL)
            return;
        inorder(root->left, num, k);
        k--;
        if (k == 0)
        {
            num = root->val;
            return;
        }
        inorder(root->right, num, k);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int num = 0;
        inorder(root, num, k);
        return num;
    }
};
int main(){

return 0;
}