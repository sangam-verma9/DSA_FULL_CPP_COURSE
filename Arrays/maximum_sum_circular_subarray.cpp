// https://leetcode.com/problems/maximum-sum-circular-subarray/
#include <bits/stdc++.h>
using namespace std;
/*
Case 1. The first is that the subarray take only a middle part, and we know how to find the max subarray sum.
Case2. The second is that the subarray take a part of head array and a part of tail array.
We can transfer this case to the first one.
The maximum result equals to the total sum minus the minimum subarray sum.

*/
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int total = 0, maxSum = A[0], curMax = 0, minSum = A[0], curMin = 0;
        for (int &a : A)
        {
            curMax = max(curMax + a, a);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + a, a);
            minSum = min(minSum, curMin);
            total += a;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};
int main()
{

    return 0;
}