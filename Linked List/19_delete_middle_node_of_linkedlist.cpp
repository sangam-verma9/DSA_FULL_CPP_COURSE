// leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head->next == NULL)
            return NULL;
        ListNode *prev = NULL;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        delete slow;
        return head;
    }
};
int main(){

return 0;
}