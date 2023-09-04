#include <bits/stdc++.h>
using namespace std;
//********* recursion ****
class Solution
{
public:
    int solve(vector<int> &v, int i, int j)
    {
        if (i + 1 == j)
        {
            return 0;
        }
        int ans = INT_MAX;
        for (int n = i + 1; n < j; n++)
        {
            ans = min(ans, v[i] * v[j] * v[n] + solve(v, i, n) + solve(v, n, j));
        }
        return ans;
    }
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();
        return solve(values, 0, n - 1);
    }
};
//******* memoization *******
class Solution
{
public:
    int solve(vector<int> &v, int i, int j, vector<vector<int>> &dp)
    {
        if (i + 1 == j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = INT_MAX;
        for (int n = i + 1; n < j; n++)
        {
            ans = min(ans, v[i] * v[j] * v[n] + solve(v, i, n, dp) + solve(v, n, j, dp));
        }
        return dp[i][j] = ans;
    }
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(values, 0, n - 1, dp);
    }
};
//*********** tabulation *******
class Solution
{
public:
    int solvetab(vector<int> &v)
    {
        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 2; j < n; j++)
            {
                int ans = INT_MAX;
                for (int n = i + 1; n < j; n++)
                {
                    ans = min(ans, v[i] * v[j] * v[n] + dp[i][n] + dp[n][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n - 1];
    }
    int minScoreTriangulation(vector<int> &values)
    {
        return solvetab(values);
    }
};
//***********
int main()
{

    return 0;
}