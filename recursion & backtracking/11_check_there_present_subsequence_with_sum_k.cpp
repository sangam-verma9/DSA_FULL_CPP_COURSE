// https://www.naukri.com/code360/problems/subset-sum_630213
#include <bits/stdc++.h>
using namespace std;
bool solve(int ind, int n, int k, vector<int> &a, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;
    if (ind == n)
        return false;
    if (dp[ind][k] != -1)
        return dp[ind][k];
    bool op1 = solve(ind + 1, n, k, a, dp);
    bool op2 = false;
    if (k >= a[ind])
    {
        op2 = solve(ind + 1, n, k - a[ind], a, dp);
    }
    return dp[ind][k] = op1 || op2;
}
bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(0, n, k, a, dp);
}

int main()
{

    return 0;
}