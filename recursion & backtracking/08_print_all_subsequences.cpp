// https://leetcode.com/problems/subsets/
#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    void solve(vector<int> &nums, int index, int &size, vector<int> &s, vector<vector<int>> &ans)
    {
        if (index >= size)
        {
            ans.push_back(s);
            return;
        }
        solve(nums, index + 1, size, s, ans);
        s.push_back(nums[index]);
        solve(nums, index + 1, size, s, ans);
        s.pop_back();
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int size = nums.size();
        vector<vector<int>> ans;
        vector<int> s;
        int index = 0;
        solve(nums, index, size, s, ans);
        return ans;
    }
};
int main()
{

    return 0;
}