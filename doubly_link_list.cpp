#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
void insertAtFirst(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
    temp->prev = NULL;
}
void insertAtLast(Node *&head, int data)
{
    Node *temp = new Node(data);
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    temp->prev = curr;
    curr->next = temp;
    temp->next = NULL;
}
void insertAtAnyPosition(Node *&head, int data, int position)
{
    if (position == 1)
    {
        insertAtFirst(head, data);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        cnt++;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        insertAtLast(head, data);
        return;
    }
    Node *nodetoinsert = new Node(data);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
}
// delete node
void deleteNode(Node *&head, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *pre = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            pre = curr;
            curr = curr->next;
            cnt++;
        }

        pre->next = curr->next;
        curr->next->prev = pre;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    insertAtFirst(head, 2);
    insertAtLast(head, 4);
    insertAtLast(head, 5);
    insertAtLast(head, 6);
    insertAtFirst(head, 8);
    insertAtAnyPosition(head, 10, 2);
    deleteNode(head, 4);

    print(head);

    return 0;
}