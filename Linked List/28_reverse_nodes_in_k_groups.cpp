// https://leetcode.com/problems/reverse-nodes-in-k-group/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *fow = NULL;
        int cnt = 0;
        while (curr != NULL && cnt < k)
        {
            fow = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fow;
            cnt++;
        }
        ListNode *temp = fow;
        int sa = 0;
        while (temp)
        {
            sa++;
            temp = temp->next;
            if (sa >= k)
            {
                break;
            }
        }

        if (sa >= k)
        {
            head->next = reverseKGroup(fow, k);
        }
        else
        {
            head->next = fow;
        }
        return prev;
    }
};
int main()
{

    return 0;
}