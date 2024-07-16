// https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1
#include <bits/stdc++.h>
using namespace std;
void addNode(Node *head, int pos, int data)
{
    // Your code here
    Node *curr = head;
    while (pos--)
    {
        curr = curr->next;
    }
    Node *temp = new Node(data);
    temp->next = curr->next;
    if (curr->next)
        curr->next->prev = temp;
    curr->next = temp;
    temp->prev = curr;
}
int main()
{

    return 0;
}