#include <bits/stdc++.h>
using namespace std;
bool isNodePresent(Node *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    if (x > root->data)
    {
        return isNodePresent(root->right, x);
    }
    else
    {
        return isNodePresent(root->left, x);
    }
}
int main()
{

    return 0;
}