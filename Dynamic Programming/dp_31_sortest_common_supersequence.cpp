// https://leetcode.com/problems/shortest-common-supersequence
#include <bits/stdc++.h>
using namespace std;
// Idea here we first create dp matrix of lcs then some coputation
//  perform on matrix how to add ele on our ans , here we starting
//  from last co-ordinate then check if char match then add to ans
//  if not match then caheck where is greater value then that side
// we move and other side add in our ans and checking for all when
// i>0 and j>0 , now if any string remaining then add to our ans string finally return
string shortestSupersequence(string s, string t)
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
    int i = n, j = m;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans += s[i - 1];
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans += s[i - 1];
            i--;
        }
        else
        {
            ans += t[j - 1];
            j--;
        }
    }
    while (i > 0)
    {
        ans += s[i - 1];
        i--;
    }

    while (j > 0)
    {
        ans += t[j - 1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{

    return 0;
}