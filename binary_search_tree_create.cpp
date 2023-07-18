#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *createNode(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = createNode(root->right, data);
    }
    else
    {
        root->left = createNode(root->left, data);
    }
    return root;
}
void insertNode(Node *&root)
{
    cout << "enter data";
    int n;
    cin >> n;
    while (n != -1)
    {
        createNode(root, n);
        cin >> n;
    }
}

Node *maxvalue(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node *minvalue(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

// delete a node in bst
Node *deleteNode(Node *root, int x)
{
    if (root == NULL)
        return root;
    if (root->data == x)
    {
        // case-1 node is leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // case-2 right child is null
        else if (root->left && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // case-3 left child is null
        else if (root->left == NULL && root->right)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // case-4 left and right both are not null
        else
        {
            int mini = minvalue(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }
    else if (root->data > x)
    {
        root->left = deleteNode(root->left, x);
        return root;
    }
    else
    {
        rot->right = deleteNode(root->right, x);
        return root;
    }
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    Node *root = NULL;
    cout << endl
         << "enter bst values" << endl;
    insertNode(root);
    cout << endl
         << "printing inorder traversel of tree" << endl;
    inorder(root);
    return 0;
}