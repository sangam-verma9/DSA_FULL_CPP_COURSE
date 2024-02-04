#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        long long sum = 0;
        int i = 0, j = 0;
        long long wsum = 0;
        unordered_map<int, int> mp;
        while (j <= nums.size())
        {
            while (j - i + 1 <= k)
            {
                wsum += nums[j];
                mp[nums[j]]++;
                j++;
            }
            if (mp.size() == k)
            {
                sum = max(sum, wsum);
            }
            if (mp[nums[i]] == 1)
                mp.erase(nums[i]);
            else
                mp[nums[i]]--;
            wsum -= nums[i];
            if (j < nums.size())
            {
                wsum += nums[j];
                mp[nums[j]]++;
            }
            i++, j++;
        }
        return sum;
    }
};
int main() {

return 0;
}