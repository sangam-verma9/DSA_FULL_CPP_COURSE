// https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
#include <bits/stdc++.h>
using namespace std;
int findCeil(Node *root, int input)
{
    if (root == NULL)
        return -1;
    int ans = -1;
    if (root->data == input)
        ans = root->data;
    else if (root->data > input)
    {
        int ans1 = root->data;
        int ans2 = root->data;
        int d = findCeil(root->left, input);
        if (d >= input)
            ans2 = d;
        ans = (ans1 - input) < (ans2 - input) ? ans1 : ans2;
    }
    else
    {
        ans = findCeil(root->right, input);
    }
    return ans;
}
int main()
{

    return 0;
}