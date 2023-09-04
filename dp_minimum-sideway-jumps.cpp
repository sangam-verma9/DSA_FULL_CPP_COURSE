#include <bits/stdc++.h>
using namespace std;
// ******** recursive approach *********
class Solution
{
public:
    int solve(int ind, vector<int> &ob, int n, int line)
    {
        if (ind == n)
        {
            return 0;
        }
        if (ob[ind + 1] != line)
        {
            return solve(ind + 1, ob, n, line);
        }
        else
        {
            int ans = 1e7;
            for (int i = 1; i <= 3; i++)
            {
                if (ob[ind] != i && i != line)
                {
                    ans = min(ans, 1 + solve(ind + 1, ob, n, i));
                }
            }
            return ans;
        }
    }
    int minSideJumps(vector<int> &obstacles)
    {
        int n = obstacles.size();
        return solve(0, obstacles, n, 2);
    }
};
//********** memoization ******
class Solution
{
public:
    int solvemem(int ind, vector<int> &ob, int n, int line, vector<vector<int>> &dp)
    {
        if (ind == n)
        {
            return 0;
        }
        if (dp[line][ind] != -1)
        {
            return dp[line][ind];
        }
        if (ob[ind + 1] != line)
        {
            return solvemem(ind + 1, ob, n, line, dp);
        }
        else
        {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            {
                if (ob[ind] != i && i != line)
                {
                    ans = min(ans, 1 + solvemem(ind, ob, n, i, dp));
                }
            }
            return dp[line][ind] = ans;
        }
    }
    int minSideJumps(vector<int> &obstacles)
    {
        int n = obstacles.size();
        vector<vector<int>> dp(4, vector<int>(n, -1));
        return solvemem(0, obstacles, n - 1, 2, dp);
    }
};
//************ tabulation method *******
class Solution
{
public:
    int solvetab(vector<int> &ob)
    {
        int n = ob.size() - 1;
        vector<vector<int>> dp(4, vector<int>(n + 1, 1e7));
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int line = 1; line < 4; line++)
            {
                if (ob[ind + 1] != line)
                {
                    dp[line][ind] = dp[line][ind + 1];
                }
                else
                {
                    int ans = 1e7;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (ob[ind] != i && i != line)
                        {
                            ans = min(ans, 1 + dp[i][ind + 1]); // here [ind] not -> [ind+1] because if there is not already fill by value rather than int_max so we copy provious value
                        }
                    }
                    dp[line][ind] = ans;
                }
            }
        }
        return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
    }
    int minSideJumps(vector<int> &obstacles)
    {
        return solvetab(obstacles);
    }
};
//********** space optimization ********
class Solution
{
public:
    int solveso(vector<int> &ob)
    {
        int n = ob.size() - 1;
        vector<int> curr(4, 1e7);
        vector<int> next(4, 1e7);
        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int line = 1; line < 4; line++)
            {
                if (ob[ind + 1] != line)
                {
                    curr[line] = next[line];
                }
                else
                {
                    int ans = 1e7;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (ob[ind] != i && i != line)
                        {
                            ans = min(ans, 1 + next[i]);
                        }
                    }
                    curr[line] = ans;
                }
            }
            next = curr;
        }
        return min(next[2], min(1 + next[1], 1 + next[3]));
    }
    int minSideJumps(vector<int> &obstacles)
    {
        return solveso(obstacles);
    }
};
//***********
int main()
{

    return 0;
}