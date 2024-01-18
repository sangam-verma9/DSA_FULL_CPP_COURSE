#include <bits/stdc++.h>
using namespace std;
//**** recursive *****
#include <bits/stdc++.h>
bool solve(int i, int n, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (k == 0)
    {
        return true;
    }
    else if (k < 0 || i > n)
    {
        return false;
    }
    if (dp[i][k] != -1)
    {
        return dp[i][k];
    }
    bool op1 = solve(i + 1, n, k - arr[i], arr, dp);
    bool op2 = solve(i + 1, n, k, arr, dp);
    return dp[i][k] = (op1 || op2);
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(0, n, k, arr, dp);
}
//********* memoization *******
#include <bits/stdc++.h>
bool solve(int i, int n, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (k == 0)
    {
        return true;
    }
    else if (k < 0 || i > n)
    {
        return false;
    }
    if (dp[i][k] != -1)
    {
        return dp[i][k];
    }
    bool op1 = solve(i + 1, n, k - arr[i], arr, dp);
    bool op2 = solve(i + 1, n, k, arr, dp);
    return dp[i][k] = (op1 || op2);
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return solve(0, n, k, arr, dp);
}
//******** ii recurisve solution *****
bool solve(int ind, int tar, vector<int> &arr)
{
    if (tar == 0)
        return 1;
    if (ind == 0)
        return (tar == arr[ind]);
    bool nottake = solve(ind - 1, tar, arr);
    bool take = 0;
    if (tar >= arr[ind])
        take = solve(ind - 1, tar - arr[ind], arr);
    return (nottake || take);
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    return solve(n - 1, k, arr);
}
//****** ii memoization sol *****
bool solve(int ind, int tar, vector<int> &arr, vector<vector<int>> &dp)
{
    if (tar == 0)
        return 1;
    if (ind == 0)
        return (tar == arr[ind]);
    if (dp[ind][tar] != -1)
        return dp[ind][tar];
    bool nottake = solve(ind - 1, tar, arr, dp);
    bool take = 0;
    if (tar >= arr[ind])
        take = solve(ind - 1, tar - arr[ind], arr, dp);
    return dp[ind][tar] = (nottake || take);
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, k, arr, dp);
}
//***** tabulation ******
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if (arr[0] <= k)
        dp[0][arr[0]] = 1; // ind 0 tar same as arr[0] then true
    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 1; tar <= k; tar++)
        {
            bool nottake = dp[ind - 1][tar];
            bool take = 0;
            if (tar >= arr[ind])
                take = dp[ind - 1][tar - arr[ind]];
            dp[ind][tar] = (nottake || take);
        }
    }
    return dp[n - 1][k];
}
//***** space optimization ***
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<bool> prev(k + 1, 0), curr(k + 1, 0);
    prev[0] = curr[0] = 1;

    if (arr[0] <= k)
        prev[arr[0]] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 1; tar <= k; tar++)
        {
            bool nottake = prev[tar];
            bool take = 0;
            if (tar >= arr[ind])
                take = prev[tar - arr[ind]];
            curr[tar] = (nottake || take);
        }
        prev = curr;
    }
    return prev[k];
}
//*****
int main()
{

    return 0;
}