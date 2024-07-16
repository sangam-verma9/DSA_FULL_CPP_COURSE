// https://www.geeksforgeeks.org/problems/floor-in-bst/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int floor(Node *root, int input)
    {
        if (root == NULL)
            return -1;
        int ans = -1;
        if (root->data == input)
            ans = root->data;
        else if (root->data < input)
        {
            int ans1 = root->data;
            int ans2 = root->data;
            int d = floor(root->right, input);
            if (d <= input)
                ans2 = d;
            ans = (input - ans1) < (input - ans2) ? ans1 : ans2;
        }
        else
        {
            ans = floor(root->left, input);
        }
        return ans;
    }
};
int main()
{

    return 0;
}