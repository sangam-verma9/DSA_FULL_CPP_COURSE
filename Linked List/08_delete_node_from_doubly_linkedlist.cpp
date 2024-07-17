// https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *deleteNode(Node *head, int x)
    {
        Node *dummy = new Node(0);
        dummy->next = head;
        Node *ans = dummy;
        head->prev = dummy;
        Node *prev = NULL;
        Node *curr = dummy;
        while (x--)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if (curr->next)
            curr->next->prev = prev;

        Node *res = ans->next;
        if (res)
            res->prev = NULL;
        return res;
    }
};
int main()
{

    return 0;
}