// https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *solve(Node *root)
    {
        if (root == NULL)
            return NULL;
        if (root->left)
            return solve(root->left);
        return root;
    }
    int minValue(Node *root)
    {
        // Code here
        if (root == NULL)
            return -1;
        return solve(root)->data;
    }
};
int main()
{

    return 0;
}