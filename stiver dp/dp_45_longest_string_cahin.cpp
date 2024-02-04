// https://www.codingninjas.com/studio/problems/longest-string-chain_3752111
#include <bits/stdc++.h>
using namespace std;
// Here idea is only change instead of number in LIS ,here string so no
//  need wory of sequence so sort in increasing order by length and now check function
// to check only one char is diff/new add in string so in check function
//  we going to create two pointer then check if char match then move forword
// if not match increase first pointer which is of new string (badi) at last
//  if both pointer end same then is possible
bool check(string &s1, string &s2)
{
    if (s1.length() != s2.length() + 1)
    {
        return false;
    }
    int a = 0, b = 0;
    while (a < s1.length())
    {
        if (s1[a] == s2[b] && s2.length() > b)
        {
            a++, b++;
        }
        else
        {
            a++;
        }
    }
    if (s1.length() == a && s2.length() == b)
        return true;
    return false;
}
bool comp(string &s1, string &s2)
{
    return s1.length() < s2.length();
}
int longestStrChain(vector<string> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(), comp);
    vector<int> dp(n, 1);
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (check(arr[i], arr[prev]) && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
        }
    }
    return maxi;
}
int main()
{

    return 0;
}