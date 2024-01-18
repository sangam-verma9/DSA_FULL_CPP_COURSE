// https://www.codingninjas.com/studio/problems/frog-jump_3621012?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include <bits/stdc++.h>
using namespace std;
//****** recursive approach *****
int countDistinctWays(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    return countDistinctWays(n - 1) + countDistinctWays(n - 2);
}
//**********
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
//**********
int main()
{

    return 0;
}