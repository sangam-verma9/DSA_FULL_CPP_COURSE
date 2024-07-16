// https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node *head, int key)
    {
        // Code here
        while (head)
        {
            if (head->data == key)
                return true;
            head = head->next;
        }
        return false;
    }
};
int main()
{

    return 0;
}