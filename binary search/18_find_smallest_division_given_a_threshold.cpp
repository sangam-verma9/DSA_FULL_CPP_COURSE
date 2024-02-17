// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool ispossible(int mid, vector<int> &nums, int threshold)
    {
        int temp = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            temp += (nums[i] % mid == 0 ? nums[i] / mid : nums[i] / mid + 1);
        }
        return temp <= threshold;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int s = 1;
        int e = *max_element(nums.begin(), nums.end());
        int mid = 0, ans = 0;
        while (s <= e)
        {
            mid = s + (e - s) / 2;
            if (ispossible(mid, nums, threshold))
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;
    }
};
int main(){

return 0;
}