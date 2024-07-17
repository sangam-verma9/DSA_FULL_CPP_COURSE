// https://leetcode.com/problems/sort-list/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    ListNode *merge(ListNode *h1, ListNode *h2)
    {
        if (h1 == NULL)
            return h2;
        if (h2 == NULL)
            return h1;
        ListNode *dummy = new ListNode(INT_MIN);
        ListNode *temp = dummy;
        while (h1 && h2)
        {
            if (h1->val <= h2->val)
            {
                temp->next = h1;
                temp = h1;
                h1 = h1->next;
            }
            else
            {
                temp->next = h2;
                temp = h2;
                h2 = h2->next;
            }
        }
        if (h1 == NULL)
            temp->next = h2;
        else
            temp->next = h1;
        return dummy->next;
    }
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *left = head;
        ListNode *right = slow->next;
        slow->next = NULL;
        left = sortList(left);
        right = sortList(right);
        ListNode *res = merge(left, right);
        return res;
    }
};
int main()
{

    return 0;
}