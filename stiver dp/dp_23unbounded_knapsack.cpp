#include <bits/stdc++.h>
using namespace std;
//**** recusion ****
int solve(int ind, int tar, vector<int> &profit, vector<int> &weight)
{
    if (ind == 0)
    {
        int a = tar / weight[0];
        return a * profit[0];
    }
    int notTake = 0 + solve(ind - 1, tar, profit, weight);
    int take = -1e9;
    if (tar >= weight[ind])
        take = profit[ind] + solve(ind, tar - weight[ind], profit, weight);
    return max(notTake, take);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    int a = solve(n - 1, w, profit, weight);
    if (a == -1e9)
        return 0;
    return a;
}
//**** memoization ****
int solve(int ind, int tar, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        int a = tar / weight[0];
        return a * profit[0];
    }
    if (dp[ind][tar] != -1)
    {
        return dp[ind][tar];
    }
    int notTake = 0 + solve(ind - 1, tar, profit, weight, dp);
    int take = -1e9;
    if (tar >= weight[ind])
        take = profit[ind] + solve(ind, tar - weight[ind], profit, weight, dp);
    return dp[ind][tar] = max(notTake, take);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    int a = solve(n - 1, w, profit, weight, dp);
    if (a == -1e9)
        return 0;
    return a;
}
//**** tabulation ****
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    for (int i = 0; i <= w; i++)
    {
        int a = i / weight[0];
        dp[0][i] = a * profit[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 0; tar <= w; tar++)
        {
            int notTake = dp[ind - 1][tar];
            int take = -1e9;
            if (tar >= weight[ind])
                take = profit[ind] + dp[ind][tar - weight[ind]];
            dp[ind][tar] = max(notTake, take);
        }
    }
    return dp[n - 1][w];
}
//**** space optimization ***
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w + 1, 0), curr(w + 1, 0);
    for (int i = 0; i <= w; i++)
    {
        int a = i / weight[0];
        prev[i] = a * profit[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 0; tar <= w; tar++)
        {
            int notTake = prev[tar];
            int take = -1e9;
            if (tar >= weight[ind])
                take = profit[ind] + curr[tar - weight[ind]];
            curr[tar] = max(notTake, take);
        }
        prev = curr;
    }
    return prev[w];
}
int main()
{

    return 0;
}