// Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.
// An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.
#include <bits/stdc++.h>
using namespace std;
int sum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = 0, right = 0;
    if (root->left != NULL)
    {
        left = sum(root->left);
    }
    if (root->right != NULL)
    {
        right = sum(root->right);
    }
    return left + right + root->data;
}
bool isSumTree(Node *root)
{
    // Your code here
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return true;
    }
    bool left = isSumTree(root->left);
    bool right = isSumTree(root->right);
    bool op3 = (sum(root->left) + sum(root->right) == root->data) ? true : false;
    return (left && right && op3);
}
int main()
{

    return 0;
}
