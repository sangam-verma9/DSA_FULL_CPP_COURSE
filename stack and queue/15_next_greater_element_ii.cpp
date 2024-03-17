// https://leetcode.com/problems/next-greater-element-ii/
#include <bits/stdc++.h>
using namespace std;
//**** method - 1 **
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> st;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--)
        {
            st.push(nums[i]);
        }
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i])
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
            st.push(nums[i]);
        }
        return ans;
    }
};
//*** method -2 ****
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = n * 2 - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i % n])
            {
                st.pop();
            }
            if (i < n)
            {
                if (!st.empty())
                {
                    ans[i] = st.top();
                }
                else
                {
                    ans[i] = -1;
                }
            }
            st.push(nums[i % n]);
        }
        return ans;
    }
};
int main()
{

    return 0;
}