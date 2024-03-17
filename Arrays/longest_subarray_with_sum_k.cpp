// https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399
#include<bits/stdc++.h>
using namespace std;
// brute is simle run in two for loop going to all subarray and check
// *** better sol ***** (this is optimized if negative number in array) 
int longestSubarrayWithSumK(vector<int> a, long long k)
{
    map<long long, int> mp; // val,ind
    int len = 0;
    mp[0] = -1; // prev sum and ind initilize
    long long sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
        if (mp.find(sum - k) != mp.end())
        {
            int l = i - mp[sum - k];
            len = max(len, l);
        }
        if (mp.find(sum) == mp.end())   // case - [2,0,0,3] k=3  handilng
            mp[sum] = i;
    }
    return len;
}

// *** optimal ****  (two pointer approach)
int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int n = a.size();
    int left = 0, right = 0;
    long long sum = a[0];
    int len = 0;
    while (right < n)
    {
        while (sum > k && left <= right)
        {
            sum -= a[left];
            left++;
        }
        if (sum == k)
        {
            len = max(len, right - left + 1);
        }
        right++;
        if (right < n)
            sum += a[right];
    }
    return len;
}
int main() {

return 0;
}