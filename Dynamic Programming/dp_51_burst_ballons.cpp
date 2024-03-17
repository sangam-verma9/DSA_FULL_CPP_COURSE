#include<bits/stdc++.h>
using namespace std;
//*** recusive ***
class Solution
{
public:
    int solve(int i, int j, vector<int> &nums)
    {
        if (i > j)
            return 0;
        int ans = INT_MIN;
        for (int k = i; k <= j; k++)
        {
            int temp = nums[i - 1] * nums[k] * nums[j + 1] + solve(i, k - 1, nums) + solve(k + 1, j, nums);
            ans = max(ans, temp);
        }
        return ans;
    }
    int maxCoins(vector<int> &nums)
    {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        return solve(1, nums.size() - 2, nums);
    }
};
//**** memoization ****
class Solution
{
public:
    int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MIN;
        for (int k = i; k <= j; k++)
        {
            int temp = nums[i - 1] * nums[k] * nums[j + 1] + solve(i, k - 1, nums, dp) + solve(k + 1, j, nums, dp);
            ans = max(ans, temp);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(1, nums.size() - 2, nums, dp);
    }
};
//**** tabulation ****
class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i > j)
                    continue;
                int ans = INT_MIN;
                for (int k = i; k <= j; k++)
                {
                    int temp = nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                    ans = max(ans, temp);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n];
    }
};
//*****
int main() {

return 0;
}