#include <bits/stdc++.h>
using namespace std;
Node *floyeddetectcycle(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast->next == NULL)
        {
            return NULL;
        }
        fast = fast->next;
        slow = slow->next;
        if (fast == slow)
            return slow;
    }
    return NULL;
}
Node *startingNode(Node *head)
{
    Node *meetNode = floyeddetectcycle(head);
    Node *fast = head;
    while (fast != meetNode)
    {
        meetNode = meetNode->next;
        fast = fast->next;
    }
    return fast;
}
int main()
{

    return 0;
}