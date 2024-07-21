// https://leetcode.com/problems/lemonade-change/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0;
        for (auto i : bills)
        {
            if (i == 5)
                five++;
            else if (i == 10)
            {
                if (five >= 1)
                {
                    five--, ten++;
                }
                else
                    return false;
            }
            else
            {
                if (five >= 1 && ten >= 1)
                {
                    five--, ten--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
int main()
{

    return 0;
}