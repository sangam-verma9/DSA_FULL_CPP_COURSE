// https://leetcode.com/problems/next-greater-element-i
#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] >= st.top())
        {
            st.pop();
        }
        if (!st.empty())
        {
            ans[i] = st.top();
        }
        else
        {
            ans[i] = -1;
        }
        st.push(arr[i]);
    }
    return ans;
}
int main()
{

    return 0;
}