#include <bits/stdc++.h>
using namespace std;
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
bool canPartition(vector<int> &arr, int n)
{
    // Write your code here.
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
        return false;
    int tar = sum / 2;
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return solve(n - 1, tar, arr, dp);
}
int main()
{

    return 0;
}