#include <bits/stdc++.h>
using namespace std;
//*** recursion ***
int solve(int ind, int len, vector<int> &price)
{
    if (ind == 0)
    {
        int a = len / (ind + 1);
        return a * price[0];
    }
    int notTake = solve(ind - 1, len, price);
    int take = -1e9;
    if (len >= ind + 1)
        take = price[ind] + solve(ind, len - (ind + 1), price);
    return max(take, notTake);
}
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    return solve(n - 1, n, price);
}
//*** memoization ***
int solve(int ind, int len, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        int a = len / (ind + 1);
        return a * price[0];
    }
    if (dp[ind][len] != -1)
    {
        return dp[ind][len];
    }
    int notTake = solve(ind - 1, len, price, dp);
    int take = -1e9;
    if (len >= ind + 1)
        take = price[ind] + solve(ind, len - (ind + 1), price, dp);
    return dp[ind][len] = max(take, notTake);
}
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(n - 1, n, price, dp);
}

//**** tabulation ***
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i * price[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int len = 0; len <= n; len++)
        {
            int notTake = dp[ind - 1][len];
            int take = -1e9;
            if (len >= ind + 1)
                take = price[ind] + dp[ind][len - (ind + 1)];
            dp[ind][len] = max(take, notTake);
        }
    }
    return dp[n - 1][n];
}
//*** space optimization ****
int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        prev[i] = i * price[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int len = 0; len <= n; len++)
        {
            int notTake = prev[len];
            int take = -1e9;
            if (len >= ind + 1)
                take = price[ind] + curr[len - (ind + 1)];
            curr[len] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[n];
}
//******
int main()
{

    return 0;
}