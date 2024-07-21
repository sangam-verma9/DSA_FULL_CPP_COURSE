// https://leetcode.com/problems/merge-intervals/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        vector<int> v;
        int n = intervals.size();
        if (n == 1)
        {
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        int p1 = intervals[0][0];
        int p2 = intervals[0][1];
        for (int i = 1; i < n; i++)
        {
            int p3 = intervals[i][0];
            if (p3 >= p1 && p3 <= p2)
            {
                p2 = max(p2, intervals[i][1]);
            }
            else
            {
                v.push_back(p1);
                v.push_back(p2);
                ans.push_back(v);
                v.clear();
                p1 = intervals[i][0];
                p2 = intervals[i][1];
            }
            if (i == n - 1)
            {
                v.push_back(p1);
                v.push_back(p2);
                ans.push_back(v);
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}