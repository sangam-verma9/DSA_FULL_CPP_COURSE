// https://leetcode.com/problems/odd-even-linked-list
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL)
            return head;
        ListNode *t1 = head;
        ListNode *d = new ListNode(INT_MIN);
        ListNode *t2 = d;
        ListNode *curr = head;
        int cnt = 1;
        while (curr)
        {
            if (cnt % 2 == 0)
            {
                t1->next = curr->next;
                t2->next = curr;
                curr = curr->next;
                t2 = t2->next;
                t2->next = NULL;
                t1 = t1->next;
            }
            else
                curr = curr->next;
            cnt++;
        }
        t1 = head;
        while (t1->next)
        {
            t1 = t1->next;
        }
        t1->next = d->next;
        return head;
    }
};
int main()
{

    return 0;
}