// https://leetcode.com/problems/max-consecutive-ones-iii/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0, j = 0;
        int cnt = 0;
        while (j < n)
        {
            if (nums[j] == 1)
            {
                cnt = max(cnt, j - i + 1);
                j++;
            }
            else if (nums[j] == 0 && k > 0)
            {
                cnt = max(cnt, j - i + 1);
                k--;
                j++;
            }
            else
            {
                while (nums[i] != 0)
                {
                    i++;
                }
                k++;
                i++;
            }
        }
        return cnt;
    }
};
int main()
{

    return 0;
}