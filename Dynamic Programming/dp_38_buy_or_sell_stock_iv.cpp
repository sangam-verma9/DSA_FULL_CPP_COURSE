// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv
#include <bits/stdc++.h>
using namespace std;
int maximumProfit(vector<int> &p, int n, int k)
{
    vector<vector<int>> prev(2, vector<int>(k + 1, 0));
    vector<vector<int>> curr(2, vector<int>(k + 1, 0));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= k; cap++)
            {
                if (buy)
                {
                    curr[buy][cap] = max(-p[ind] + prev[0][cap], 0 + prev[1][cap]);
                }
                else
                {
                    curr[buy][cap] = max(p[ind] + prev[1][cap - 1], 0 + prev[0][cap]);
                }
            }
        }
        prev = curr;
    }
    return prev[1][k];
}
//***** another method *** (recrsive solution)
int solve(int ind, int tranNo, vector<int> &p, int n, int k)
{
    if (ind == n || tranNo == 2 * k)
        return 0;
    if (tranNo % 2 == 0)
    {
        // buy
        return max(-p[ind] + solve(ind + 1, tranNo + 1, p, n, k), 0 + solve(ind + 1, tranNo, p, n, k));
    }
    else
    {
        // sell
        return max(p[ind] + solve(ind + 1, tranNo + 1, p, n, k), 0 + solve(ind + 1, tranNo, p, n, k));
    }
}
int maximumProfit(vector<int> &p, int n, int k)
{
    return solve(0, 0, p, n, k);
}
//**another approach**** memoization ****
int solve(int ind, int tranNo, vector<int> &p, int n, int k, vector<vector<int>> &dp)
{
    if (ind == n || tranNo == 2 * k)
        return 0;
    if (dp[ind][tranNo] != -1)
        return dp[ind][tranNo];
    if (tranNo % 2 == 0)
    {
        // buy
        return dp[ind][tranNo] = max(-p[ind] + solve(ind + 1, tranNo + 1, p, n, k, dp), 0 + solve(ind + 1, tranNo, p, n, k, dp));
    }
    else
    {
        // sell
        return dp[ind][tranNo] = max(p[ind] + solve(ind + 1, tranNo + 1, p, n, k, dp), 0 + solve(ind + 1, tranNo, p, n, k, dp));
    }
}
int maximumProfit(vector<int> &p, int n, int k)
{
    vector<vector<int>> dp(n, vector<int>(2 * k, -1));
    return solve(0, 0, p, n, k, dp);
}
//*******
int main()
{

    return 0;
}