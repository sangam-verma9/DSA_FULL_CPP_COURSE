// https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int, int>> ans;
        Node *h = head;
        Node *t = head;
        while (t->next)
            t = t->next;
        while (h->data <= t->data && h != t)
        {
            if (h->data + t->data == target)
            {
                ans.push_back({h->data, t->data});
                h = h->next;
                t = t->prev;
            }
            else if (h->data + t->data > target)
            {
                t = t->prev;
            }
            else
            {
                h = h->next;
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}