// https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/0
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to count nodes of a linked list.
    int getCount(struct Node *head)
    {

        // Code here
        int cnt = 0;
        while (head)
        {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
};
int main()
{

    return 0;
}