// https://www.geeksforgeeks.org/problems/largest-bst/1
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    struct Info
    {
        bool isBST;
        int size;
        int min;
        int max;
    };

    Info solve(Node *root, int &res)
    {
        if (root == NULL)
        {
            return {true, 0, INT_MAX, INT_MIN}; // Empty tree is a BST
        }

        Info leftInfo = solve(root->left, res);
        Info rightInfo = solve(root->right, res);

        Info curr;
        curr.size = 1 + leftInfo.size + rightInfo.size;

        // Check if current subtree is BST
        if (leftInfo.isBST && rightInfo.isBST &&
            root->data > leftInfo.max && root->data < rightInfo.min)
        {
            curr.isBST = true;
            curr.min = min(root->data, leftInfo.min);
            curr.max = max(root->data, rightInfo.max);

            res = max(res, curr.size); // Update the result with the size of the current BST
        }
        else
        {
            curr.isBST = false;
        }

        return curr;
    }

    int largestBst(Node *root)
    {
        int res = 0;
        solve(root, res);
        return res;
    }
};

int main(){

return 0;
}