// https://leetcode.com/problems/rotate-list/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return head;
        int cnt = 0;
        ListNode *temp = head;
        while (true)
        {
            cnt++;
            if (temp->next == NULL)
            {
                temp->next = head;
                break;
            }
            temp = temp->next;
        }
        k = k % cnt;
        int c = cnt - k;
        while (c--)
        {
            head = head->next;
        }
        cnt--;
        temp = head;
        while (cnt--)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        return head;
    }
};
int main()
{

    return 0;
}