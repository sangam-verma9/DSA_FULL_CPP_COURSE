#include <bits/stdc++.h>
using namespace std;
class Circular_queue
{
    int size;
    int *arr;
    int front;
    int rear;
    Circular_queue()
    {
        size = 100001;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void push(int data)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "queue is full" << endl;
        }
        else if (front == -1)
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
    void pop()
    {
        if (front == -1)
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
};
int main()
{

    return 0;
}