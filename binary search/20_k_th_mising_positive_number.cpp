// https://leetcode.com/problems/kth-missing-positive-number/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int s = 0, e = n - 1;
        int mid = 0;
        while (s <= e)
        {
            mid = s + (e - s) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return e + k + 1;
    }
};
int main()
{

    return 0;
}