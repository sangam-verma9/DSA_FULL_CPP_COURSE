#include <bits/stdc++.h>
using namespace std;
//**** recusive solution ***
int solve(int ind, int pind, int arr[], int n)
{
    if (ind == n)
        return 0;
    int op1 = 0 + solve(ind + 1, pind, arr, n);
    int op2 = 0;
    if (pind == -1 || arr[pind] < arr[ind])
    {
        op2 = 1 + solve(ind + 1, ind, arr, n);
    }
    return max(op1, op2);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    return solve(0, -1, arr, n);
}
//*** memoization ****
int solve(int ind, int pind, int arr[], int n, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind][pind + 1] != -1)
        return dp[ind][pind + 1];
    int op1 = 0 + solve(ind + 1, pind, arr, n, dp);
    int op2 = 0;
    if (pind == -1 || arr[pind] < arr[ind])
    {
        op2 = 1 + solve(ind + 1, ind, arr, n, dp);
    }
    return dp[ind][pind + 1] = max(op1, op2);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(0, -1, arr, n, dp);
}
//**** tabulation ***
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // no need to declare base case because alread they 0
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int pind = ind - 1; pind >= -1; pind--)
        {
            int op1 = 0 + dp[ind + 1][pind + 1];
            int op2 = 0;
            if (pind == -1 || arr[pind] < arr[ind])
            {
                op2 = 1 + dp[ind + 1][ind + 1];
            }
            dp[ind][pind + 1] = max(op1, op2);
        }
    }
    return dp[0][-1 + 1];
}
//**** space optimization ****
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> next(n + 1, 0), curr(n + 1, 0);
    // no need to declare base case because alread they 0
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int pind = ind - 1; pind >= -1; pind--)
        {
            int op1 = 0 + next[pind + 1];
            int op2 = 0;
            if (pind == -1 || arr[pind] < arr[ind])
            {
                op2 = 1 + next[ind + 1];
            }
            curr[pind + 1] = max(op1, op2);
        }
        next = curr;
    }
    return next[-1 + 1];
}
//****** Another approach ****
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n, 1);
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i])
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}
//******  printing longest common subsequence ****
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n, 1), hash(n, 1); // here we use hash array for backtrack and find ele of LIS
    int maxi = 1;
    int lastind = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastind = i;
        }
    }
    vector<int> ans;
    ans.push_back(arr[lastind]);
    while (hash[lastind] != lastind)
    {
        lastind = hash[lastind];
        ans.push_back(arr[lastind]);
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans) // printing LIS
    {
        cout << i << " ";
    }
    cout << endl;
    return maxi; // return length
}
//******

int main()
{

    return 0;
}