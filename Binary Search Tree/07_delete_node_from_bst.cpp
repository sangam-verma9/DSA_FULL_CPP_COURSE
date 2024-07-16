// https://leetcode.com/problems/delete-node-in-a-bst
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
        {
            return root;
        }
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }

        // now perform deletion
        // if one child is absent
        if (root->left == NULL)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }
        // if both child present
        else
        {
            TreeNode *succpar = root;
            TreeNode *succ = root->right;
            while (succ->left != NULL)
            {
                succpar = succ;
                succ = succ->left;
            }
            if (succpar != root)
            {
                succpar->left = succ->right;
            }
            else
            {
                succpar->right = succ->right;
            }
            root->val = succ->val;
            delete succ;
            return root;
        }
    }
};
int main(){

return 0;
}