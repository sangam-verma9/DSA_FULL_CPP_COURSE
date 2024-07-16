// https://leetcode.com/problems/delete-node-in-a-linked-list/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *temp = node->next;
        int num = temp->val;
        node->next = temp->next;
        temp->next = NULL;
        node->val = num;
        delete temp;
    }
};
int main()
{

    return 0;
}