// https://www.naukri.com/code360/problems/children-sum-property_8357239
#include <bits/stdc++.h>
using namespace std;

bool isParentSum(Node *root)
{
    // Write your code here.
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    bool op1 = root->data == (root->left ? root->left->data : 0) + (root->right ? root->right->data : 0);
    bool op2 = isParentSum(root->left);
    bool op3 = isParentSum(root->right);
    return op1 && op2 && op3;
}

int main()
{

    return 0;
}