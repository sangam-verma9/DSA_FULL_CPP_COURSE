#include <bits/stdc++.h>
using namespace std;

//******** recusive normal approach
int solve(int i, int nStairs)
{
    if (i == nStairs)
    {
        return 1;
    }
    if (i > nStairs)
        return 0;

    return solve(i + 1, nStairs) + solve(i + 2, nStairs);
}
int countDistinctWays(int nStairs)
{
    //  Write your code here.
    int ans = solve(0, nStairs);
    return ans;
}
//******** solve memeoization *******
#define M 1000000007
int solvemem(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return dp[0] = 1;
    }
    if (n == 1)
    {
        return dp[1] = 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = (solvemem(n - 1, dp) + solvemem(n - 2, dp)) % M;
}
int countDistinctWays(int n)
{
    //  Write your code here.
    vector<int> dp(n + 1, -1);
    return solvemem(n, dp);
}
//***************
int main()
{

    return 0;
}