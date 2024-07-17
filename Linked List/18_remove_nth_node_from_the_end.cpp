// https://leetcode.com/problems/remove-nth-node-from-end-of-list
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        if (fast == NULL)
            return head->next;
        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

int main()
{

    return 0;
}