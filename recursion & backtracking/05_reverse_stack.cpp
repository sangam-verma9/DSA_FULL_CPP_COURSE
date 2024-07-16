// https://www.geeksforgeeks.org/problems/reverse-a-stack/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void pushToB(stack<int> &s, int ele)
    {
        if (s.empty())
        {
            s.push(ele);
            return;
        }
        int t = s.top();
        s.pop();
        pushToB(s, ele);
        s.push(t);
    }
    void Reverse(stack<int> &s)
    {
        if (s.empty())
            return;
        int t = s.top();
        s.pop();
        Reverse(s);
        pushToB(s, t);
    }
};
int main()
{

    return 0;
}