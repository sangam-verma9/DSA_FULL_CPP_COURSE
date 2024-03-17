#include <bits/stdc++.h>
using namespace std;
// Idea -- here we going to crete table for index & total sum as q of
// find target sum  so that we can find
// any value sum possible or not after then check it is possible or not to
// doing abs diff of( tar value and total sum value) on the last row which
//  store all values one more optimization possible is to can go half of
//  ind in last row beacause after that values starts reapeat again
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int tsum = 0;
    for (int i = 0; i < n; i++)
        tsum += arr[i];
    int k = tsum;

    //*** code of find target sum in array
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if (arr[0] <= k)
        dp[0][arr[0]] = 1; // ind 0 tar same as arr[0] then true

    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 1; tar <= k; tar++)
        {
            bool nottake = dp[ind - 1][tar];
            bool take = 0;
            if (tar >= arr[ind])
                take = dp[ind - 1][tar - arr[ind]];
            dp[ind][tar] = (nottake || take);
        }
    }

    //****

    int mindiff = INT_MAX;
    for (int i = 0; i <= k / 2; i++)
    {
        if (dp[n - 1][i] == true)
        {
            mindiff = min(mindiff, abs((k - i) - i));
        }
    }
    return mindiff;
}

// ***** space optimization *****
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int tsum = 0;
    for (int i = 0; i < n; i++)
        tsum += arr[i];
    int k = tsum;

    vector<bool> prev(k + 1, 0), curr(k + 1, 0);
    prev[0] = curr[0] = 1;

    if (arr[0] <= k)
        prev[arr[0]] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 1; tar <= k; tar++)
        {
            bool nottake = prev[tar];
            bool take = 0;
            if (tar >= arr[ind])
                take = prev[tar - arr[ind]];
            curr[tar] = (nottake || take);
        }
        prev = curr;
    }

    int mindiff = INT_MAX;
    for (int i = 0; i <= k / 2; i++)
    {
        if (prev[i] == true)
        {
            mindiff = min(mindiff, abs((k - i) - i));
        }
    }
    return mindiff;
}

int main()
{

    return 0;
}