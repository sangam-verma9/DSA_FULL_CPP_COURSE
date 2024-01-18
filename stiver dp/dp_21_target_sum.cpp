#include <bits/stdc++.h>
using namespace std;
//**** recursive solution **** (copyed from codestudio)
int getNumOfWays(vector<int> &arr, int target, int index)
{
    // Base Cases.
    if (index >= arr.size())
    {
        if (target == 0)
        {
            return 1;
        }
        return 0;
    }

    // Explore both possibilities.
    int ans1 = getNumOfWays(arr, target - arr[index], index + 1);
    int ans2 = getNumOfWays(arr, target + arr[index], index + 1);

    return (ans1 + ans2);
}

int targetSum(int n, int target, vector<int> &arr)
{
    return getNumOfWays(arr, target, 0);
}

//****** memoization *****
getNumOfWays(vector<int> &arr, int target, int index,
             vector<unordered_map<int, int>> &cache)
{
    // Base Cases.
    if (index >= arr.size())
    {
        if (target == 0)
        {
            return 1;
        }
        return 0;
    }

    // If the value exists in the cache return it.
    if (cache[index].find(target) != cache[index].end())
    {
        return cache[index][target];
    }

    // Explore both possibilities.
    int ans1 = getNumOfWays(arr, target - arr[index], index + 1, cache);
    int ans2 = getNumOfWays(arr, target + arr[index], index + 1, cache);

    // Take the sum of both possibilities, and store it.
    cache[index][target] = (ans1 + ans2);

    return (ans1 + ans2);
}

int targetSum(int n, int target, vector<int> &arr)
{

    // Making the vector to store results of recursive calls.
    vector<unordered_map<int, int>> cache(arr.size());

    // Return the number of ways.
    return getNumOfWays(arr, target, 0, cache);
}

//**********

// here we have to find target sum of an arr appling some + or - in front of ele and take all ele
// so idea changed we have to divide in two subset which have diff target , this problem alredy implemented

int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    if (arr[0] != 0 && arr[0] <= k)
        dp[0][arr[0]] = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 0; tar <= k; tar++)
        {
            int notT = dp[ind - 1][tar];
            int take = 0;
            if (tar >= arr[ind])
                take = dp[ind - 1][tar - arr[ind]];
            dp[ind][tar] = (take + notT);
        }
    }
    return dp[n - 1][k];
}
int countPartitions(int n, int d, vector<int> &arr)
{
    int tsum = 0;
    for (int i = 0; i < n; i++)
    {
        tsum += arr[i];
    }
    if (tsum - d < 0 || (tsum - d) % 2 != 0)
        return 0;
    return findWays(arr, (tsum - d) / 2);
}
int targetSum(int n, int target, vector<int> &arr)
{
    // Write your code here.
    return countPartitions(n, target, arr);
}
int main()
{

    return 0;
}