// https://www.geeksforgeeks.org/problems/prime-factors5052/1
#include <bits/stdc++.h>
using namespace std;
vector<int> sieve(int n)
{
    vector<int> a(n + 1, 1);
    a[0] = a[1] = 0;
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
class Solution
{
public:
    vector<int> AllPrimeFactors(int N)
    {
        // Code here
        vector<int> v = sieve(N);
        vector<int> ans;
        for (auto it : v)
        {
            if (N % it == 0)
                ans.push_back(it);
        }
        return ans;
    }
};
int main()
{

    return 0;
}