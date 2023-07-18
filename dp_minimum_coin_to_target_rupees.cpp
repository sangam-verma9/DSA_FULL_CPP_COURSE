#include <bits/stdc++.h>
//****** noraml recursion
int solve1(vector<int> &num, int x)
{
    if (x == 0)
        return 0;
    if (x < 0)
        return INT_MAX;
    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solve1(num, x - num[i]);
        mini = min(mini, ans + 1);
    }
    return mini;
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int ans = solve1(num, x);
    if (ans == INT_MAX)
        return -1;
    return ans;
}
//****** memoization
int solve2(vector<int> &num, int x, vector<int> &dp)
{
    if (x == 0)
        return 0;
    if (x < 0)
        return INT_MAX;

    if (dp[x] != -1)
        return dp[x];
    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solve2(num, x - num[i]);
        mini = min(mini, ans + 1);
    }
    dp[x] = mini;
    return dp[x];
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    vector<int> dp(x + 1, -1);
    int ans = solve2(num, x, dp);
    if (ans == INT_MAX)
        return -1;
    return ans;
}
//****** tabulation method
int solveTab(vector<int> &num, int x)
{
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0 && dp[i - num[j] != INT_MAX])
            {
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
            }
        }
    }
    if (dp[x] == INT_MAX)
        return -1;
    return dp[x];
}
//******

using namespace std;

int main()
{

    return 0;
}