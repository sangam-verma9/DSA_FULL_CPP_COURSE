// Given a binary tree of size  N, a node, and a positive integer k., Your task is to complete the function
// kthAncestor(), the function should return the kth ancestor of the given node i
// the binary tree. If there does not exist any such ancestor then return -1.
#include <bits/stdc++.h>
using namespace std;
/*
void solve(Node *root, int k, int node, vector<int> v, int &ans)
{
    if (root == NULL)
    {
        return;
    }
    v.push_back(root->data);
    if (root->data == node)
    {
        int size = v.size() - 1;
        ans = v[size - k];
    }
    solve(root->left, k, node, v, ans);
    solve(root->right, k, node, v, ans);
    v.pop_back();
}
int kthAncestor(Node *root, int k, int node)
{
    vector<int> v;
    int ans = -1;
    solve(root, k, node, v, ans);
}
*/

Node *solve(Node *root, int node, int k)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == node)
    {
        return root;
    }
    Node *left = solve(root->left, node, k);
    Node *right = solve(root->right, node, k);
    if (left != NULL && right == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return left;
    }
    else if (left == NULL && right != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return right;
    }
    else
        return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node *ans = solve(root, node, k);
    if (ans == NULL || ans->data == node)
    {
        return -1;
    }
    return ans->data;
}

int main()
{

    return 0;
}
