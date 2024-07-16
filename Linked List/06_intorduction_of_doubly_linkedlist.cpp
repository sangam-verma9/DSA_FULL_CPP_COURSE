// https://www.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *constructDLL(vector<int> &arr)
    {
        // code here
        Node *head = new Node(arr[0]);
        Node *temp = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *t = new Node(arr[i]);
            temp->next = t;
            t->prev = temp;
            temp = t;
        }
        return head;
    }
};
int main()
{

    return 0;
}