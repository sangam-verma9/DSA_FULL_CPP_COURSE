// https://www.codingninjas.com/studio/problems/unique-paths-ii_977241?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include <bits/stdc++.h>
using namespace std;
//****** recursion *******

//***** memoization ******
bool ispossible(int n, int m, vector<vector<int>> &mat)
{
    return n >= 0 && m >= 0 && mat[n][m] == 0;
}
int solve(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    if (n == 0 && m == 0)
    {
        return 1;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    // up
    int newr = n - 1;
    int newc = m;
    int op1 = 0;
    int op2 = 0;
    if (ispossible(newr, newc, mat))
    {
        op1 = solve(newr, newc, mat, dp);
    }
    // left
    newr = n;
    newc = m - 1;
    if (ispossible(newr, newc, mat))
    {
        op2 = solve(newr, newc, mat, dp);
    }
    return dp[n][m] = op1 + op2;
}
int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = solve(n - 1, m - 1, mat, dp);
    return ans;
}
//***** tabulation *****
int M = 1000000007;
int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == -1)
            {
                dp[i][j] = 0;
            }
            else if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                int op1 = 0;
                int op2 = 0;
                if (i > 0)
                    op1 = dp[i - 1][j];
                if (j > 0)
                    op2 = dp[i][j - 1];
                dp[i][j] = (op1 + op2) % M;
            }
        }
    }
    return dp[n - 1][m - 1];
}
int main()
{

    return 0;
}