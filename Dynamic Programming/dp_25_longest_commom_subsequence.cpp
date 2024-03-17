#include <bits/stdc++.h>
using namespace std;
//***** recursion *******
int solve(int i, int j, string &s, string &t)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (s[i] == t[j])
    {
        return 1 + solve(i - 1, j - 1, s, t);
    }
    else
    {
        return max(solve(i - 1, j, s, t), solve(i, j - 1, s, t));
    }
}
int lcs(string s, string t)
{
    int n = s.length();
    int m = t.length();
    return solve(n - 1, m - 1, s, t);
}
//******** tabulation ****
int lcs(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // here we doing with shifting of index
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1]) // shifting of index
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}
//******* space optimization ***
int lcs(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    for (int i = 0; i <= n; i++)
        prev[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[m];
}
//********
int main()
{

    return 0;
}