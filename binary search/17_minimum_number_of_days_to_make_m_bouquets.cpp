// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossible(int mid, vector<int> &bloomDay, int m, int k, int n)
    {
        vector<bool> v(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= mid)
                v[i] = 1;
        }
        int temp = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 1)
            {
                temp++;
            }
            else
            {
                temp = 0;
            }
            if (temp == k)
            {
                temp = 0;
                cnt++;
            }
        }
        return cnt >= m;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        long long ab = m, ac = k;
        long long aa = ab * ac;
        if (aa > n)
            return -1;
        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1, mid = 0;
        while (s <= e)
        {
            mid = s + (e - s) / 2;
            if (isPossible(mid, bloomDay, m, k, n))
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