// https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *reverseDLL(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        Node *prev = NULL, *curr = head;
        while (curr != NULL)
        {
            Node *nextNode = curr->next;
            curr->next = curr->prev; //(OR) curr->next = prev;
            curr->prev = nextNode;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};
int main()
{

    return 0;
}