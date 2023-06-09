#include <bits/stdc++.h>
using namespace std;
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q == NULL)
    {
        return true;
    }
    else if (p == NULL && q != NULL)
    {
        return false;
    }
    else if (p != NULL && q == NULL)
    {
        return false;
    }
    bool check = p->val == q->val ? true : false;
    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);
    if (check && left && right)
    {
        return true;
    }
    else
        return false;
}
int main()
{

    return 0;
}