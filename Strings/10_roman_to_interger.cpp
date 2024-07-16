// https://leetcode.com/problems/roman-to-integer
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int romanToInt(string s)
    {
        int c = 0;
        int d = s.length();
        for (int i = 0; i < d; i++)
        {
            if (s[i] == 'I')
                c += 1;
            else if (s[i] == 'V')
                c += 5;
            else if (s[i] == 'X')
                c += 10;
            else if (s[i] == 'L')
                c += 50;
            else if (s[i] == 'C')
                c += 100;
            else if (s[i] == 'D')
                c += 500;
            else if (s[i] == 'M')
                c += 1000;
        }
        for (int i = 0; i < d - 1; i++)
        {
            if ((s[i] == 'I' && s[i + 1] == 'V') || (s[i] == 'I' && s[i + 1] == 'X'))
            {
                c -= 2;
            }
            else if ((s[i] == 'X' && s[i + 1] == 'L') || (s[i] == 'X' && s[i + 1] == 'C'))
            {
                c -= 20;
            }
            else if ((s[i] == 'C' && s[i + 1] == 'D') || (s[i] == 'C' && s[i + 1] == 'M'))
            {
                c -= 200;
            }
        }
        return c;
    }
};
int main()
{

    return 0;
}