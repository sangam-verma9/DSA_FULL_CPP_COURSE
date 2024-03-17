// https://www.codingninjas.com/studio/problems/implement-stack-with-linked-list_1279905
#include <bits/stdc++.h>
using namespace std;
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

class Stack
{
    // Write your code here
    Node *t;
    int size;

public:
    Stack()
    {
        // Write your code here
        t = NULL;
        size = 0;
    }

    int getSize()
    {
        // Write your code here
        return size;
    }

    bool isEmpty()
    {
        // Write your code here
        return size == 0;
    }

    void push(int data)
    {
        // Write your code here
        Node *temp = new Node(data);
        temp->next = t;
        t = temp;
        size++;
    }

    void pop()
    {
        // Write your code here
        if (size == 0)
            return;
        Node *temp = t;
        t = t->next;
        size--;
        delete temp;
    }

    int getTop()
    {
        // Write your code here
        if (size == 0)
            return -1;
        return t->data;
    }
};

int main()
{

    return 0;
}