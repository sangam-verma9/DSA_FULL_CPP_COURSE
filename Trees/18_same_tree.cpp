// https://leetcode.com/problems/same-tree
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
        {
            return true;
        }
        else if (p != NULL && q == NULL)
        {
            return false;
        }
        else if (p == NULL && q != NULL)
        {
            return false;
        }
        else
        {
            if (p->val == q->val)
            {
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
            else
            {
                return false;
            }
        }
    }
};
int main()
{

    return 0;
}