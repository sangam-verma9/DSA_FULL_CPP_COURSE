#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> nums, int index, vector<vector<int>> &ans)
{
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        solve(nums, index + 1, ans);
        // backtrack
        swap(nums[index], nums[i]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    int index = 0;
    vector<vector<int>> ans;
    solve(nums, index, ans);
    return ans;
}
int main() {

return 0;
}