// https://leetcode.com/problems/count-good-numbers/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long binpow(long long a, long long b, int &mod)
    {
        long long res = 1;
        while (b > 0)
        {
            if (b & 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res % mod;
    }
    int countGoodNumbers(long long n)
    {
        long long e = (n + 1) / 2;
        long long o = n - e;
        int mod = 1e9 + 7;
        long long ans = binpow(5, e, mod);
        long long ans1 = binpow(4, o, mod);
        return (ans * ans1) % mod;
    }
};
int main()
{

    return 0;
}