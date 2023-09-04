#include <bits/stdc++.h>
using namespace std;
bool floyeddetectcycle(Node *head)
{
    if (head == NULL)
        return false;
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast->next == NULL)
        {
            return false;
        }
        fast = fast->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}
int main()
{

    return 0;
}