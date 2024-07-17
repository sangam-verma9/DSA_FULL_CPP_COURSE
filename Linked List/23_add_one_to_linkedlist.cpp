// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *reverse(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *prev = NULL;
        Node *curr = head;

        while (curr != NULL)
        {
            Node *forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    Node *addOne(Node *head)
    {
        Node *d = reverse(head);
        Node *temp = d;
        int c = 1;
        while (temp)
        {
            int t = temp->data;
            temp->data = (t + c) % 10;
            c = (t + c) / 10;
            temp = temp->next;
        }
        if (c)
        {
            temp = d;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = new Node(c);
        }
        return reverse(d);
    }
};
int main()
{

    return 0;
}