// https://leetcode.com/problems/jump-game-ii/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = size(nums), i = 0, maxReachable = 0, lastJumpedPos = 0, jumps = 0;
        while (lastJumpedPos < n - 1)
        {
            maxReachable = max(maxReachable, i + nums[i]);
            if (i == lastJumpedPos)
            {
                lastJumpedPos = maxReachable;
                jumps++;
            }
            i++;
        }
        return jumps;
    }
};

// striver solution
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int jump = 0;
        int l = 0, r = 0;
        while (r < nums.size() - 1)
        {
            int largest = 0;
            for (int i = l; i <= r; i++)
            {
                largest = max(largest, i + nums[i]);
            }
            l = r + 1;
            r = largest;
            jump++;
        }
        return jump;
    }
};
int main()
{

    return 0;
}