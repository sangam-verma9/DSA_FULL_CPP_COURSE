// https://www.codingninjas.com/studio/problems/subarray-sums-i_1467103
#include<bits/stdc++.h>
using namespace std;
int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    map<long long, bool> mp;
    mp[0] = 1;
    long long sum = 0;
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (mp.find(sum - k) != mp.end())
        {
            cnt++;
        }
        mp[sum] = 1;
    }
    return cnt;
}
int main() {

return 0;
}