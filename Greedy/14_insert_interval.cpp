// https://leetcode.com/problems/insert-interval/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int first = intervals[0][0];
        int second = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (second < intervals[i][0])
            {
                ans.push_back({first, second});
                first = intervals[i][0];
                second = intervals[i][1];
            }
            else
            {
                second = max(second, intervals[i][1]);
            }
        }
        ans.push_back({first, second});
        return ans;
    }
};
int main()
{

    return 0;
}