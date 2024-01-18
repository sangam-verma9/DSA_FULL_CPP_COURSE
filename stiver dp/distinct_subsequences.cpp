#include <bits/stdc++.h>
using namespace std;
//****** recursion method ***
// Here idea is match subsequence from the last if char match then we can
// take it or not take it so going for two calles if take then i-1 and j-1
// and if not take then i-1 in str only  , now if not match then we have to
// not take so only i-1 in str string , now for base case if str exeosted
// then return 0 because not possible to make sub if sub if exeosted then
// return 1 that means we make it
// solve(i,j,str,sub) => respresent that number of possible
// sub in str to 0...i in str and 0...j in sub

int solve(int i, int j, string &str, string &sub)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;
    if (str[i] == sub[j])
    {
        return solve(i - 1, j - 1, str, sub) + solve(i - 1, j, str, sub);
    }
    else
    {
        return solve(i - 1, j, str, sub);
    }
}
int distinctSubsequences(string &str, string &sub)
{
    // Write your code here.
    int n = str.length();
    int m = sub.length();
    return solve(n - 1, m - 1, str, sub);
}
//***** memoization ******
int solve(int i, int j, string &str, string &sub, vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (str[i] == sub[j])
    {
        return dp[i][j] = solve(i - 1, j - 1, str, sub, dp) + solve(i - 1, j, str, sub, dp);
    }
    else
    {
        return dp[i][j] = solve(i - 1, j, str, sub, dp);
    }
}
int distinctSubsequences(string &str, string &sub)
{
    // Write your code here.
    int n = str.length();
    int m = sub.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, str, sub, dp);
}

//********* Tabulation ******
int distinctSubsequences(string &str, string &sub)
{
    // Write your code here.
    int n = str.length();
    int m = sub.length();
    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int j = 1; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str[i - 1] == sub[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return int(dp[n][m]);
}
//********
int main()
{

    return 0;
}