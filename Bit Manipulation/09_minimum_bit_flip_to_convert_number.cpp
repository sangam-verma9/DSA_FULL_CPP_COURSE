// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int cnt = 0;
        int t = start ^ goal;
        for (int i = 0; i < 31; i++)
        {
            if ((t & (1 << i)) > 0)
                cnt++;
        }
        return cnt;
    }
};
int main()
{

    return 0;
}