// https://leetcode.com/problems/merge-k-sorted-lists/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = new ListNode(0);
        ListNode *ans = head;
        int cnt = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        while (true)
        {
            cnt = 0;
            for (int i = 0; i < lists.size(); i++)
            {
                if (lists[i])
                {
                    pq.push(lists[i]->val);
                    lists[i] = lists[i]->next;
                    cnt++;
                }
            }
            if (cnt == 0)
            {
                break;
            }
            else
            {
                ListNode *temp = new ListNode(pq.top());
                pq.pop();
                head->next = temp;
                head = temp;
            }
        }
        while (!pq.empty())
        {
            ListNode *temp = new ListNode(pq.top());
            pq.pop();
            head->next = temp;
            head = temp;
        }
        return ans->next;
    }
};
int main(){

return 0;
}