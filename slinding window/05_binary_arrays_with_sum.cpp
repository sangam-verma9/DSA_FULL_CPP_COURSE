// https://leetcode.com/problems/binary-subarrays-with-sum
#include<bits/stdc++.h>
using namespace std;
// *** method-1 (without slinding window) ***
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            ans += mp[sum - goal];
            mp[sum]++;
        }
        return ans;
    }
};
// *** second solution **
// https://www.youtube.com/watch?v=Pkqq6kv2E6k&ab_channel=CodingSamurai%27s
class Solution
{
public:
    int atmost(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0;
        int i = 0, j = 0;
        int ans = 0;
        while (j < nums.size())
        {
            goal -= nums[j];
            while (goal < 0)
            {
                goal += nums[i];
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return atmost(nums, goal) - atmost(nums, goal - 1);
    }
};
int main(){

return 0;
}
