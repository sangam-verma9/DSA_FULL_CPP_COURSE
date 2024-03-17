// https://leetcode.com/problems/implement-stack-using-queues
#include <bits/stdc++.h>
using namespace std;
class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;
    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        int n = q1.size();
        if (n < 1)
        {
            return -1;
        }
        for (int i = 0; i < n - 1; i++)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q1.pop();
        for (int i = 0; i < n - 1; i++)
        {
            q1.push(q2.front());
            q2.pop();
        }
        return ans;
    }

    int top()
    {
        int n = q1.size();
        if (n < 1)
        {
            return -1;
        }
        for (int i = 0; i < n - 1; i++)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q2.push(ans);
        q1.pop();
        for (int i = 0; i < n; i++)
        {
            q1.push(q2.front());
            q2.pop();
        }
        return ans;
    }

    bool empty()
    {
        return q1.empty();
    }

    int getSize()
    {
        return q1.size();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main()
{

    return 0;
}