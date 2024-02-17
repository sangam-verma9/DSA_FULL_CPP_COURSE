// https://leetcode.com/problems/find-peak-element/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        int s = 0, e = n - 1;
        int mid = (s + e) / 2;
        int ans = -1;
        while (s <= e)
        {
            if (mid > 0 && mid < n - 1)
            {
                if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                {
                    return mid;
                }
                else if (nums[mid] > nums[mid - 1])
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
            else if (mid == 0)
            {
                if (nums[mid] > nums[mid + 1])
                    return mid;
                else
                    s = mid + 1;
            }
            else if (mid == n - 1)
            {
                if (nums[mid] > nums[mid - 1])
                    return mid;
                else
                    e = mid - 1;
            }
            mid = (s + e) / 2;
        }
        return ans;
    }
};
int main()
{

    return 0;
}