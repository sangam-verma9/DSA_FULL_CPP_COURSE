// https://www.codingninjas.com/studio/problems/ninja%E2%80%99s-training_3621003?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include <bits/stdc++.h>
using namespace std;
// In this ques we declare last to 3 means no task done yet and call recursion to
// solve solve(day,points,last,dp) means tell me max points ninja can get which
// already has done task last
//**** memoization *******
int solve(int day, vector<vector<int>> &points, int last, vector<vector<int>> &dp)
{
    if (day < 0)
    {
        return 0;
    }
    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int point = points[day][i] + solve(day - 1, points, i, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    int last = 3;
    vector<vector<int>> dp(n + 1, vector<int>(4, -1));
    int ans = solve(n - 1, points, last, dp);
    return ans;
}
//********* tabulation ******
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n + 1, vector<int>(4, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    // dp[0][3]=max(points[0][1],max(points[0][1],points[0][2]));
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            // dp[day][last]=0;
            for (int i = 0; i < 3; i++)
            {
                if (i != last)
                {
                    int point = points[day][i] + dp[day - 1][i];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[n - 1][3];
}
//****** space optimization ****
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    // prev[3]=max(points[0][1],max(points[0][1],points[0][2]));
    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            for (int i = 0; i < 3; i++)
            {
                if (i != last)
                {
                    int point = points[day][i] + prev[i];
                    temp[last] = max(temp[last], point);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}
//*******
int main()
{

    return 0;
}