#include <bits/stdc++.h>
using namespace std;
//****** recusive solution ***** (copyed from chat gpt)
class Solution
{
public:
    bool ispossible(int i, int j, vector<vector<int>> &mat, int n, int m)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    int maxSquareFromCell(int i, int j, vector<vector<int>> &mat, int n, int m)
    {
        if (!ispossible(i, j, mat, n, m) || mat[i][j] == 0)
            return 0;

        int right = maxSquareFromCell(i, j + 1, mat, n, m);
        int down = maxSquareFromCell(i + 1, j, mat, n, m);
        int rightdown = maxSquareFromCell(i + 1, j + 1, mat, n, m);

        return 1 + min(right, min(down, rightdown));
    }

    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = max(ans, maxSquareFromCell(i, j, mat, n, m));
            }
        }

        return ans;
    }
};
//******** recusive solution babbar
class Solution
{
public:
    bool ispossible(int i, int j, vector<vector<int>> &mat, int n, int m)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    int maxSquareFromCell(int ans, int i, int j, vector<vector<int>> &mat, int n, int m)
    {
        if (!ispossible(i, j, mat, n, m) || mat[i][j] == 0)
            return 0;

        int right = maxSquareFromCell(i, j + 1, mat, n, m);
        int down = maxSquareFromCell(i + 1, j, mat, n, m);
        int rightdown = maxSquareFromCell(i + 1, j + 1, mat, n, m);

        int result = 1 + min(right, min(down, rightdown));
        ans = max(ans, result);
        return result;
    }

    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        int ans = 0;
        ans = max(ans, 0, 0, mat, n, m);
        return ans;
    }
};
//****** memoization *******
class Solution
{
public:
    int solve(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp)
    {
        if (i >= mat.size() || j >= mat[0].size())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int right = solve(mat, i, j + 1, maxi, dp);
        int diagonal = solve(mat, i + 1, j + 1, maxi, dp);
        int down = solve(mat, i + 1, j, maxi, dp);
        if (mat[i][j] == 1)
        {
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else
            return dp[i][j] = 0;
    }
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        // code here
        int maxi = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        solve(mat, 0, 0, maxi, dp);
        return maxi;
    }
};
//****** tabulation *******
class Solution
{
public:
    int solvetab(vector<vector<int>> &mat, int &maxi, int n, int m)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int right = dp[i][j + 1];
                int diagonal = dp[i + 1][j + 1];
                int down = dp[i + 1][j];
                if (mat[i][j] == 1)
                {
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return dp[0][0];
    }
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        // code here
        int maxi = 0;
        solvetab(mat, maxi, n, m);
        return maxi;
    }
};
//********** space optimization *******
class Solution
{
public:
    int solveso(vector<vector<int>> &mat, int &maxi, int n, int m)
    {
        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int right = curr[j + 1];
                int diagonal = next[j + 1];
                int down = next[j];
                if (mat[i][j] == 1)
                {
                    curr[j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, curr[j]);
                }
                else
                    curr[j] = 0;
            }
            next = curr;
        }
        return next[0];
    }
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        // code here
        int maxi = 0;
        solveso(mat, maxi, n, m);
        return maxi;
    }
};
//************

int main()
{

    return 0;
}