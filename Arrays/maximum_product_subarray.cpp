// https://leetcode.com/problems/maximum-product-subarray
#include <bits/stdc++.h>
using namespace std;
// Intuition is here ans is max of all prefixes and suffixes when there is 0 then we start a new prefix or suffix

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int ans = INT_MIN;
        int prefix = 1;
        int suffix = 1;
        for (int i = 0; i < n; i++)
        {
            if (prefix == 0)
                prefix = 1;
            if (suffix == 0)
                suffix = 1;
            prefix *= nums[i];
            suffix *= nums[n - i - 1];
            ans = max(ans, max(prefix, suffix));
        }
        return ans;
    }
};
int main()
{

    return 0;
}