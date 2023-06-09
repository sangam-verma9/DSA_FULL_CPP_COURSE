#include <bits/stdc++.h>
using namespace std;
void print_levelorder(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data;
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
}
int main()
{

    return 0;
}