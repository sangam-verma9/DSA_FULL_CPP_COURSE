// https://leetcode.com/problems/palindrome-linked-list/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = slow;
        slow = slow->next;
        prev->next = NULL;
        ListNode *temp = NULL;
        while (slow != NULL)
        {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        fast = head;
        slow = prev;
        while (slow != NULL)
        {
            if (fast->val != slow->val)
            {
                return false;
            }
            else
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return true;
    }
};
int main(){

return 0;
}