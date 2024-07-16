// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1000000007;

    int sol(int ind, int target, int arr[], vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (target == 0 && arr[0] == 0)
                return 2; // take 0 ,nontake 0 => both
            else if (target == 0 && arr[0] != 0)
                return 1; // nontake 0=>only 1 option
            else if (target == arr[0])
                return 1; // take arr[0] => only 1 option
            else
                return 0;
        }
        // If the result for this state is already calculated, return it
        if (dp[ind][target] != -1)
            return dp[ind][target];

        // Recursive cases
        // 1. Exclude the current element
        int notTaken = sol(ind - 1, target, arr, dp);

        // 2. Include the current element if it doesn't exceed the target
        int taken = 0;
        if (arr[ind] <= target)
            taken = sol(ind - 1, target - arr[ind], arr, dp);

        // Store the result in the DP table and return
        return dp[ind][target] = (notTaken % mod + taken % mod) % mod;
    }
    int perfectSum(int num[], int n, int k)
    {
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return sol(n - 1, k, num, dp);
    }
};
// Tabultaion solution
class Solution
{
public:
    int perfectSum(int arr[], int n, int sum)
    {
        const int MOD = 1e9 + 7;

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        // Initialize the dp array
        dp[0][0] = 1;
        for (int j = 1; j <= sum; j++)
            dp[0][j] = 0;

        // Fill the dp array
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % MOD;
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][sum];
    }
};
int main()
{

    return 0;
}