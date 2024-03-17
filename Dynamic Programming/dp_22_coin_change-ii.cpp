// https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_630471
#include<bits/stdc++.h>
using namespace std;
//**** recusive ****
long solve(int ind, int *denominations, int value)
{
    if (ind < 0)
        return 0;
    if (value == 0)
        return 1;

    int notT = solve(ind - 1, denominations, value);
    int take = 0;
    if (value >= denominations[ind])
        take = solve(ind, denominations, value - denominations[ind]);
    return take + notT;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    return solve(n - 1, denominations, value);
}
//****** memoization ***
#include <bits/stdc++.h>
long solve(int ind, int *denominations, int value, vector<vector<long>> &dp)
{
    if (ind == 0)
    {
        if (value % denominations[0] == 0)
            return 1;
        return 0;
    }
    if (value == 0)
        return 1;
    if (dp[ind][value] != -1)
    {
        dp[ind][value];
    }
    long notT = solve(ind - 1, denominations, value, dp);
    long take = 0;
    if (value >= denominations[ind])
        take = solve(ind, denominations, value - denominations[ind], dp);
    return dp[ind][value] = take + notT;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    return solve(n - 1, denominations, value, dp);
}

//***** tabulation ***
#include <bits/stdc++.h>
long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    vector<vector<long>> dp(n, vector<long>(value + 1, 0));
    for (int i = 0; i <= value; i++)
    {
        if (i % denominations[0] == 0)
            dp[0][i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 1; tar <= value; tar++)
        {
            long notT = dp[ind - 1][tar];
            long take = 0;
            if (tar >= denominations[ind])
                take = dp[ind][tar - denominations[ind]];
            dp[ind][tar] = take + notT;
        }
    }
    return dp[n - 1][value];
}
//****

int main() {

return 0;
}