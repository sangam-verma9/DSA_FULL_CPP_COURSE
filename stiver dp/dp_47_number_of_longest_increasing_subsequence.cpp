#include <bits/stdc++.h>
using namespace std;
// Here idea is going to create a cnt array to count no of possible
// subsequences if there are dp[prev]+1==dp[i] that means there a another
// way so we add cnt[i]+=cnt[prev] if not dp[prev]+1>dp[i] that means
// there is we new subsequence of new greater length
int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1), cnt(n, 1);
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && dp[prev] + 1 > dp[i])
            {
                dp[i] = 1 + dp[prev];
                cnt[i] = cnt[prev];
            }
            else if (arr[prev] < arr[i] && dp[prev] + 1 == dp[i])
            {
                cnt[i] += cnt[prev];
            }
        }
        maxi = max(maxi, dp[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
            ans += cnt[i];
    }
    return ans;
}
int main()
{

    return 0;
}