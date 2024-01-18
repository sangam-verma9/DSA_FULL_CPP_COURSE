#include <bits/stdc++.h>
using namespace std;
//***** recusion *****
bool ispossible(int i, int j, vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    return i >= 0 && j >= 0;
}
int solve(int i, int j, vector<vector<int>> &grid)
{
    if (i == 0 && j == 0)
    {
        return grid[0][0];
    }
    int op1 = INT_MAX;
    int op2 = INT_MAX;

    if (ispossible(i, j - 1, grid))
    {
        op1 = grid[i][j] + solve(i, j - 1, grid);
    }
    if (ispossible(i - 1, j, grid))
    {
        op2 = grid[i][j] + solve(i - 1, j, grid);
    }
    return min(op1, op2);
}
int minSumPath(vector<vector<int>> &grid)
{
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    int ans = solve(n - 1, m - 1, grid);
    return ans;
}
//**** memoization ****
bool ispossible(int i, int j, vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    return i >= 0 && j >= 0;
}
int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
    {
        return grid[0][0];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int op1 = INT_MAX;
    int op2 = INT_MAX;

    if (ispossible(i, j - 1, grid))
    {
        op1 = grid[i][j] + solve(i, j - 1, grid, dp);
    }
    if (ispossible(i - 1, j, grid))
    {
        op2 = grid[i][j] + solve(i - 1, j, grid, dp);
    }
    return dp[i][j] = min(op1, op2);
}
int minSumPath(vector<vector<int>> &grid)
{
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = solve(n - 1, m - 1, grid, dp);
    return ans;
}
//********** tabulation ****
int minSumPath(vector<vector<int>> &grid)
{
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int op1 = INT_MAX;
            int op2 = INT_MAX;
            if (i > 0)
                op1 = grid[i][j] + dp[i - 1][j];
            if (j > 0)
                op2 = grid[i][j] + dp[i][j - 1];
            dp[i][j] = min(op1, op2);
        }
    }
    return dp[n - 1][m - 1];
}
//******** space optimization *******
int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                curr[0] = grid[0][0];
                continue;
            }
            int op1 = INT_MAX;
            int op2 = INT_MAX;
            if (i > 0)
                op1 = grid[i][j] + prev[j];
            if (j > 0)
                op2 = grid[i][j] + curr[j - 1];
            curr[j] = min(op1, op2);
        }
        prev = curr;
    }
    return prev[m - 1];
}
//***********

int main()
{

    return 0;
}