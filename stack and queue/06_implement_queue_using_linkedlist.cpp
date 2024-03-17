// https://www.codingninjas.com/studio/problems/implement-queue-using-linked-list_8161235
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition of linked list
 * class Node {
 *
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 *
 * Definition of Queue
 * struct Queue {
 *   Node* front;
 *   Node* rear;
 *   void push(int);
 *   int pop();
 *
 *   Queue() {
 *       front = rear = NULL;
 *   }
 * };
 */

void Queue::push(int x)
{
    // Write Your Code Here
    Node *temp = new Node(x);
    if (rear == NULL)
    {
        rear = temp;
        front = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

int Queue::pop()
{
    // Write Your Code Here
    if (front == NULL)
        return -1;
    int ele = front->data;
    Node *temp = front;
    front = front->next;
    delete temp;
    if (front == NULL)
        rear = NULL;
    return ele;
}

int main()
{

    return 0;
}