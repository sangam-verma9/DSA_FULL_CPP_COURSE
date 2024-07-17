// https://leetcode.com/problems/add-two-numbers/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *r1 = l1;
        ListNode *r2 = l2;
        int c = 0;
        ListNode *head = NULL;
        ListNode *curr = head;

        while (r1 != NULL && r2 != NULL)
        {
            int s = r1->val + r2->val + c;
            int p = s % 10;
            if (s > 9)
            {
                c = 1;
            }
            else
            {
                c = 0;
            }
            if (curr == NULL)
            {
                head = new ListNode(p);
                curr = head;
            }
            else
            {
                ListNode *temp = new ListNode(p);
                curr->next = temp;
                curr = curr->next;
            }
            r1 = r1->next;
            r2 = r2->next;
        }

        while (r1 != NULL)
        {
            int s = r1->val + c;
            int p = s % 10;
            if (s > 9)
            {
                c = 1;
            }
            else
            {
                c = 0;
            }
            ListNode *temp = new ListNode(p);
            curr->next = temp;
            curr = curr->next;
            r1 = r1->next;
        }

        while (r2 != NULL)
        {
            int s = r2->val + c;
            int p = s % 10;
            if (s > 9)
            {
                c = 1;
            }
            else
            {
                c = 0;
            }
            ListNode *temp = new ListNode(p);
            curr->next = temp;
            curr = curr->next;
            r2 = r2->next;
        }

        if (c == 1)
        {
            ListNode *temp = new ListNode(c);
            curr->next = temp;
            curr = curr->next;
        }
        return head;
    }
};
int main()
{

    return 0;
}