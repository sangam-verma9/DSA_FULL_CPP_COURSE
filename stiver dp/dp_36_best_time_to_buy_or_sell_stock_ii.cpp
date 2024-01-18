#include <bits/stdc++.h>
using namespace std;
//**** my first approcah ****(good)
long getMaximumProfit(long *p, int n)
{
    long ans = 0;
    long buy = p[0];
    for (int i = 1; i < n; i++)
    {
        if (p[i] < buy)
        {
            buy = p[i];
        }
        else if (p[i] > buy)
        {
            ans += p[i] - buy;
            buy = p[i];
        }
    }
    return ans;
}
//****** Recusion method ****
long solve(int ind, bool buy, long *p, int n)
{
    if (ind == n)
        return 0;
    if (buy)
    {
        return max(-p[ind] + solve(ind + 1, 0, p, n), 0 + solve(ind + 1, 1, p, n));
    }
    else
    {
        return max(p[ind] + solve(ind + 1, 1, p, n), 0 + solve(ind + 1, 0, p, n));
    }
}
long getMaximumProfit(long *p, int n)
{
    return solve(0, 1, p, n);
}
//******* memoization ****
long solve(int ind, bool buy, long *p, int n, vector<vector<long>> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    if (buy)
    {
        return dp[ind][buy] = max(-p[ind] + solve(ind + 1, 0, p, n, dp), 0 + solve(ind + 1, 1, p, n, dp));
    }
    else
    {
        return dp[ind][buy] = max(p[ind] + solve(ind + 1, 1, p, n, dp), 0 + solve(ind + 1, 0, p, n, dp));
    }
}
long getMaximumProfit(long *p, int n)
{
    vector<vector<long>> dp(n, vector<long>(2, -1));
    return solve(0, 1, p, n, dp);
}
//******  Tabulation *****
long getMaximumProfit(long *p, int n)
{
    vector<vector<long>> dp(n + 1, vector<long>(2, 0));
    dp[n][0] = dp[n][1] = 0;
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
                dp[ind][buy] = max(p[ind] + dp[ind + 1][1], 0 + dp[ind + 1][0]);
            }
        }
    }
    return dp[0][1];
}
//****** space optimized *****
long getMaximumProfit(long *p, int n)
{
    // vector<vector<long>>dp(n+1,vector<long>(2,0));
    vector<long> prev(2, 0), curr(2, 0);
    prev[0] = prev[1] = 0;
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
                curr[buy] = max(p[ind] + prev[1], 0 + prev[0]);
            }
        }
        prev = curr;
    }
    return prev[1];
}
//******

int main()
{

    return 0;
}