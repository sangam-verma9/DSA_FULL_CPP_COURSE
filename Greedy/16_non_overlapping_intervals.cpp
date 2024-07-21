// https://leetcode.com/problems/non-overlapping-intervals/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        vector<pair<int, int>> v;
        for (auto i : intervals)
        {
            v.push_back({i[0], i[1]});
        }
        sort(v.begin(), v.end());
        int start = v[0].first;
        int end = v[0].second;
        int ans = 0;
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i].first >= end)
            {
                start = v[i].first;
                end = v[i].second;
            }
            else
            {
                ans++;
                end = min(end, v[i].second);
            }
        }
        return ans;
    }
};
int main(){

return 0;
}