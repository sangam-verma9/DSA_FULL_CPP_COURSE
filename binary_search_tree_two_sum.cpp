// you are given a binary tree and target value you need to find wheather there exists pair of nodes such their sum if equal to target.
#include <bits/stdc++.h>
using namespace std;
void inorder(BinaryTreeNode<int> *root, vector<int> &inorderval)
{
    if (root == NULL)
        return;
    inorder(root->left, inorderval);
    inorderval.push_back(root->data);
    inorder(root->right, inorderval);
}
bool twoSumInBST(BinaryTreeNode<int> *root, int target)
{
    vector<int> inorderval;
    inorder(root, inorderval);
    int i = 0, j = inorderval.size() - 1;
    while (i < j)
    {
        if (inorderval[i] + inorderval[j] == target)
        {
            return true;
        }
        else if (inorderval[i] + inorderval[j] > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}
int main()
{

    return 0;
}