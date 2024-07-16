// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
#include <bits/stdc++.h>
using namespace std;
//**** recursive ****
int solve(int ind, int buy, vector<int> &p, int n)
{
    if (ind >= n)
        return 0;
    if (buy)
    {
        return max(-p[ind] + solve(ind + 1, 0, p, n), 0 + solve(ind + 1, 1, p, n));
    }
    else
    {
        return max(p[ind] + solve(ind + 2, 1, p, n), 0 + solve(ind + 1, 0, p, n));
    }
}
int stockProfit(vector<int> &p)
{
    // Write your code here.
    int n = p.size();
    return solve(0, 1, p, n);
}
//***** memoization ****
int solve(int ind, int buy, vector<int> &p, int n, vector<vector<int>> &dp)
{
    if (ind >= n)
        return 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    if (buy)
    {
        return dp[ind][buy] = max(-p[ind] + solve(ind + 1, 0, p, n, dp), 0 + solve(ind + 1, 1, p, n, dp));
    }
    else
    {
        return dp[ind][buy] = max(p[ind] + solve(ind + 2, 1, p, n, dp), 0 + solve(ind + 1, 0, p, n, dp));
    }
}
int stockProfit(vector<int> &p)
{
    // Write your code here.
    int n = p.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve(0, 1, p, n, dp);
}
//*** tabulataion ***
int stockProfit(vector<int> &p)
{
    // Write your code here.
    int n = p.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    // not need to wrtie base case beacuse alredy all ele is 0
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
                dp[ind][buy] = max(p[ind] + dp[ind + 2][1], 0 + dp[ind + 1][0]);
            }
        }
    }
    return dp[0][1];
}
int main()
{

    return 0;
}