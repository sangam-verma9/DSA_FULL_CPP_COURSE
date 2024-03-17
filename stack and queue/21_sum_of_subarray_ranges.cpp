// https://leetcode.com/problems/sum-of-subarray-ranges/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long subArrayRanges(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prevsmin(n), nextsmin(n);
        stack<int> st1;
        for (int i = 0; i < n; i++)
        {
            while (!st1.empty() && arr[st1.top()] >= arr[i])
            {
                st1.pop();
            }
            if (st1.empty())
            {
                prevsmin[i] = i + 1;
            }
            else
                prevsmin[i] = i - st1.top();
            st1.push(i);
        }
        stack<int> ss1;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!ss1.empty() && arr[ss1.top()] > arr[i])
            {
                ss1.pop();
            }
            if (ss1.empty())
            {
                nextsmin[i] = n - i;
            }
            else
                nextsmin[i] = ss1.top() - i;
            ss1.push(i);
        }
        long long ans1 = 0;
        for (int i = 0; i < n; i++)
        {
            ans1 = ans1 + (1LL * prevsmin[i] * nextsmin[i] * arr[i]);
        }
        vector<int> prevsmax(n), nextsmax(n);
        stack<int> st2;
        for (int i = 0; i < n; i++)
        {
            while (!st2.empty() && arr[st2.top()] <= arr[i])
            {
                st2.pop();
            }
            if (st2.empty())
            {
                prevsmax[i] = i + 1;
            }
            else
                prevsmax[i] = i - st2.top();
            st2.push(i);
        }
        stack<int> ss2;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!ss2.empty() && arr[ss2.top()] < arr[i])
            {
                ss2.pop();
            }
            if (ss2.empty())
            {
                nextsmax[i] = n - i;
            }
            else
                nextsmax[i] = ss2.top() - i;
            ss2.push(i);
        }
        long long ans2 = 0;
        for (int i = 0; i < n; i++)
        {
            ans2 = ans2 + (1LL * prevsmax[i] * nextsmax[i] * arr[i]);
        }
        return ans2 - ans1;
    }
};
int main(){

return 0;
}