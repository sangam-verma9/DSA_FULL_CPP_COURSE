#include <bits/stdc++.h>
using namespace std;
//**** normal recusive
#define MOD 1000000007
long long int countDerangements(int n)
{
    // Write your code here.
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
        return 1;
    long long int ans = ((n - 1) % MOD * ((countDerangements(n - 1) % MOD) + (countDerangements(n - 2) % MOD)));
    return ans;
}
//***** memozation
#define MOD 1000000007

long long int solve(int n, vector<long long int> &dp)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = ((n - 1) % MOD * ((solve(n - 1, dp) % MOD) + (solve(n - 2, dp) % MOD)));
    return dp[n];
}
long long int countDerangements(int n)
{
    // Write your code here.
    vector<long long int> dp(n + 1, -1);
    return solve(n, dp);
}
//****tabulation
#define MOD 1000000007
long long int countDerangements(int n)
{
    // Write your code here.
    vector<long long int> dp(n + 1, -1);
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        long long int first = dp[i - 1] % MOD;
        long long int second = dp[i - 2] % MOD;
        long long int ans = (first + second) % MOD;
        dp[i] = ((i - 1) * ans) % MOD;
    }
    return dp[n];
}
//**** space optimization
#define MOD 1000000007
long long int countDerangements(int n)
{
    // Write your code here.

    long long int prev2 = 0;
    long long int prev1 = 1;
    for (int i = 3; i <= n; i++)
    {
        long long int first = prev1 % MOD;
        long long int second = prev2 % MOD;
        long long int ans = (first + second) % MOD;
        long long int curr = ((i - 1) * ans) % MOD;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
//***

int main()
{

    return 0;
}