// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool search(vector<int> &arr, int target)
    {
        int s = 0, e = arr.size() - 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (arr[mid] == target)
            {
                return true;
            }
            else if (arr[mid] == arr[s] && arr[mid] == arr[e])
            {
                s = s + 1;
                e = e - 1;
                continue;
            }
            else if (arr[mid] >= arr[s])
            {
                if (arr[s] <= target && arr[mid] >= target)
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            else
            {
                if (arr[mid] <= target && arr[e] >= target)
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
        }
        return false;
    }
};
int main()
{

    return 0;
}