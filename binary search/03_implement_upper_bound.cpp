// https://www.codingninjas.com/studio/problems/implement-upper-bound_8165383
#include <bits/stdc++.h>
using namespace std;
int upperBound(vector<int> &arr, int x, int n)
{
    int s = 0, e = n - 1, ans = n;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (x < arr[mid])
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{

    return 0;
}