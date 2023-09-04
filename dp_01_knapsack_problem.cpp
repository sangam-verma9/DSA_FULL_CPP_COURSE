#include <bits/stdc++.h>
using namespace std;
//******* recursion ******
int solve(vector<int> &weight, vector<int> &value, int ind, int capacity)
{
    if (ind == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
            return 0;
    }
    int include = 0;
    if (weight[ind] <= capacity)
    {
        include = value[ind] + solve(weight, value, ind - 1, capacity - weight[ind]);
    }
    int exclude = 0 + solve(weight, value, ind - 1, capacity);
    return max(include, exclude);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return solve(weight, value, n - 1, maxWeight);
}
//********* memoization ********
int solvemem(vector<int> &weight, vector<int> &value, int ind, int capacity, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
            return 0;
    }
    if (dp[ind][capacity] != -1)
    {
        return dp[ind][capacity];
    }
    int include = 0;
    if (weight[ind] <= capacity)
    {
        include = value[ind] + solvemem(weight, value, ind - 1, capacity - weight[ind], dp);
    }
    int exclude = 0 + solvemem(weight, value, ind - 1, capacity, dp);
    return dp[ind][capacity] = max(include, exclude);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)

{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solvemem(weight, value, n - 1, maxWeight, dp);
}
//********* tabulation *****
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    // base case
    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int include = 0;
            if (weight[ind] <= w)
            {
                include = value[ind] + dp[ind - 1][w - weight[ind]];
            }
            int exclude = 0 + dp[ind - 1][w];
            dp[ind][w] = max(include, exclude);
        }
    }
    return dp[n - 1][maxWeight];
}
//******** space optimization *******
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0);
    vector<int> curr(maxWeight + 1, 0);
    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
        {
            prev[w] = value[0];
        }
        else
        {
            prev[w] = 0;
        }
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int include = 0;
            if (weight[ind] <= w)
            {
                include = value[ind] + prev[w - weight[ind]];
            }
            int exclude = 0 + prev[w];
            curr[w] = max(include, exclude);
        }
        prev = curr;
    }
    return prev[maxWeight];
}
//*********** further space optimization *****
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> curr(maxWeight + 1, 0);
    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
        {
            curr[w] = value[0];
        }
        else
        {
            curr[w] = 0;
        }
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int w = maxWeight; w >= 0; w--)
        {
            int include = 0;
            if (weight[ind] <= w)
            {
                include = value[ind] + curr[w - weight[ind]];
            }
            int exclude = 0 + curr[w];
            curr[w] = max(include, exclude);
        }
    }
    return curr[maxWeight];
}
//********
int main()
{

    return 0;
}