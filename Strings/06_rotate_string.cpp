// https://leetcode.com/problems/rotate-string/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            int t = 0;
            for (int j = 0; j < n; j++)
            {
                if (goal[j] == s[(j + i) % n])
                    t++;
            }
            if (t == n)
                return true;
        }
        return false;
    }
};
int main()
{

    return 0;
}