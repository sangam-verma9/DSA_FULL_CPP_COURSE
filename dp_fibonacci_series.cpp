#include <bits/stdc++.h>
using namespace std;

//********
// normal recursion
int fibb(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibb(n - 1) + fibb(n - 2);
}
//********
// memoization
int fibbmemoization(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = fibbmemoization(n - 1, dp) + fibbmemoization(n - 2, dp);
    return dp[n];
}
//*********

int main()
{
    int n;
    cin >> n;
    //**normal recusion***
    // cout << fibb(n);
    // memoization dp
    /* vector<int> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    cout << fibbmemoization(n, dp);*/

    //**** tabulation method to create 1D array
    /*
    int arr[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    cout << arr[n]
    */

    //**** space optimization
    int prev1 = 0;
    int prev2 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    cout << prev2;
    return 0;
}