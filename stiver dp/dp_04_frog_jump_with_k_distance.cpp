// https://www.codingninjas.com/studio/problems/minimal-cost_8180930?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM
#include<bits/stdc++.h>
        using namespace std;
//**** recusive solution ***
int solve(int ind, int k, vector<int> &height)
{
    if (ind == 1)
    {
        return 0;
    }
    if (ind <= k)
    {
        return abs(height[ind - 1] - height[0]);
    }
    int mini = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        int op = abs(height[ind - i - 1] - height[ind - 1]) + solve(ind - i, k, height);
        mini = min(op, mini);
    }
    return mini;
}
int minimizeCost(int n, int k, vector<int> &height)
{
    // Write your code here.
    return solve(n, k, height);
}
//**** memoization *****
int solve(int ind, int k, vector<int> &height, vector<int> &dp)
{
    if (ind == 1)
    {
        return 0;
    }
    if (ind <= k)
    {
        return abs(height[ind - 1] - height[0]);
    }
    if (dp[ind] != -1)
        return dp[ind];
    int mini = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        int op = abs(height[ind - i - 1] - height[ind - 1]) + solve(ind - i, k, height, dp);
        mini = min(op, mini);
    }
    return dp[ind] = mini;
}
int minimizeCost(int n, int k, vector<int> &height)
{
    // Write your code here.
    vector<int> dp(n + 1, -1);
    return solve(n, k, height, dp);
}
//*****
int main() {

return 0;
}