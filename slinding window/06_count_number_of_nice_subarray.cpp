// https://leetcode.com/problems/count-number-of-nice-subarrays/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int atmost(vector<int> nums, int k)
    {
        if (k < 0)
            return 0;
        int i = 0, j = 0;
        int cnt = 0;
        int ans = 0;
        while (j < nums.size())
        {
            if (nums[j] & 1)
                cnt++;
            while (cnt > k)
            {
                if (nums[i] & 1)
                    cnt--;
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};
int main(){

return 0;
}