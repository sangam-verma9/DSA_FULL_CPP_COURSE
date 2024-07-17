// https://leetcode.com/problems/reverse-linked-list/
//for good understanding watch striver dry run code
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *newnode = reverseList(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = NULL;
        return newnode;
    }
};
int main(){

return 0;
}