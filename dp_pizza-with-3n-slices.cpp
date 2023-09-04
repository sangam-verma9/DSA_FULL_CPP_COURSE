#include <bits/stdc++.h>
using namespace std;
//******** recusion **********
class Solution
{
public:
    int solve(int ind, int endind, vector<int> &slices, int n)
    {
        if (n == 0 || ind > endind)
        {
            return 0;
        }
        int take = slices[ind] + solve(ind + 2, endind, slices, n - 1);
        int nottake = 0 + solve(ind + 1, endind, slices, n);
        return max(take, nottake);
    }
    int maxSizeSlices(vector<int> &slices)
    {
        int k = slices.size();
        int case1 = solve(0, k - 2, slices, k / 3);
        int case2 = solve(1, k - 1, slices, k / 3);
        return max(case1, case2);
    }
};
//******** memoization *******
class Solution
{
public:
    int solve(int ind, int endind, vector<int> &slices, int n, vector<vector<int>> &dp)
    {
        if (n == 0 || ind > endind)
        {
            return 0;
        }
        if (dp[ind][n] != -1)
        {
            return dp[ind][n];
        }
        int take = slices[ind] + solve(ind + 2, endind, slices, n - 1, dp);
        int nottake = 0 + solve(ind + 1, endind, slices, n, dp);
        return dp[ind][n] = max(take, nottake);
    }
    int maxSizeSlices(vector<int> &slices)
    {
        int k = slices.size();
        vector<vector<int>> dp1(k, vector<int>(k / 3 + 1, -1));
        int case1 = solve(0, k - 2, slices, k / 3, dp1);
        vector<vector<int>> dp2(k, vector<int>(k / 3 + 1, -1));
        int case2 = solve(1, k - 1, slices, k / 3, dp2);
        return max(case1, case2);
    }
};
//***********
int main()
{

    return 0;
}