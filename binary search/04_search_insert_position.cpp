// https://www.codingninjas.com/studio/problems/algorithm-to-find-best-insert-position-in-sorted-array_839813
#include <bits/stdc++.h>
using namespace std;
int searchInsert(vector<int> &arr, int m)
{
    int s = 0, e = arr.size() - 1, ans = arr.size();
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (m <= arr[mid])
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