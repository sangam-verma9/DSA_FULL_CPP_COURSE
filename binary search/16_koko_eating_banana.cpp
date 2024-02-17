// https://leetcode.com/problems/koko-eating-bananas/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool ispossible(long long mid, int h, vector<int> &piles)
    {
        int cnt = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            if (piles[i] <= mid)
                cnt++;
            else
                cnt += (piles[i] % mid == 0 ? piles[i] / mid : piles[i] / mid + 1);
        }
        return cnt <= h;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        long long sum = 0;
        for (auto i : piles)
        {
            sum += i;
        }
        long long s = 1, e = sum;
        long long ans = 0, mid = 0;
        while (s <= e)
        {
            mid = s + (e - s) / 2;
            if (ispossible(mid, h, piles))
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