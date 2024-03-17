// https://www.codingninjas.com/studio/problems/implement-queue-using-arrays_8390825
#include<bits/stdc++.h>
using namespace std;
class Queue
{

    int front, rear;
    vector<int> arr;

public:
    Queue()
    {
        front = 0;
        rear = 0;
        arr.resize(100001);
    }

    // Enqueue (add) element 'e' at the end of the queue.
    void enqueue(int e)
    {
        rear++;
        arr[rear] = e;
    }

    // Dequeue (retrieve) the element from the front of the queue.
    int dequeue()
    {
        if (front >= rear)
            return -1;
        else
        {
            int ele = arr[++front];
            return ele;
        }
    }
};
int main(){

return 0;
}