// https://www.codingninjas.com/studio/problems/lower-bound_8165382
#include <bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> arr, int n, int x)
{
    int s = 0, e = n - 1, ans = n;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (x <= arr[mid])
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