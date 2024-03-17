// https://www.codingninjas.com/studio/problems/frog-jump_3621012?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h>
using namespace std;
//*********my approcah**********
// here we assume 1 base indexing
int solve(int n, vector<int> &heights, vector<int> &dp)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return abs(heights[1] - heights[0]);
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int op1 = abs(heights[n - 1] - heights[n - 2]) + solve(n - 1, heights, dp);
    int op2 = abs(heights[n - 3] - heights[n - 1]) + solve(n - 2, heights, dp);
    return dp[n] = min(op1, op2);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    int ans = solve(n, heights, dp);
    return ans;
}
// *********striver code***********
// assume as 0 base indexing then we going to solve
int solve(int n, vector<int> &heights, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int op2 = INT_MAX;
    int op1 = abs(heights[n] - heights[n - 1]) + solve(n - 1, heights, dp);
    if (n > 1)
    {
        op2 = abs(heights[n - 2] - heights[n]) + solve(n - 2, heights, dp);
    }
    return dp[n] = min(op1, op2);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    int ans = solve(n - 1, heights, dp);
    return ans;
}
//*******
//******* tabulation method *********
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int op2 = INT_MAX;
        int op1 = abs(heights[i] - heights[i - 1]) + dp[i - 1];
        if (i > 1)
        {
            op2 = abs(heights[i - 2] - heights[i]) + dp[i - 2];
        }
        dp[i] = min(op1, op2);
    }
    return dp[n - 1];
}
//*********
//****** space optimization ******
int frogJump(int n, vector<int> &heights)
{
    int prev1 = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int op2 = INT_MAX;
        int op1 = abs(heights[i] - heights[i - 1]) + prev1;
        if (i > 1)
        {
            op2 = abs(heights[i - 2] - heights[i]) + prev2;
        }
        int curr = min(op1, op2);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
//********
int main()
{

    return 0;
}