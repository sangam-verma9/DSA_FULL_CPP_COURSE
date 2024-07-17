// https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *removeDuplicates(struct Node *head)
    {
        // Your code here
        if (head == NULL || head->next == NULL)
            return head;
        Node *prev = head;
        Node *curr = head->next;
        while (curr)
        {
            if (curr->data != prev->data)
            {
                prev->next = curr;
                curr->prev = prev;
                prev = curr;
            }
            curr = curr->next;
        }
        prev->next = NULL;
        return head;
    }
};
int main()
{

    return 0;
}