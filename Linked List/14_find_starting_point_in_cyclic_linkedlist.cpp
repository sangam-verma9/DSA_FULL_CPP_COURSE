// https://leetcode.com/problems/linked-list-cycle-ii/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        bool flag = false;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
            return NULL;
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main()
{

    return 0;
}