// https://www.codingninjas.com/studio/problems/nth-root-of-m_1062679
#include <bits/stdc++.h>
using namespace std;
int NthRoot(int n, int m)
{
    int s = 0, e = m;
    int ans = 0;
    long long mid = 0;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (pow(mid, n) <= m)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    if (pow(ans, n) != m)
        return -1;
    return ans;
}
int main()
{

    return 0;
}