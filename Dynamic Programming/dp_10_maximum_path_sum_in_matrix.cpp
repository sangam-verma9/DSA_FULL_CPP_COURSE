// https://www.codingninjas.com/studio/problems/minimum-path-sum_985349?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include <bits/stdc++.h>
using namespace std;
//**** recusive ****** (TLE)
int solve(int i, int j, vector<vector<int>> &matrix, int n, int m)
{
    if (i == n - 1)
    {
        return matrix[i][j];
    }
    // down
    int op1 = matrix[i][j] + solve(i + 1, j, matrix, n, m);
    // down right
    int op2 = INT_MIN;
    if (j + 1 < m)
        op2 = matrix[i][j] + solve(i + 1, j + 1, matrix, n, m);
    // down left
    int op3 = INT_MIN;
    if (j - 1 >= 0)
        op3 = matrix[i][j] + solve(i + 1, j - 1, matrix, n, m);
    return max(op1, max(op2, op3));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int sr = 0;
    int sc = 0;
    int ans = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        ans = max(ans, solve(sr, sc, matrix, n, m));
        sc++;
    }
    return ans;
}
//**** memoization ***
int solve(int i, int j, vector<vector<int>> &matrix, int n, int m, vector<vector<int>> &dp)
{
    if (i == n - 1)
    {
        return matrix[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    // down
    int op1 = matrix[i][j] + solve(i + 1, j, matrix, n, m, dp);
    // down right
    int op2 = INT_MIN;
    if (j + 1 < m)
        op2 = matrix[i][j] + solve(i + 1, j + 1, matrix, n, m, dp);
    // down left
    int op3 = INT_MIN;
    if (j - 1 >= 0)
        op3 = matrix[i][j] + solve(i + 1, j - 1, matrix, n, m, dp);
    return dp[i][j] = max(op1, max(op2, op3));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int sr = 0;
    int sc = 0;
    int ans = INT_MIN;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < m; i++)
    {
        ans = max(ans, solve(sr, sc, matrix, n, m, dp));
        sc++;
    }
    return ans;
}
//****** Tabulation ******
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < m; i++)
    {
        dp[n - 1][i] = matrix[n - 1][i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int op1 = matrix[i][j] + dp[i + 1][j];
            // down right
            int op2 = INT_MIN;
            if (j + 1 < m)
                op2 = matrix[i][j] + dp[i + 1][j + 1];
            // down left
            int op3 = INT_MIN;
            if (j - 1 >= 0)
                op3 = matrix[i][j] + dp[i + 1][j - 1];
            dp[i][j] = max(op1, max(op2, op3));
        }
    }

    int ans = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        ans = max(ans, dp[0][i]);
    }
    return ans;
}
//********* spce optimizaton ******
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> prev(m, 0);
    for (int i = 0; i < m; i++)
    {
        prev[i] = matrix[n - 1][i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> curr(m, 0);
        for (int j = m - 1; j >= 0; j--)
        {
            int op1 = matrix[i][j] + prev[j];
            // down right
            int op2 = INT_MIN;
            if (j + 1 < m)
                op2 = matrix[i][j] + prev[j + 1];
            // down left
            int op3 = INT_MIN;
            if (j - 1 >= 0)
                op3 = matrix[i][j] + prev[j - 1];
            curr[j] = max(op1, max(op2, op3));
        }
        prev = curr;
    }

    int ans = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        ans = max(ans, prev[i]);
    }
    return ans;
}
//**********
int main()
{

    return 0;
}