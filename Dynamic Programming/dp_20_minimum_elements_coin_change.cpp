// https://leetcode.com/problems/coin-change
#include <bits/stdc++.h>
using namespace std;
//**** recurisve ****
int solve(int ind, vector<int> &num, int x)
{
    if (ind == 0)
    {
        if (x % num[ind] == 0)
            return x / num[ind];
        else
            return 1e9;
    }
    int notT = 0 + solve(ind - 1, num, x);
    int take = 1e9;
    if (x >= num[ind])
        take = 1 + solve(ind, num, x - num[ind]);
    return min(take, notT);
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    if (solve(n - 1, num, x) == 1e9)
        return -1;
    return solve(n - 1, num, x);
}
//**** memoization ***
int solve(int ind, vector<int> &num, int x, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (x % num[ind] == 0)
            return x / num[ind];
        else
            return 1e9;
    }
    if (dp[ind][x] != -1)
    {
        return dp[ind][x];
    }
    int notT = 0 + solve(ind - 1, num, x, dp);
    int take = 1e9;
    if (x >= num[ind])
        take = 1 + solve(ind, num, x - num[ind], dp);
    return dp[ind][x] = min(take, notT);
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    int a = solve(n - 1, num, x, dp);
    if (a == 1e9)
        return -1;
    return a;
}
//********* Tabulation ****
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    for (int i = 0; i <= x; i++)
    {
        if (i % num[0] == 0)
            dp[0][i] = i / num[0];
        else
            dp[0][i] = 1e9;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 0; tar <= x; tar++)
        {
            int notT = 0 + dp[ind - 1][tar];
            int take = 1e9;
            if (tar >= num[ind])
                take = 1 + dp[ind][tar - num[ind]];
            dp[ind][tar] = min(take, notT);
        }
    }
    int a = dp[n - 1][x];
    if (a == 1e9)
        return -1;
    return a;
}
//***** space optimizaion ****
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<int> prev(x + 1, 0);
    for (int i = 0; i <= x; i++)
    {
        if (i % num[0] == 0)
            prev[i] = i / num[0];
        else
            prev[i] = 1e9;
    }
    for (int ind = 1; ind < n; ind++)
    {
        vector<int> curr(x + 1, 0);
        for (int tar = 0; tar <= x; tar++)
        {
            int notT = 0 + prev[tar];
            int take = 1e9;
            if (tar >= num[ind])
                take = 1 + curr[tar - num[ind]];
            curr[tar] = min(take, notT);
        }
        prev = curr;
    }
    int a = prev[x];
    if (a == 1e9)
        return -1;
    return a;
}
//*****
int main()
{

    return 0;
}