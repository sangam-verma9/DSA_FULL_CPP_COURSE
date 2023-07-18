#include <bits/stdc++.h>
using namespace std;
//***** noraml recursion
int solve(int n, int &x, int &y, int &z)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }
    int xs = 1 + solve(n - x, x, y, z);
    int ys = 1 + solve(n - y, x, y, z);
    int zs = 1 + solve(n - z, x, y, z);
    return max(xs, max(ys, zs));
}
int cutSegments(int n, int x, int y, int z)
{
    // Write your code here.
    int ans = solve(n, x, y, z);
    if (ans < 0)
        return 0;
    return ans;
}
//****
//****** memoization
int solve(int n, int &x, int &y, int &z, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }
    if (dp[n] != -1)
        return dp[n];
    int xs = 1 + solve(n - x, x, y, z, dp);
    int ys = 1 + solve(n - y, x, y, z, dp);
    int zs = 1 + solve(n - z, x, y, z, dp);
    dp[n] = max(xs, max(ys, zs));
    return dp[n];
}
int cutSegments(int n, int x, int y, int z)
{
    // Write your code here.
    vector<int> dp(n + 1, -1);
    int ans = solve(n, x, y, z, dp);
    if (ans < 0)
        return 0;
    return ans;
}
//**** tabulation method
int cutSegments(int n, int x, int y, int z)
{
    // Write your code here.
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0)
        {
            dp[i] = max(dp[i], dp[i - x] + 1);
        }
        if (i - y >= 0)
        {
            dp[i] = max(dp[i], dp[i - y] + 1);
        }
        if (i - z >= 0)
        {
            dp[i] = max(dp[i], dp[i - z] + 1);
        }
    }
    if (dp[n] < 0)
        return 0;
    return dp[n];
}
//***

int main()
{

    return 0;
}