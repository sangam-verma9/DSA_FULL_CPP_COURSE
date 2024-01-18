#include <bits/stdc++.h>
using namespace std;
// Idea is here we intact longest palindromic substring and for remaining
// char insert char , so ans is (total length - lps)
int lcs(string &s, string &t)
{
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}
int longestPalindromeSubsequence(string s)
{
    // Write your code here.
    string t = s;
    reverse(t.begin(), t.end());
    return lcs(s, t);
}
int minimumInsertions(string &str)
{
    // Write your code here.
    return (str.length() - longestPalindromeSubsequence(str));
}
int main()
{

    return 0;
}