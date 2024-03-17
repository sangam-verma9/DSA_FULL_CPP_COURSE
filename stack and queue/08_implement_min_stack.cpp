// https://leetcode.com/problems/min-stack/
#include <bits/stdc++.h>
using namespace std;
class MinStack
{
public:
    stack<pair<int, int>> st;
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
        {
            st.push({val, val});
        }
        else
        {
            int a = min(val, st.top().second);
            st.push({val, a});
        }
    }

    void pop()
    {
        if (!st.empty())
        {
            st.pop();
        }
    }

    int top()
    {
        if (!st.empty())
        {
            return st.top().first;
        }
        else
            return -1;
    }

    int getMin()
    {
        if (!st.empty())
        {
            return st.top().second;
        }
        else
            return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main()
{

    return 0;
}