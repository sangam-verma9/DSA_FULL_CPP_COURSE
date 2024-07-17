// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
#include<bits/stdc++.h>
using namespace std;
Node *flatten(Node *root)
{
    // Your code here
    priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> pq;
    Node *dummy = new Node(0);
    Node *temp = dummy;
    while (root)
    {
        pq.push({root->data, root});
        root = root->next;
    }
    while (!pq.empty())
    {
        auto t = pq.top();
        pq.pop();
        Node *newnode = t.second;
        temp->bottom = newnode;
        temp = newnode;
        if (newnode->bottom)
        {
            pq.push({newnode->bottom->data, newnode->bottom});
        }
    }
    return dummy->bottom;
}
int main(){

return 0;
}