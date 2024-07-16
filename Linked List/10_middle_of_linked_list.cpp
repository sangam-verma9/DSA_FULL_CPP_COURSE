// https://leetcode.com/problems/middle-of-the-linked-list/
#include <bits/stdc++.h>
using namespace std;
int len(Node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}
Node *findMiddle(Node *head)
{
    // Write your code here
    int ans = len(head) / 2;
    int c = 0;
    while (c < ans)
    {
        head = head->next;
        c++;
    }
    return head;
}


// TortoisHare method
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (head->next == NULL)
            return head;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next != NULL)
        {
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
int main()
{

    return 0;
}