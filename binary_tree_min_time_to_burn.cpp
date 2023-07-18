#include <bits/stdc++.h>
using namespace std;
Node *mappingandtarget(Node *root, int target, map<Node *, Node *> &nodeToParent)
{
    Node *result = NULL;
    queue<Node *> q;
    q.push(root);
    nodeToParent[root] = NULL;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front->data == target)
        {
            result = front;
        }
        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return result;
}

int burntree(map<Node *, Node *> &nodeToParent, Node *targetNode)
{
    int ans = 0;
    map<Node *, bool> visited;
    queue<Node *> q;
    q.push(targetNode);
    visited[targetNode] = 1;
    while (!q.empty())
    {
        int size = q.size();
        bool flag = 0;
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();
            if (front->left && !visited[front->left])
            {
                q.push(front->left);
                visited[front->left] = 1;
                flag = 1;
            }
            if (front->right && !visited[front->right])
            {
                q.push(front->right);
                visited[front->right] = 1;
                flag = 1;
            }
            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
                flag = 1;
            }
        }
        if (flag == 1)
        {
            ans++;
        }
    }
    return ans;
}
int minTime(Node *root, int target)
{
    // step1- create node to parent mapping
    // step2- find target node
    // burn tree
    map<Node *, Node *> nodeToParent;
    Node *targetNode = mappingandtarget(root, target, nodeToParent);
    int ans = burntree(nodeToParent, targetNode);
    return ans;
}
int main()
{

    return 0;
}