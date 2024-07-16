#include <bits/stdc++.h>
using namespace std;
// space complexity O(n) time complexity O(n)
bool detect_cycle(Node *&head)
{
    if (head == NULL)
    {
        return false;
    }
    Node *temp = head;
    map<Node *, bool> visited;
    while (temp != NULL)
    {
        if (visited[temp] = true)
        {
            cout << "cycle present at element: " << temp->data;
            return true;
        }
        temp = temp->next;
    }
    return false;
}
// floyd algorithum space complexity O(1) time compexity O(n)
bool floyd_algo(Node *&head)
{
    if (head == NULL)
    {
        return false;
    }
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}
// cycle start at first element using floyed algo
Node *cycle_first_element(Node *&head)
{
    // first make upper function return Node* and then
    // make sure return index that it slow pointer is equal to fast pointer
    Node *indexElement = floyd_algo(head);
    Node *slow = head;
    while (slow != indexElement)
    {
        slow = slow->next;
        indexElement = indexElement->next;
    }
    return slow;
    // here slow is equal to indexElement so we can return either one of them
}
// remove loop from link list
void removeLoop(Node *&head)
{
    // loop start point
    Node *start = cycle_first_element(head);
    Node *temp = start->next;
    while (temp->next != start)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

int main()
{
    // link list
    return 0;
}