#include <bits/stdc++.h>
using namespace std;
class Solutin
{
public:
    vector<int> inorderTraversal(Node *root)
    {
        stcak<Node *> st;
        Node *temp = root;
        vector<int> ans;
        while (true)
        {
            if (temp != NULL)
            {
                st.push(temp);
                temp = temp->left;
            }
            else
            {
                if (st.empty() == true)
                    break;
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                temp = temp->right;
            }
        }
        return
    }
};
int main()
{

    return 0;
}