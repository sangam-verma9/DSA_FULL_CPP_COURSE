// https://leetcode.com/problems/subarrays-with-k-different-integers/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int atmost(vector<int> &nums, int k)
    {
        int ans = 0;
        int i = 0, j = 0;
        unordered_map<int, int> mp;
        while (j < nums.size())
        {
            mp[nums[j]]++;
            if (mp.size() > k)
            {
                while (mp.size() > k)
                {
                    mp[nums[i]]--;
                    if (mp[nums[i]] == 0)
                        mp.erase(nums[i]);
                    i++;
                }
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int ans1 = atmost(nums, k);
        int ans2 = 0;
        if (k > 1)
            ans2 = atmost(nums, k - 1);
        return ans1 - ans2;
    }
};
int main(){

return 0;
}