#include <bits/stdc++.h>
using namespace std;
//****** recusion approach ******
class Solution
{
public:
    int solve(vector<int> &satisfaction, int ind, int time)
    {
        if (ind == satisfaction.size())
        {
            return 0;
        }
        int include = satisfaction[ind] * (time + 1) + solve(satisfaction, ind + 1, time + 1);
        int exclude = 0 + solve(satisfaction, ind + 1, time);
        return max(include, exclude);
    }
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        return solve(satisfaction, 0, 0);
    }
};
//************* memoization********
class Solution
{
public:
    int solve(vector<int> &satisfaction, int ind, int time, vector<vector<int>> &dp)
    {
        if (ind == satisfaction.size())
        {
            return 0;
        }
        if (dp[ind][time] != -1)
        {
            return dp[ind][time];
        }
        int include = satisfaction[ind] * (time + 1) + solve(satisfaction, ind + 1, time + 1, dp);
        int exclude = 0 + solve(satisfaction, ind + 1, time, dp);
        return dp[ind][time] = max(include, exclude);
    }
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(satisfaction, 0, 0, dp);
    }
};
//********** tabulation *********
class Solution
{
public:
    int solvetab(vector<int> &satisfaction)
    {
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int time = ind; time >= 0; time--)
            {
                int include = satisfaction[ind] * (time + 1) + dp[ind + 1][time + 1];
                int exclude = 0 + dp[ind + 1][time];
                dp[ind][time] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        return solvetab(satisfaction);
    }
};
//************ space optimization ******
class Solution
{
public:
    int solvetab2(vector<int> &satisfaction)
    {
        int n = satisfaction.size();
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int time = ind; time >= 0; time--)
            {
                int include = satisfaction[ind] * (time + 1) + next[time + 1];
                int exclude = 0 + next[time];
                curr[time] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        return solvetab2(satisfaction);
    }
};
//***********
int main()
{

    return 0;
}