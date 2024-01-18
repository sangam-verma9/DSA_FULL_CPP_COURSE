#include <bits/stdc++.h>
using namespace std;
// here we find s1-s2=d  =>  tsum-s2-s2=d  => s2=(tsum-d)/2
int M = 1000000007;
int solve(int ind, int tar, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (tar == 0 && arr[0] == 0) // target 0 and array ele is 0 then 2 case take or nottake
            return 2;
        if (tar == 0 || arr[0] == tar) // target 0 but arr ele not 0  or tar= arr ele the only one case
            return 1;
        return 0;
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
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, k, arr, dp);
}
int countPartitions(int n, int d, vector<int> &arr)
{
    int tsum = 0;
    for (int i = 0; i < n; i++)
    {
        tsum += arr[i];
    }
    if (tsum - d < 0 || (tsum - d) % 2 != 0)
        return 0;
    return findWays(arr, (tsum - d) / 2);
}
// **** Tabulation *****
int M = 1000000007;
int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    if (arr[0] != 0 && arr[0] <= k)
        dp[0][arr[0]] = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 0; tar <= k; tar++)
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
int countPartitions(int n, int d, vector<int> &arr)
{
    int tsum = 0;
    for (int i = 0; i < n; i++)
    {
        tsum += arr[i];
    }
    if (tsum - d < 0 || (tsum - d) % 2 != 0)
        return 0;
    return findWays(arr, (tsum - d) / 2);
}
//*******
int main()
{

    return 0;
}