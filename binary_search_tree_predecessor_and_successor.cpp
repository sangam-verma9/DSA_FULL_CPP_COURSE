#include <bits/stdc++.h>
using namespace std;
pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    // find key
    BinaryTreeNode<int> *temp = root;
    int pred = -1, succ = -1;
    while (temp->data != key)
    {
        if (temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }
        else
        {
            pred = temp->data;
            temp = temp->right;
        }
    }

    // find pred succ
    BinaryTreeNode<int> *temp1 = temp->left;
    while (temp1 != NULL)
    {
        pred = temp1->data;
        temp1 = temp1->right;
    }
    BinaryTreeNode<int> *temp2 = temp->right;
    while (temp2 != NULL)
    {
        succ = temp2->data;
        temp2 = temp2->left;
    }
    pair<int, int> ans = make_pair(pred, succ);
    return ans;
}
int main()
{

    return 0;
}