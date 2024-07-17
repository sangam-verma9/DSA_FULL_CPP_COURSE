// https://www.geeksforgeeks.org/problems/find-length-of-loop/1
#include <bits/stdc++.h>
using namespace std;
int countNodesinLoop(struct Node *head)
{
    // Code here
    Node *slow = head;
    Node *fast = head;
    int cnt = 0;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            cnt++;
            slow = slow->next;
            while (slow != fast)
            {
                slow = slow->next;
                cnt++;
            }
            return cnt;
        }
    }

    return cnt;
}
int main()
{

    return 0;
}