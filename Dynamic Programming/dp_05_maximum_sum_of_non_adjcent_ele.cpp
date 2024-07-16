// https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include <bits/stdc++.h>
using namespace std;
//***** recursive ******
int solve(int n, vector<int> &nums)
{
    if (n < 0)
    {
        return 0;
    }
    int include = nums[n] + solve(n - 2, nums);
    int exclude = 0 + solve(n - 1, nums);
    return max(include, exclude);
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.

    int n = nums.size();
    int ans = solve(n - 1, nums);
    return ans;
}
//******** memoization *******
int solve(vector<int> &nums, int n, vector<int> &dp)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return nums[n];
    if (dp[n] != -1)
        return dp[n];
    int include = solve(nums, n - 2, dp) + nums[n];
    int exclude = solve(nums, n - 1, dp) + 0;
    dp[n] = max(include, exclude);
    return dp[n];
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    int ans = solve(nums, n - 1, dp);
    return ans;
}
//******** tabulation ********
int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        int include = nums[i];
        if (i > 1)
            include += [i - 2];
        int exclude = dp[i - 1] + 0;
        dp[i] = max(include, exclude);
    }
    return dp[n - 1];
}
//******* space optimization ****
int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();

    int prev1 = nums[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int include = nums[i] + prev2;
        int exclude = prev1 + 0;
        int curr = max(include, exclude);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{

    return 0;
}