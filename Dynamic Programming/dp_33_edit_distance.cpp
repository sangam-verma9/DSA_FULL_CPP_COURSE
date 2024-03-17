#include <bits/stdc++.h>
using namespace std;
//****** recursion ****
int solve(int i, int j, string &s, string &t)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (s[i] == t[j])
    {
        return 0 + solve(i - 1, j - 1, s, t);
    }
    // one opertaion take if we going to insert, delete, updata below 👇
    return 1 + min(solve(i, j - 1, s, t), min(solve(i - 1, j, s, t), solve(i - 1, j - 1, s, t)));
}
int editDistance(string str1, string str2)
{
    // write you code here
    int n = str1.length();
    int m = str2.length();
    return solve(n - 1, m - 1, str1, str2);
}
//******* memoization *****
int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s[i] == t[j])
    {
        return 0 + solve(i - 1, j - 1, s, t, dp);
    }
    return dp[i][j] = 1 + min(solve(i, j - 1, s, t, dp), min(solve(i - 1, j, s, t, dp), solve(i - 1, j - 1, s, t, dp)));
}
int editDistance(string str1, string str2)
{
    // write you code here
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, str1, str2, dp);
}
//******** memoization with shifing of ind ***
int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (i == 0)
        return j;
    if (j == 0)
        return i;
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s[i - 1] == t[j - 1])
    {
        return 0 + solve(i - 1, j - 1, s, t, dp);
    }
    return dp[i][j] = 1 + min(solve(i, j - 1, s, t, dp), min(solve(i - 1, j, s, t, dp), solve(i - 1, j - 1, s, t, dp)));
}
int editDistance(string str1, string str2)
{
    // write you code here
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(n, m, str1, str2, dp);
}
//******* Tabulation ***
int editDistance(string str1, string str2)
{
    // write you code here
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
        }
    }
    return dp[n][m];
}
//******* space optimizaton ****
int editDistance(string str1, string str2)
{
    // write you code here
    int n = str1.length();
    int m = str2.length();
    // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    for (int j = 0; j <= m; j++)
        prev[j] = j;
    for (int i = 1; i <= n; i++)
    {
        curr[0] = i; // here at every row we have to assign first ele to i
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                curr[j] = prev[j - 1];
            }
            else
                curr[j] = 1 + min(curr[j - 1], min(prev[j], prev[j - 1]));
        }
        prev = curr;
    }
    return prev[m];
}
//******
int main()
{

    return 0;
}