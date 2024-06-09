// https://www.naukri.com/code360/problems/create-binary-tree_8360671
#include <bits/stdc++.h>
using namespace std;

Node *createTree(vector<int> &arr)
{
    Node *root = new Node(arr[0]);
    root->left = new Node(arr[1]);
    root->right = new Node(arr[2]);
    root->left->left = new Node(arr[3]);
    root->left->right = new Node(arr[4]);
    root->right->left = new Node(arr[5]);
    root->right->right = new Node(arr[6]);
    return root;
}
int main()
{

    return 0;
}