#include <bits/stdc++.h>
using namespace std;
//****** optmized approach (using longest increasing subsequence dp approach )
class Solution
{
public:
    bool check(vector<int> &base, vector<int> &newbox)
    {
        if (base[0] >= newbox[0] && base[1] >= newbox[1] && base[2] >= newbox[2])
        {
            return true;
        }
        return false;
    }
    int solve(vector<vector<int>> &c)
    {
        int n = c.size();
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);
        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                if (prev == -1 || check(c[curr], c[prev]))
                {
                    include = c[curr][2] + nextRow[curr + 1]; // [curr][prev+1+1]
                }
                int exclude = nextRow[prev + 1];
                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (auto &a : cuboids)
        {
            sort(a.begin(), a.end());
        }
        sort(cuboids.begin(), cuboids.end());
        return solve(cuboids);
    }
};
//**************
int main()
{

    return 0;
}