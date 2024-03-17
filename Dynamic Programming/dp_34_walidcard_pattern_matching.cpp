#include <bits/stdc++.h>
using namespace std;
//******* recusion ******
bool solve(int i, int j, string &pattern, string &text)
{
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (i >= 0 && j < 0)
    {
        for (int ii = 0; ii <= i; ii++)
        {
            if (pattern[ii] != '*')
                return false;
        }
        return true;
    }
    if (pattern[i] == text[j] || pattern[i] == '?')
    {
        return solve(i - 1, j - 1, pattern, text);
    }
    if (pattern[i] == '*')
    {
        return solve(i - 1, j, pattern, text) || solve(i, j - 1, pattern, text);
    }
    return false;
}
bool wildcardMatching(string pattern, string text)
{
    // Write your code here.
    int n = pattern.length();
    int m = text.length();
    return solve(n - 1, m - 1, pattern, text);
}
//******** memoization ****
bool solve(int i, int j, string &pattern, string &text, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (i >= 0 && j < 0)
    {
        for (int ii = 0; ii <= i; ii++)
        {
            if (pattern[ii] != '*')
                return false;
        }
        return true;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (pattern[i] == text[j] || pattern[i] == '?')
    {
        return dp[i][j] = solve(i - 1, j - 1, pattern, text, dp);
    }
    if (pattern[i] == '*')
    {
        return dp[i][j] = solve(i - 1, j, pattern, text, dp) || solve(i, j - 1, pattern, text, dp);
    }
    return dp[i][j] = false;
}
bool wildcardMatching(string pattern, string text)
{
    // Write your code here.
    int n = pattern.length();
    int m = text.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, pattern, text, dp);
}
//******** memoization with shifting of ind ******
bool solve(int i, int j, string &pattern, string &text, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return true;
    if (i == 0 && j > 0)
        return false;
    if (i > 0 && j == 0)
    {
        for (int ii = 1; ii <= i; ii++)
        {
            if (pattern[ii - 1] != '*')
                return false;
        }
        return true;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
    {
        return dp[i][j] = solve(i - 1, j - 1, pattern, text, dp);
    }
    if (pattern[i - 1] == '*')
    {
        return dp[i][j] = solve(i - 1, j, pattern, text, dp) || solve(i, j - 1, pattern, text, dp);
    }
    return dp[i][j] = false;
}
bool wildcardMatching(string pattern, string text)
{
    // Write your code here.
    int n = pattern.length();
    int m = text.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(n, m, pattern, text, dp);
}
//******** tabulation *******
bool wildcardMatching(string pattern, string text)
{
    // Write your code here.
    int n = pattern.length();
    int m = text.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1));
    dp[0][0] = 1;
    for (int j = 1; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int ii = 1; ii <= i; ii++)
        {
            if (pattern[ii - 1] != '*')
            {
                dp[i][0] = 0;
                break;
            }
        }
        // here we write if all dp is 0
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (pattern[i - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else
                dp[i][j] = false;
        }
    }
    return dp[n][m];
}
//****** space optimization ******
bool wildcardMatching(string pattern, string text)
{
    // Write your code here.
    int n = pattern.length();
    int m = text.length();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    prev[0] = 1;
    for (int j = 1; j <= m; j++)
        prev[j] = 0;
    bool sa = 1;
    curr[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (pattern[i - 1] != '*' || sa == 0)
        {
            curr[0] = 0;
            sa = 0;
        }
        for (int j = 1; j <= m; j++)
        {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
            {
                curr[j] = prev[j - 1];
            }
            else if (pattern[i - 1] == '*')
            {
                curr[j] = prev[j] || curr[j - 1];
            }
            else
                curr[j] = false;
        }
        prev = curr;
    }
    return prev[m];
}
//*******
int main()
{

    return 0;
}