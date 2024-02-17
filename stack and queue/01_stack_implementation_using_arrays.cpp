// https://www.codingninjas.com/studio/problems/stack-implementation-using-array_3210209
#include <bits/stdc++.h>
using namespace std;
// Stack class.
class Stack
{
    int *arr;
    int t;
    int size;

public:
    Stack(int capacity)
    {
        arr = new int[capacity];
        t = -1;
        size = capacity;
    }

    void push(int num)
    {
        if (t < size - 1)
        {
            t++;
            arr[t] = num;
        }
    }

    int pop()
    {
        if (t == -1)
            return -1;
        else
        {
            int top = arr[t];
            t--;
            return top;
        }
    }

    int top()
    {
        if (t == -1)
            return -1;
        return arr[t];
    }

    int isEmpty()
    {
        return t == -1;
    }

    int isFull()
    {
        return t == size - 1;
    }
};

int main()
{

    return 0;
}