// https://leetcode.com/problems/reverse-pairs
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int ans = 0;
    void merge(vector<int> &arr, int s, int e)
    {
        int mid = (s + e) / 2;
        int len1 = mid - s + 1;
        int len2 = e - mid;
        int *first = new int[len1];
        int *second = new int[len2];

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
        // Count reverse pairs
        int index1 = 0, index2 = 0;
        for (index1 = 0; index1 < len1; index1++)
        {
            while (index2 < len2 && first[index1] > 2L * second[index2])
            {
                index2++;
            }
            ans += index2;
        }
        // merge to sorted array
        index1 = 0;
        index2 = 0;
        mainindex = s;
        while (index1 < len1 && index2 < len2)
        {
            if (first[index1] <= second[index2])
            {
                arr[mainindex++] = first[index1++];
            }
            else
            {
                // if(first[index1]>2*second[index2]) ans += (len1 - index1);
                arr[mainindex++] = second[index2++];
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
    void merge_sort(vector<int> &arr, int l, int r)
    {
        if (l >= r)
            return;
        int mid = l + (r - l) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        merge(arr, l, r);
    }
    int reversePairs(vector<int> &nums)
    {
        merge_sort(nums, 0, nums.size() - 1);
        return ans;
    }
};
int main()
{

    return 0;
}