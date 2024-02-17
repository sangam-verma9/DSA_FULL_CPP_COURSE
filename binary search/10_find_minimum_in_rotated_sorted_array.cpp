// https://www.codingninjas.com/studio/problems/rotated-array_1093219
#include <bits/stdc++.h>
using namespace std;
int findMin(vector<int> &arr)
{
    int s = 0, e = arr.size() - 1;
    int end = arr.size() - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] > arr[end])
        {
            s = mid + 1;
        }
        else
        {
            ans = mid;
            e = mid - 1;
        }
    }
    return arr[ans];
}
int main()
{

    return 0;
}