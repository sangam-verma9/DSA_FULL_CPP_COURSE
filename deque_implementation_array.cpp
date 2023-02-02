#include <bits/stdc++.h>
using namespace std;
class Deque
{
public:
    int *arr;
    int size;
    int front;
    int rear;
    Deque()
    {
        size = 100001;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    bool isFull()
    {
        if ((front == 0 &&rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        else
            return false;
    }
    void Push_front(int data)
    {
        if (isFull())
        {
            cout << "deque if full" << endl;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = data;
    }
    void Push_rear()
    {
        if (isFull())
        {
            cout << "queue is full" << endl;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = data;
    }
    void Pop_front()
    {
        if (isEmpty())
        {
            cout << "queue is empty" << endl;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else if (rear == front)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
        arr[front] = -1;
    }
    void Pop_back()
    {
        if (isEmpty())
        {
            cout << "deque is empty" << endl;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else if (rear == front)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            rear--;
        }
        arr[rear]=-1;
    }
};
int main()
{

    return 0;
}