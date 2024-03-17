// https://www.codingninjas.com/studio/problems/day-25-:-queue-using-stack_799482
#include <bits/stdc++.h>
using namespace std;
class Queue
{
    // Define the data members(if any) here.
    stack<int> s1;
    stack<int> s2;

public:
    Queue()
    {
        // Initialize your data structure here.
    }

    void enQueue(int val)
    {
        // Implement the enqueue() function.
        s1.push(val);
    }

    int deQueue()
    {
        // Implement the dequeue() function.
        int n = s1.size();
        if (n == 0)
            return -1;
        for (int i = 0; i < n - 1; i++)
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ele = s1.top();
        s1.pop();
        for (int i = 0; i < n - 1; i++)
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ele;
    }

    int peek()
    {
        // Implement the peek() function here.
        int n = s1.size();
        if (n == 0)
            return -1;
        for (int i = 0; i < n - 1; i++)
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ele = s1.top();
        s1.pop();
        s2.push(ele);
        for (int i = 0; i < n; i++)
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ele;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here.
        return s1.empty();
    }
};
int main()
{

    return 0;
}