// morris Inorder traversel O(n) time complexity and O(1) space complexity
#include <bits/stdc++.h>
using namespace std;
void morrisTraversel(Node *root)
{
    if (root == NULL)
        return;
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data;
            curr = curr->right;
        }
        else
        {
            Node *pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
            {
                pre = pre->right;
            }
            if (pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre->right = NULL;
                cout << curr->data;
                curr = curr->right;
            }
        }
    }
}
int main()
{

    return 0;
}