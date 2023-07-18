// The "linked list" should use the same Node class where the right child pointer points to the next   node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre - order traversal of the binary tree.
#include <bits/stdc++.h>
using namespace std;
void flattenToLinkedlist(Node *root)
{
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left != NULL)
        {
            Node *pred = curr->left;
            while (pred->right)
            {
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}
int main()
{

    return 0;
}