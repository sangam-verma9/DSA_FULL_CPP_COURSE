#include <bits/stdc++.h>
using namespace std;
//****** recursion ******
int MinSquares(int n)
{
    // Code here
    if (n == 0)
    {
        return 0;
    }
    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, MinSquares(n - i * i) + 1);
    }
    return ans;
}
//****** memoization ***********
class Solution
{
public:
    int solvemem(int n, vector<int> &dp)
    {
        if (n == 0)
        {
            return 0;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int ans = n;
        for (int i = 1; i * i <= n; i++)
        {
            ans = min(ans, solvemem(n - i * i, dp) + 1);
        }
        return dp[n] = ans;
    }
    int MinSquares(int n)
    {
        // Code here
        vector<int> dp(n + 1, -1);
        return solvemem(n, dp);
    }
};
//******** tabulation ******
class Solution
{
public:
    int MinSquares(int n)
    {
        // Code here
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= n; j++)
            {
                if (i - j * j >= 0)
                    dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }
        return dp[n];
    }
};
/**********/
int main()
{

    return 0;
}