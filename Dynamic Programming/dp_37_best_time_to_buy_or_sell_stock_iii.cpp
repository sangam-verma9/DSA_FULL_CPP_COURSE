// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
#include <bits/stdc++.h>
using namespace std;
//***** recusion ****
int solve(int ind, int buy, vector<int> &p, int cap, int n)
{
    if (ind == n || cap == 0)
    {
        return 0;
    }
    if (buy)
    {
        return max(-p[ind] + solve(ind + 1, 0, p, cap, n), 0 + solve(ind + 1, 1, p, cap, n));
    }
    else
    {
        return max(p[ind] + solve(ind + 1, 1, p, cap - 1, n), 0 + solve(ind + 1, 0, p, cap, n));
    }
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    return solve(0, 1, prices, 2, n);
}
//**** memoization ***
int solve(int ind, int buy, vector<int> &p, int cap, int n, vector<vector<vector<int>>> &dp)
{
    if (ind == n || cap == 0)
    {
        return 0;
    }
    if (dp[ind][buy][cap] != -1)
    {
        return dp[ind][buy][cap];
    }
    if (buy)
    {
        return dp[ind][buy][cap] = max(-p[ind] + solve(ind + 1, 0, p, cap, n, dp), 0 + solve(ind + 1, 1, p, cap, n, dp));
    }
    else
    {
        return dp[ind][buy][cap] = max(p[ind] + solve(ind + 1, 1, p, cap - 1, n, dp), 0 + solve(ind + 1, 0, p, cap, n, dp));
    }
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return solve(0, 1, prices, 2, n, dp);
}
//**** tabulation ****
int maxProfit(vector<int> &p)
{
    int n = p.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    // Not need to wwrite base case beacuse all ele is alredy 0
    // for(int ind=0;ind<=n;ind++){
    //     for(int buy=0;buy<=1;buy++){
    //         dp[ind][buy][0]=0;
    //     }
    // }
    // for(int buy=0;buy<=1;buy++){
    //     for(int cap=0;cap<=2;cap++){
    //         dp[n][buy][cap]=0;
    //     }
    // }
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if (buy)
                {
                    dp[ind][buy][cap] = max(-p[ind] + dp[ind + 1][0][cap], 0 + dp[ind + 1][1][cap]);
                }
                else
                {
                    dp[ind][buy][cap] = max(p[ind] + dp[ind + 1][1][cap - 1], 0 + dp[ind + 1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][2];
}
//**** space optimization ****
int maxProfit(vector<int> &p)
{
    int n = p.size();
    vector<vector<int>> prev(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
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
    return prev[1][2];
}
//*******
int main()
{

    return 0;
}