// https://leetcode.com/problems/longest-common-prefix
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int size = strs.size(), n = strs[0].length();
        for (int i = 1; i < size; i++)
        {
            int m = 0;
            while (m < n && strs[0][m] == strs[i][m])
            {
                m++;
            }
            n = min(n, m);
        }
        return strs[0].substr(0, n);
    }
};
int main()
{

    return 0;
}