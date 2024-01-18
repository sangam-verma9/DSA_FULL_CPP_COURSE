#include <bits/stdc++.h>
using namespace std;
// here idea is find dp1 from start to LIS then dp2 from last to LIS now
// ans is additioin of both is particular ind -1  which is maximum
int longestBitonicSubsequence(vector<int> &arr, int n)
{
    // for increasing
    vector<int> dp1(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] > arr[prev] && dp1[prev] + 1 > dp1[i])
            {
                dp1[i] = max(dp1[i], 1 + dp1[prev]);
            }
        }
    }
    // for decreasing
    vector<int> dp2(n, 1);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = n - 1; prev > i; prev--)
        {
            if (arr[i] > arr[prev] && dp2[prev] + 1 > dp2[i])
            {
                dp2[i] = max(dp2[i], 1 + dp2[prev]);
            }
        }
    }
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }
    return maxi;
}
int main()
{

    return 0;
}