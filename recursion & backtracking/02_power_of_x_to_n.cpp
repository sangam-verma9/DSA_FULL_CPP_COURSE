// https://leetcode.com/problems/powx-n/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double binpow(double a, int b)
    {
        if (b == 0)
            return 1;
        double res = binpow(a, b / 2);
        if (b % 2)
            return res * res * a;
        else
            return res * res;
    }
    double myPow(double x, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        else if (n > 0)
        {
            return binpow(x, n);
        }
        else
        {
            return binpow(1 / x, n);
        }
    }
};
int main()
{

    return 0;
}