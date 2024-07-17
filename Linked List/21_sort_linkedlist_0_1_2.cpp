// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {
        Node *d1 = new Node(0);
        Node *ans = d1;
        Node *d2 = new Node(0);
        Node *ans2 = d2;
        Node *d3 = new Node(0);
        Node *ans3 = d3;
        Node *next = NULL;
        while (head)
        {
            next = head->next;
            if (head->data == 0)
            {
                d1->next = head;
                d1 = head;
                head->next = NULL;
            }
            else if (head->data == 1)
            {
                d2->next = head;
                d2 = head;
                head->next = NULL;
            }
            else
            {
                d3->next = head;
                d3 = head;
                head->next = NULL;
            }
            head = next;
        }

        if (ans2->next)
        {
            d1->next = ans2->next;
            d2->next = ans3->next;
        }
        else
        {
            d1->next = ans3->next;
        }
        return ans->next;
    }
};
int main()
{

    return 0;
}