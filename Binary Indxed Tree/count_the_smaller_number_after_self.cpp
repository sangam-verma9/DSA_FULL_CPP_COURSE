// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n = 20001;
    vector<int> tr;

    int lowerbit(int x)
    {
        return x & -x;
    }

    int query(int x)
    {
        int res = 0;
        for (int i = x; i; i -= lowerbit(i))
            res += tr[i];
        return res;
    }

    void add(int idx, int val)
    {
        for (int i = idx; i <= n; i += lowerbit(i))
            tr[i] += val;
    }

    vector<int> countSmaller(vector<int> &nums)
    {
        tr.resize(n + 1);
        vector<int> res(nums.size(), 0);

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int x = nums[i] + 10001; // move to 1 based
            res[i] = query(x - 1);
            add(x, 1);
        }

        return res;
    }
};
int main()
{

    return 0;
}