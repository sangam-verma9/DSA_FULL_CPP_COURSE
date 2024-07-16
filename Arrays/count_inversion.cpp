// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long ans = 0;
    void merge(long long arr[], int s, int e)
    {
        long long mid = (s + e) / 2;
        int len1 = mid - s + 1;
        int len2 = e - mid;
        long long *first = new long long[len1];
        long long *second = new long long[len2];

        // copy values
        int mainindex = s;
        for (int i = 0; i < len1; i++)
        {
            first[i] = arr[mainindex++];
        }

        // mainindex = mid + 1;
        for (int i = 0; i < len2; i++)
        {
            second[i] = arr[mainindex++];
        }

        // merge to sorted array
        int index1 = 0;
        int index2 = 0;
        mainindex = s;
        while (index1 < len1 && index2 < len2)
        {
            if (first[index1] <= second[index2])
            {
                arr[mainindex++] = first[index1++];
            }
            else
            {
                arr[mainindex++] = second[index2++];
                ans += (len1 - index1);
            }
        }

        while (index1 < len1)
        {
            arr[mainindex++] = first[index1++];
        }
        while (index2 < len2)
        {
            arr[mainindex++] = second[index2++];
        }

        delete[] first;
        delete[] second;
    }
    void merge_sort(long long arr[], int l, int r)
    {
        if (l >= r)
            return;
        long long mid = l + (r - l) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        merge(arr, l, r);
    }
    long long int inversionCount(long long arr[], int n)
    {
        merge_sort(arr, 0, n - 1);
        return ans;
    }
};
int main()
{

    return 0;
}