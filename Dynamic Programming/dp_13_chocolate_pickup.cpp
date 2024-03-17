#include <bits/stdc++.h>
using namespace std;
//**** recurison ****
int solve(int i, int j1, int j2, vector<vector<int>> &grid, int r, int c)
{
    if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)
    {
        return -1e8;
    }
    if (i == r - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int op = 0;
            if (j1 == j2)
            {
                op = grid[i][j1];
            }
            else
            {
                op = grid[i][j1] + grid[i][j2];
            }
            op += solve(i + 1, j1 + dj1, j2 + dj2, grid, r, c);
            maxi = max(maxi, op);
        }
    }
    return maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    return solve(0, 0, c - 1, grid, r, c);
}
//*******  memoization ******
int solve(int i, int j1, int j2, vector<vector<int>> &grid, int r, int c, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)
    {
        return -1e8;
    }
    if (i == r - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1)
    {
        return dp[i][j1][j2];
    }

    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int op = 0;
            if (j1 == j2)
            {
                op = grid[i][j1];
            }
            else
            {
                op = grid[i][j1] + grid[i][j2];
            }
            op += solve(i + 1, j1 + dj1, j2 + dj2, grid, r, c, dp);
            maxi = max(maxi, op);
        }
    }
    return dp[i][j1][j2] = maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return solve(0, 0, c - 1, grid, r, c, dp);
}
//***** Tabulation *****
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));
    for (int j1 = 0; j1 < c; j1++)
    {
        for (int j2 = 0; j2 < c; j2++)
        {
            if (j1 == j2)
            {
                dp[r - 1][j1][j2] = grid[r - 1][j1];
            }
            else
            {
                dp[r - 1][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
            }
        }
    }
    for (int i = r - 2; i >= 0; i--)
    {
        for (int j1 = c - 1; j1 >= 0; j1--)
        {
            for (int j2 = c - 1; j2 >= 0; j2--)
            {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int op = 0;
                        if (j1 == j2)
                        {
                            op = grid[i][j1];
                        }
                        else
                        {
                            op = grid[i][j1] + grid[i][j2];
                        }
                        if (j1 + dj1 >= 0 && j1 + dj1 < c && j2 + dj2 >= 0 && j2 + dj2 < c)
                            op += dp[i + 1][j1 + dj1][j2 + dj2];
                        else
                            op += -1e8;
                        maxi = max(maxi, op);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][c - 1];
}
//********* space optimization *****
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<int>> prev(c, vector<int>(c, 0));
    for (int j1 = 0; j1 < c; j1++)
    {
        for (int j2 = 0; j2 < c; j2++)
        {
            if (j1 == j2)
            {
                prev[j1][j2] = grid[r - 1][j1];
            }
            else
            {
                prev[j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
            }
        }
    }
    for (int i = r - 2; i >= 0; i--)
    {
        vector<vector<int>> curr(c, vector<int>(c, 0));

        for (int j1 = c - 1; j1 >= 0; j1--)
        {
            for (int j2 = c - 1; j2 >= 0; j2--)
            {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int op = 0;
                        if (j1 == j2)
                        {
                            op = grid[i][j1];
                        }
                        else
                        {
                            op = grid[i][j1] + grid[i][j2];
                        }
                        if (j1 + dj1 >= 0 && j1 + dj1 < c && j2 + dj2 >= 0 && j2 + dj2 < c)
                            op += prev[j1 + dj1][j2 + dj2];
                        else
                            op += -1e8;
                        maxi = max(maxi, op);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        prev = curr;
    }
    return prev[0][c - 1];
}
//**********
int main()
{

    return 0;
}