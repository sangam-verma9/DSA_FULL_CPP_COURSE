#include <bits/stdc++.h>
using namespace std;
//***** recursion ******* (codestudio q)
int solve(int ind, vector<int> &days, vector<int> &cost, int n)
{
    if (ind >= n)
    {
        return 0;
    }
    int i = ind;
    int option1 = cost[0] + solve(i + 1, days, cost, n);

    for (i = ind; i < n && days[i] < days[ind] + 7; i++)
        ;

    int option2 = cost[1] + solve(i, days, cost, n);

    for (i = ind; i < n && days[i] < days[ind] + 30; i++)
        ;

    int option3 = cost[2] + solve(i, days, cost, n);

    return min(option1, min(option2, option3));
}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{

    return solve(0, days, cost, n);
}
//****** memoization ********
int solvemem(int ind, vector<int> &days, vector<int> &cost, int n, vector<int> &dp)
{
    if (ind >= n)
    {
        return 0;
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    int i = ind;
    int option1 = cost[0] + solvemem(i + 1, days, cost, n, dp);

    for (i = ind; i < n && days[i] < days[ind] + 7; i++)
        ;

    int option2 = cost[1] + solvemem(i, days, cost, n, dp);

    for (i = ind; i < n && days[i] < days[ind] + 30; i++)
        ;

    int option3 = cost[2] + solvemem(i, days, cost, n, dp);

    return dp[ind] = min(option1, min(option2, option3));
}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n, -1);
    return solvemem(0, days, cost, n, dp);
}
//******** tabulation *******
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n + 1, -1);
    dp[n] = 0;
    for (int k = n - 1; k >= 0; k--)
    {
        int i = k;
        int option1 = cost[0] + dp[i + 1];

        for (i = k; i < n && days[i] < days[k] + 7; i++)
            ;

        int option2 = cost[1] + dp[i];

        for (i = k; i < n && days[i] < days[k] + 30; i++)
            ;

        int option3 = cost[2] + dp[i];
        dp[k] = min(option1, min(option2, option3));
    }
    return dp[0];
}
//**********
int main()
{

    return 0;
}