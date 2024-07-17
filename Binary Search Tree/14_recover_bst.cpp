// https://leetcode.com/problems/recover-binary-search-tree/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    TreeNode *firstele = NULL;
    TreeNode *secondele = NULL;
    TreeNode *prevele = new TreeNode(INT_MIN);
    void inorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        if (firstele == NULL && prevele->val > root->val)
        {
            firstele = prevele;
        }
        if (firstele != NULL && prevele->val > root->val)
        {
            secondele = root;
        }
        prevele = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        inorder(root);
        cout << firstele->val << endl;
        cout << secondele->val << endl;
        swap(firstele->val, secondele->val);
    }
};
int main()
{

    return 0;
}