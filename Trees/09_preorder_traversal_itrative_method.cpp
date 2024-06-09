#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    vector<int> preorderTraversel(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        stack<Node *> st;
        st.push(root);
        while (!st.empty())
        {
            Node *root = st.top();
            st.pop();
            ans.push_back(root->data);
            if (root->right)
            {
                st.push(root->right);
            }
            if (root->left)
            {
                st.push(root->left);
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}