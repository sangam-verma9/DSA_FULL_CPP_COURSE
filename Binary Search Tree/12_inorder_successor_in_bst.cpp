// https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node *res = NULL;
    void help(Node *root, Node *x)
    {
        if (root == NULL)
            return;
        if (root->data <= x->data)
        {
            help(root->right, x);
        }
        else
        {
            res = root;
            help(root->left, x);
        }
    }
    Node *inOrderSuccessor(Node *root, Node *x)
    {
        help(root, x);
        return res;
    }
};
int main(){

return 0;
}