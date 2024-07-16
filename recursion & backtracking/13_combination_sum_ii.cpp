// https://leetcode.com/problems/combination-sum-ii
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;

    void solve(int ind, vector<int> &candidates, int target, vector<int> &temp)
    {
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }
        for (int i = ind; i < candidates.size(); ++i)
        {
            if (i > ind && candidates[i] == candidates[i - 1]) // Skip duplicates
                continue;
            if (candidates[i] > target) // No need to continue if the current candidate is greater than the target
                break;
            temp.push_back(candidates[i]);
            solve(i + 1, candidates, target - candidates[i], temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end()); // Sort candidates to handle duplicates
        vector<int> temp;
        solve(0, candidates, target, temp);
        return ans;
    }
};
int main()
{

    return 0;
}