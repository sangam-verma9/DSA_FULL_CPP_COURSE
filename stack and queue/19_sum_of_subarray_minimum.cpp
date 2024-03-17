// https://leetcode.com/problems/sum-of-subarray-minimums
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prevs(n), nexts(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                prevs[i] = i + 1;
            }
            else
                prevs[i] = i - st.top();
            st.push(i);
        }
        stack<int> ss;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!ss.empty() && arr[ss.top()] > arr[i])
            {
                ss.pop();
            }
            if (ss.empty())
            {
                nexts[i] = n - i;
            }
            else
                nexts[i] = ss.top() - i;
            ss.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = (ans + (1LL * prevs[i] * nexts[i] * arr[i]) % MOD) % MOD;
        }
        return ans;
    }
};

int main(){

return 0;
}