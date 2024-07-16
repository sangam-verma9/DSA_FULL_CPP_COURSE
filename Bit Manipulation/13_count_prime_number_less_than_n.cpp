// https://leetcode.com/problems/count-primes
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> sieve(int n)
    {
        vector<int> a(n + 1, 1);
        a[0] = 0, a[1] = 0;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (a[i] == 1)
            {
                for (int j = i * 2; j <= n; j += i)
                    a[j] = 0;
            }
        }
        vector<int> ans;
        for (int i = 2; i <= n; i++)
            if (a[i] == 1)
                ans.push_back(i);
        return ans;
    }
    int countPrimes(int n)
    {
        if (n < 2)
            return 0;
        return sieve(n - 1).size();
    }
};
int main()
{

    return 0;
}