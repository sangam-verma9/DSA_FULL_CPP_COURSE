// https://www.codingninjas.com/studio/problems/unique-element-in-sorted-array_1112654
#include <bits/stdc++.h>
using namespace std;
//**** first method *** (bit manipulation)
int singleNonDuplicate(vector<int> &arr)
{
    int ans = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}
//*** second method *** (binary search)
/* The idea here is to use binary search and move left and right using the below observation.

    1. If mid is even, and arr[mid] == arr[mid + 1], then size of subarray [0...mid-1] (left side) is even (since the every element occurs twice), so left side does not contain the single occurrence element. Hence we need to check in [mid + 1, ..., N] subarray (right side of mid). Else we need to search for the required element on the left side.
    Example:
    [1, 1, 2, 2, 3(mid), 3, 5, 7, 7]
    Here mid = 4.  Here subarray[0…3] doesn’t contain our unique number. So we need to check in the right side of the mid i.e. subarray [5… 8].
    2. If mid is odd, and arr[mid] == arr[mid - 1], then the size of subarray [0...mid - 2] (left side) is even (since every element occurs twice), so the left side does not contain the single occurrence element. Hence we need to check in subarray [mid + 1, ..., N] (right side of mid). Else we need to search for the required element on the left side.
    Example
    [1, 1, 2, 2, 3, 3(mid), 5, 7, 7]
    Here mid = 5.  Here subarray[0…3] doesn’t contain our unique number. So we need to check in the right side of mid i.e. subarray [6… 8].
*/
int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, high = n - 1, mid;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return arr[low];
}
int main()
{

    return 0;
}