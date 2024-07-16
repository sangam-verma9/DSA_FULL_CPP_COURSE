// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
#include <bits/stdc++.h>
using namespace std;
//***** recusion ****
int solve(int ind, bool buy, vector<int> &p, int n, int fee)
{
    if (ind == n)
        return 0;
    if (buy)
    {
        return max(-p[ind] + solve(ind + 1, 0, p, n, fee), 0 + solve(ind + 1, 1, p, n, fee));
    }
    else
    {
        return max(p[ind] + solve(ind + 1, 1, p, n, fee) - fee, 0 + solve(ind + 1, 0, p, n, fee));
    }
}
int maximumProfit(vector<int> &prices, int n, int fee)
{
    // Write your code here.

    return solve(0, 1, prices, n, fee);
}
//**** memoization ***
int solve(int ind, bool buy, vector<int> &p, int n, int fee, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    if (buy)
    {
        return dp[ind][buy] = max(-p[ind] + solve(ind + 1, 0, p, n, fee, dp), 0 + solve(ind + 1, 1, p, n, fee, dp));
    }
    else
    {
        return dp[ind][buy] = max(p[ind] + solve(ind + 1, 1, p, n, fee, dp) - fee, 0 + solve(ind + 1, 0, p, n, fee, dp));
    }
}
int maximumProfit(vector<int> &prices, int n, int fee)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve(0, 1, prices, n, fee, dp);
}
//**** tabulation ****
int maximumProfit(vector<int> &p, int n, int fee)
{
    // Write your code here.
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
            {
                dp[ind][buy] = max(-p[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
            }
            else
            {
                dp[ind][buy] = max(p[ind] + dp[ind + 1][1] - fee, 0 + dp[ind + 1][0]);
            }
        }
    }
    return dp[0][1];
}
//**** space optimization ****
int maximumProfit(vector<int> &p, int n, int fee)
{
    vector<int> prev(2, 0), curr(2, 0);
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
            {
                curr[buy] = max(-p[ind] + prev[0], 0 + prev[1]);
            }
            else
            {
                curr[buy] = max(p[ind] + prev[1] - fee, 0 + prev[0]);
            }
        }
        prev = curr;
    }
    return prev[1];
}
//*******
int main()
{

    return 0;
}