// https://www.codingninjas.com/studio/problems/ceiling-in-a-sorted-array_1825401
#include <bits/stdc++.h>
using namespace std;
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    int s = 0, e = n - 1, f = -1, c = -1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (x <= a[mid])
        {
            c = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    s = 0, e = n - 1;
    mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (x >= a[mid])
        {
            f = mid;
            s = mid + 1;
        }
        else if (x < a[mid])
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    int aa, bb;
    if (f != -1)
        aa = a[f];
    else
        aa = -1;
    if (c != -1)
        bb = a[c];
    else
        bb = -1;
    return {aa, bb};
}

int main()
{

    return 0;
}