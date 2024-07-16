// https://leetcode.com/problems/largest-odd-number-in-string/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string largestOddNumber(string num)
    {
        int n = num.size();
        int i;
        for (i = n - 1; i >= 0; i--)
        {
            if ((num[i] - '0') & 1)
            {
                break;
            }
        }
        if (i >= 0)
        {
            return num.substr(0, i + 1);
        }
        return "";
    }
};
int main()
{

    return 0;
}