// https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/0
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *insertAtEnd(Node *head, int x)
    {
        // Code here
        if (head == NULL)
            return new Node(x);
        Node *t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = new Node(x);
        return head;
    }
};
int main(){

return 0;
}