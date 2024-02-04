#include<bits/stdc++.h>
using namespace std;
//**** recusion ****
class Solution
{
public:
    int solve(int ind, vector<int> &arr, int k, int maxi, int len)
    {
        if (ind == arr.size())
            return 0;
        maxi = max(maxi, arr[ind]);
        len = len + 1;
        int op1 = 0, op2 = 0;
        if (len == k)
        {
            op1 = len * maxi + solve(ind + 1, arr, k, 0, 0);
        }
        else
        {
            op2 = max(len * maxi + solve(ind + 1, arr, k, 0, 0), solve(ind + 1, arr, k, maxi, len));
        }
        return max(op1, op2);
    }
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        return solve(0, arr, k, 0, 0);
    }
};
//******* memoization ***
class Solution
{
public:
    vector<vector<int>> dp;
    int find(int index, int maxm, int len, vector<int> &arr, int k)
    {
        if (index == arr.size())
        {
            return len * maxm;
        }

        int part = 0, noPart = 0;
        maxm = max(maxm, arr[index]);
        len++;

        if (dp[index][len] != -1)
            return dp[index][len];

        if (len < k)
        {
            noPart = find(index + 1, maxm, len, arr, k);
        }
        part = len * maxm + find(index + 1, INT_MIN, 0, arr, k);

        return dp[index][len] = max(part, noPart);
    }
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {

        int n = arr.size();
        dp.resize(n + 1, vector<int>(k + 1, -1));

        return find(0, INT_MIN, 0, arr, k);
    }
};
//****** 

int main() {

return 0;
}