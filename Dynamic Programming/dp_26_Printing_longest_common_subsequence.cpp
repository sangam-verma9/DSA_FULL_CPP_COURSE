#include <bits/stdc++.h>
using namespace std;
//**** recusion *****
string longest_common_subsequence(const string &s1, const string &s2)
{
    int m = s1.length();
    int n = s2.length();

    if (m == 0 || n == 0)
    {
        return "";
    }

    if (s1[m - 1] == s2[n - 1])
    {
        return longest_common_subsequence(s1.substr(0, m - 1), s2.substr(0, n - 1)) + s1[m - 1];
    }
    else
    {
        string left = longest_common_subsequence(s1.substr(0, m - 1), s2);
        string right = longest_common_subsequence(s1, s2.substr(0, n - 1));
        return (left.length() > right.length()) ? left : right;
    }
}

//****** Tabulation *****
string longest_common_subsequence(const string &s, const string &t)
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
    int len = dp[n][m];
    string ans = "";
    for (int i = 0; i < len; i++)
    {
        ans += '$';
    }
    int ind = len - 1;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans[ind] = s[i - 1];
            ind--;
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    return ans;
}

    int main()
    {
        return 0;
    }