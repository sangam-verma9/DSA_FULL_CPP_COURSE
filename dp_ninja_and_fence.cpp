#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
//********* rucursion approach *****
/* idea is we can print last two fence with same color or different color*/
// recursive function f(n)=(k-1)*f(n-2) + (k-1)*f(n-1)
int mul(int a, int b)
{
    return ((a % mod) * (b % mod)) % mod;
}
int sum(int a, int b)
{
    return ((a % mod) + (b % mod)) % mod;
}
int solve(int n, int k)
{
    if (n == 1)
        return k;
    if (n == 2)
        return sum(k, mul(k, k - 1));
    return sum(mul(k - 1, solve(n - 2, k)), mul(k - 1, solve(n - 1, k)));
}
int numberOfWays(int n, int k)
{
    // Write your code here.
    return solve(n, k);
}
//********** memoization solution **********
int mul(int a, int b)
{
    return ((a % mod) * 1LL * (b % mod)) % mod;
}
int sum(int a, int b)
{
    return ((a % mod) + (b % mod)) % mod;
}
int solvemem(int n, int k, vector<int> &dp)
{
    if (n == 1)
        return dp[1] = k;
    if (n == 2)
        return dp[2] = sum(k, mul(k, k - 1));
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = sum(mul(k - 1, solvemem(n - 2, k, dp)), mul(k - 1, solvemem(n - 1, k, dp)));
}
int numberOfWays(int n, int k)
{
    // Write your code here.
    vector<int> dp(n + 1, -1);
    return solvemem(n, k, dp);
}
//*********** tabulation method *****
int mul(int a, int b)
{
    return ((a % mod) * 1LL * (b % mod)) % mod;
}
int sum(int a, int b)
{
    return ((a % mod) + (b % mod)) % mod;
}

int numberOfWays(int n, int k)
{
    // Write your code here.
    vector<int> dp(n + 1, -1);
    dp[1] = k;
    dp[2] = sum(k, mul(k, k - 1));
    for (int i = 3; i <= n; i++)
    {
        dp[i] = sum(mul(k - 1, dp[i - 2]), mul(k - 1, dp[i - 1]));
    }
    return dp[n];
}
//********* space optimization ******
int numberOfWays(int n, int k)
{
    // Write your code here.
    int prev2 = k;
    int prev1 = sum(k, mul(k, k - 1));
    for (int i = 3; i <= n; i++)
    {
        int ans = sum(mul(k - 1, prev2), mul(k - 1, prev1));
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
//*******
int main()
{

    return 0;
}