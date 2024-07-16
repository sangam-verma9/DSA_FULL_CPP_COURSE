// https://leetcode.com/problems/combination-sum
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    void solve(int ind, vector<int> &candidates, int target, vector<int> &temp)
    {
        if (ind == candidates.size())
        {
            if (temp.size() > 0 && target == 0)
                ans.push_back(temp);
            return;
        }
        if (target >= candidates[ind])
        {
            temp.push_back(candidates[ind]);
            solve(ind, candidates, target - candidates[ind], temp);
            temp.pop_back();
            solve(ind + 1, candidates, target, temp);
        }
        else
        {
            solve(ind + 1, candidates, target, temp);
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        int n = candidates.size();
        vector<int> temp;
        solve(0, candidates, target, temp);
        return ans;
    }
};
int main(){

return 0;
}