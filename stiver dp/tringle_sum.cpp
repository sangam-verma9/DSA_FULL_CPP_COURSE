#include <bits/stdc++.h>
using namespace std;
//****** recursive ****
bool ispossible(int i, int j, int n)
{
    return i < n && j <= i;
}
int solve(int i, int j, vector<vector<int>> &triangle, int n)
{
    if (i == n - 1)
    {
        return triangle[i][j];
    }
    int op1 = INT_MAX;
    int op2 = INT_MAX;
    // down
    if (ispossible(i + 1, j, n))
    {
        op1 = triangle[i][j] + solve(i + 1, j, triangle, n);
    }
    // diagonal
    if (ispossible(i + 1, j + 1, n))
    {
        op2 = triangle[i][j] + solve(i + 1, j + 1, triangle, n);
    }
    return min(op1, op2);
}
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    int ans = solve(0, 0, triangle, n);
    return ans;
}
//*********** memoization ********
bool ispossible(int i, int j, int n)
{
    return i < n && j <= i;
}
int solve(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{
    if (i == n - 1)
    {
        return triangle[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int op1 = INT_MAX;
    int op2 = INT_MAX;
    // down
    if (ispossible(i + 1, j, n))
    {
        op1 = triangle[i][j] + solve(i + 1, j, triangle, n, dp);
    }
    if (ispossible(i + 1, j + 1, n))
    {
        op2 = triangle[i][j] + solve(i + 1, j + 1, triangle, n, dp);
    }
    return dp[i][j] = min(op1, op2);
}
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans = solve(0, 0, triangle, n, dp);

    return ans;
}
//******* tabulation *********
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        dp[n - 1][i] = triangle[n - 1][i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int op1 = triangle[i][j] + dp[i + 1][j];
            int op2 = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(op1, op2);
        }
    }
    return dp[0][0];
}
//********** space optimization *******
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<int> prev(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        prev[i] = triangle[n - 1][i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> curr(n, 0);
        for (int j = i; j >= 0; j--)
        {
            int op1 = triangle[i][j] + prev[j];
            int op2 = triangle[i][j] + prev[j + 1];
            curr[j] = min(op1, op2);
        }
        prev = curr;
    }
    return prev[0];
}
//***********
int main()
{

    return 0;
}