#include <bits/stdc++.h>
using namespace std;
//********* solution-1
void solve(BinaryTreeNode<int> *root, bool &sa)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left)
    {
        if (root->left->data <= root->data)
        {
            solve(root->left, sa);
        }
        else
            sa = 1;
    }
    if (root->right)
    {
        if (root->right->data >= root->data)
        {
            solve(root->right, sa);
        }
        else
            sa = 1;
    }
}
bool validateBST(BinaryTreeNode<int> *root)
{
    // Write your code here
    bool sa = 0;
    solve(root, sa);
    if (!sa)
        return true;
    else
        return false;
}
//********* solution-2
bool solve(BinaryTreeNode<int> *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data >= min && root->data <= max)
    {
        bool left = solve(root->left, min, root->data);
        bool right = solve(root->right, root->data, max);
        return left && right;
    }
    else
    {
        return false;
    }
}
bool validateBST(BinaryTreeNode<int> *root)
{
    return solve(root, INT_MIN, INT_MAX);
}
//********
int main()
{

    return 0;
}