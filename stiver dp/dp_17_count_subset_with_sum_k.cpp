#include <bits/stdc++.h>
using namespace std;
//***** recusive *****
#include <bits/stdc++.h>
int solve(int ind, int tar, vector<int> &arr)
{
    if (tar == 0)
    {
        return 1;
    }
    if (ind == 0)
    {
        return (arr[ind] == tar);
    }
    int notT = solve(ind - 1, tar, arr);
    int take = 0;
    if (tar >= arr[ind])
        take = solve(ind - 1, tar - arr[ind], arr);
    return take + notT;
}
int findWays(vector<int> &arr, int k)
{
    // Write your code here.
    int n = arr.size();
    return solve(n - 1, k, arr);
}

//***** memoization ****
int M = 1000000007;
int solve(int ind, int tar, vector<int> &arr, vector<vector<int>> &dp)
{
    if (tar == 0)
    {
        return 1;
    }
    if (ind == 0)
    {
        return (arr[ind] == tar);
    }
    if (dp[ind][tar] != -1)
    {
        return dp[ind][tar];
    }

    int notT = solve(ind - 1, tar, arr, dp);
    int take = 0;
    if (tar >= arr[ind])
        take = solve(ind - 1, tar - arr[ind], arr, dp);
    return dp[ind][tar] = (take + notT) % M;
}
int findWays(vector<int> &arr, int k)
{
    // Write your code here.
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, k, arr, dp);
}
//***** Tabulation *******
int M = 1000000007;
int findWays(vector<int> &arr, int k)
{
    // Write your code here.
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if (arr[0] <= k)
        dp[0][arr[0]] = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 1; tar <= k; tar++)
        {
            int notT = dp[ind - 1][tar];
            int take = 0;
            if (tar >= arr[ind])
                take = dp[ind - 1][tar - arr[ind]];
            dp[ind][tar] = (take + notT) % M;
        }
    }
    return dp[n - 1][k];
}
//***** Space optimization *****
int M = 1000000007;
int findWays(vector<int> &arr, int k)
{
    // Write your code here.
    int n = arr.size();
    // vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    vector<int> prev(k + 1, 0), curr(k + 1, 0);
    prev[0] = curr[0] = 1;
    if (arr[0] <= k)
        prev[arr[0]] = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 1; tar <= k; tar++)
        {
            int notT = prev[tar];
            int take = 0;
            if (tar >= arr[ind])
                take = prev[tar - arr[ind]];
            curr[tar] = (take + notT) % M;
        }
        prev = curr;
    }
    return prev[k];
}
//************
int main()
{

    return 0;
}