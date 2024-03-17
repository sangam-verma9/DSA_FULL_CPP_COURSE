// https://www.codingninjas.com/studio/problems/unique-paths_1081470?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include <bits/stdc++.h>
using namespace std;
//****** recusion *****
int solve(int i, int j, int m, int n)
{
    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }
    if (i >= m || j >= n)
    {
        return 0;
    }

    int op1 = solve(i, j + 1, m, n);
    int op2 = solve(i + 1, j, m, n);

    return op1 + op2;
}

int uniquePaths(int m, int n)
{
    int ans = solve(0, 0, m, n);
    return ans;
}
//****** memoization ******
int solve(int i, int j, int m, int n, vector<vector<int>> &memo)
{
    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }
    if (i >= m || j >= n)
    {
        return 0;
    }

    // Check if the result is already memoized.
    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }

    int op1 = solve(i, j + 1, m, n, memo);
    int op2 = solve(i + 1, j, m, n, memo);

    // Memoize the result before returning.
    memo[i][j] = op1 + op2;

    return memo[i][j];
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> memo(m, vector<int>(n, -1));
    int ans = solve(0, 0, m, n, memo);
    return ans;
}

// ****** tabulation ********
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}
//*****
int main()
{

    return 0;
}