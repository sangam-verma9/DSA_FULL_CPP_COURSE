#include <bits/stdc++.h>
using namespace std;
Node *reverse(Node *&head)
{
    Node *prev = NULL;
    Node *next = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
}
void insertAtTail(Node *&anshead, Node *&anstail, int digit)
{
    Node *temp = new Node(digit);
    if (anstail == NULL)
    {
        anstail = temp;
        anshead = temp;
        return;
    }
    anstail->next = temp;
    anstail = temp;
}
Node *addLink(Node *first, Node *second)
{
    int carry = 0;
    Node *anshead = NULL;
    Node *anstail = NULL;
    while (first != NULL && second != NULL)
    {
        int sum = carry + first->data + second->data;
        int digit = sum % 10;
        // create a node
        insertAtTail(anshead, anstail, digit);
        carry = sum / 10;
        first = first->next;
        second = second->next;
    }
    while (first != NULL)
    {
        int sum = carry + first->data;
        int digit = sum % 10;
        insertAtTail(anshead, anstail, digit);
        carry = sum / 10;
        first = first->next;
    }
    while (second != NULL)
    {
        int sum = carry + second->data;
        int digit = sum % 10;
        insertAtTail(anshead, anstail, digit);
        carry = sum / 10;
        second = second->next;
    }
    while (carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;
        insertAtTail(anshead, anstail, digit);
        carry = sum / 10;
    }
    return anshead;
}
Node *add_linkList(Node *&first, Node *&second)
{
    Node *head1 = reverse(first);
    Node *head2 = reverse(second);
    Node *addHead = addLink(head1, head2);
    Node *ans = reverse(addHead);
    return ans;
}
int main()
{
    // two link list
    return 0;
}