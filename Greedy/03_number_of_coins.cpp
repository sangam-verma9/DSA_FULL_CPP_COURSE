// https://www.geeksforgeeks.org/problems/number-of-coins1824/1
#include <bits/stdc++.h>
using namespace std;

// Note this ques can be sloved by greedy algorithm but when denominations 
//are like {1,2,5,10,20,50,100,...} as you see real like denominations then use greedy algorithm
int solve(int ind, int tar, vector<int> &coins, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (tar % coins[ind] == 0)
            return tar / coins[ind];
        else
            return 1e9;
    }
    if (dp[ind][tar] != -1)
        return dp[ind][tar];
    int notTake = 0 + solve(ind - 1, tar, coins, dp);
    int take = 1e9;
    if (coins[ind] <= tar)
    {
        take = 1 + solve(ind, tar - coins[ind], coins, dp);
    }
    return dp[ind][tar] = min(take, notTake);
}
int minCoins(vector<int> &coins, int M, int V)
{
    vector<vector<int>> dp(M, vector<int>(V + 1, -1));
    if (solve(M - 1, V, coins, dp) >= 1e9)
    {
        return -1;
    }
    return solve(M - 1, V, coins, dp);
}
int main()
{

    return 0;
}