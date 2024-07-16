// https://leetcode.com/problems/combination-sum-iii
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    void solve(int ind, int len, int target, vector<int> &temp)
    {
        if (ind == 10)
        {
            if (temp.size() == len && target == 0)
                ans.push_back(temp);
            return;
        }
        if (target >= ind)
        {
            temp.push_back(ind);
            solve(ind + 1, len, target - ind, temp);
            temp.pop_back();
            solve(ind + 1, len, target, temp);
        }
        else
        {
            solve(ind + 1, len, target, temp);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> temp;
        solve(1, k, n, temp);
        return ans;
    }
};
int main()
{

    return 0;
}