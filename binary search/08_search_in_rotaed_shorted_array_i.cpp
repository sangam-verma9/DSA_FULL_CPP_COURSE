// https://leetcode.com/problems/search-in-rotated-sorted-array
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int binarysearch(vector<int> &nums, int s, int e, int target)
    {
        int mid = (s + e) / 2;
        while (s <= e)
        {
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
            mid = (s + e) / 2;
        }
        return -1;
    }
    int findpivote(vector<int> &nums, int s, int e)
    {
        int end = e;
        int mid = (s + e) / 2;
        while (s <= e)
        {
            if (nums[mid] > nums[end])
            {
                s = mid + 1;
            }
            else if (nums[mid] <= nums[end])
            {
                e = mid - 1;
            }
            mid = (s + e) / 2;
        }
        return s;
    }
    int search(vector<int> &nums, int target)
    {
        int e = nums.size();
        int p = findpivote(nums, 0, e - 1);
        int ans = -1;
        cout << p << endl;
        if (target > nums[e - 1])
        {
            ans = binarysearch(nums, 0, p - 1, target);
        }
        else
        {
            ans = binarysearch(nums, p, e - 1, target);
        }
        return ans;
    }
};
int main(){

return 0;
}