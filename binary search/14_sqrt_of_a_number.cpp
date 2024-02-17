// https://www.codingninjas.com/studio/problems/square-root-integral_893351
#include <bits/stdc++.h>
using namespace std;
int floorSqrt(int n)
{
    int s = 0, e = n;
    int ans = 0;
    long long mid = 0;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (mid * mid <= n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{

    return 0;
}