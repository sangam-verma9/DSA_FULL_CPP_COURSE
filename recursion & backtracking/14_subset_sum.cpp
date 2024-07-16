// https://www.geeksforgeeks.org/problems/subset-sums2234/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(int ind, int &n, vector<int> &arr, int sum, vector<int> &ans)
    {
        if (ind == n)
        {
            ans.push_back(sum);
            return;
        }
        solve(ind + 1, n, arr, sum, ans);
        solve(ind + 1, n, arr, sum + arr[ind], ans);
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> ans;
        solve(0, n, arr, 0, ans);
        return ans;
    }
};
int main()
{

    return 0;
}