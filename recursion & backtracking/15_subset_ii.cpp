// https://leetcode.com/problems/subsets-ii/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(int ind, int n, vector<int> &arr, vector<int> t, set<vector<int>> &ans)
    {
        if (ind == n)
        {
            ans.insert(t);
            return;
        }
        solve(ind + 1, n, arr, t, ans);
        t.push_back(arr[ind]);
        solve(ind + 1, n, arr, t, ans);
        t.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        set<vector<int>> ans;
        vector<int> t;
        sort(nums.begin(), nums.end());
        solve(0, nums.size(), nums, t, ans);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};
int main()
{

    return 0;
}