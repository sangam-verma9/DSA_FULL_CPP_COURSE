// https://www.codingninjas.com/studio/problems/divisible-set_3754960
#include <bits/stdc++.h>
using namespace std;
// Idea is here sort the ele so that no need wory to increasing becuse
//  here q asks to return set so not need to sequentially we can return
//  any order, now going to count longest divisible subsequence by LIS
// method of another mathod discuss in dp42 to print we use hash method
//  to pront with backtrack
//*****
vector<int> divisibleSet(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> dp(n, 1), hash(n);
    int maxi = 0, lastind = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] % arr[prev] == 0 && dp[prev] + 1 > dp[i])
            {
                dp[i] = dp[prev] + 1;
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastind = i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastind]);
    while (hash[lastind] != lastind)
    {
        lastind = hash[lastind];
        temp.push_back(arr[lastind]);
    }
    reverse(temp.begin(), temp.end());
    return temp;
}
//****
int main()
{

    return 0;
}