// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool ispossible(int mid, vector<int> &weights, int days)
    {
        int temp = 0;
        int cnt = 1;
        for (int i = 0; i < weights.size(); i++)
        {
            if (weights[i] > mid)
                return false;
            temp += weights[i];
            if (temp > mid)
            {
                cnt++;
                temp = weights[i];
            }
        }
        return cnt <= days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int sum = 0;
        for (auto i : weights)
            sum += i;
        int s = 1, e = sum;
        int ans = -1, mid = 0;
        while (s <= e)
        {
            mid = s + (e - s) / 2;
            if (ispossible(mid, weights, days))
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
int main()
{

    return 0;
}