// https://leetcode.com/problems/serialize-and-deserialize-binary-tree
#include <bits/stdc++.h>
using namespace std;
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "";
        string ans = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            if (front == NULL)
                ans += "#,";
            else
            {
                ans += to_string(front->val) + ",";
                q.push(front->left);
                q.push(front->right);
            }
        }
        // cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.length() == 0)
            return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            getline(s, str, ',');
            if (str == "#")
            {
                front->left = NULL;
            }
            else
            {
                TreeNode *temp = new TreeNode(stoi(str));
                front->left = temp;
                q.push(temp);
            }
            getline(s, str, ',');
            if (str == "#")
            {
                front->right = NULL;
            }
            else
            {
                TreeNode *temp = new TreeNode(stoi(str));
                front->right = temp;
                q.push(temp);
            }
        }
        return root;
    }
};
int main()
{

    return 0;
}