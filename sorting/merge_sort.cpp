#include <iostream>
using namespace std;
void merge(int *arr, int s, int e)
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

    //mainindex = mid + 1;
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
        if (first[index1] < second[index2])
        {
            arr[mainindex++] = first[index1++];
        }
        else
        {
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

    delete [] first;
    delete [] second;

}

void merge_sort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;
    merge_sort(arr, s, mid);

    merge_sort(arr, mid + 1, e);

    // merge
    merge(arr, s, e);
}
int main()
{
    int arr[] = {2, 34, 21, 45, 22, 5, 67, 87, 98};
    int n = sizeof(arr) / sizeof(int);
    merge_sort(arr, 0, n - 1);
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

class Solution
{
public:
    long long int merge(long long arr[], int low, int mid, int high)
    {
        vector<long long int> temp; // temporary array
        int left = low;             // starting index of left half of arr
        int right = mid + 1;        // starting index of right half of arr

        // Modification 1: cnt variable to count the pairs:
        long long int cnt = 0;

        // storing elements in the temporary array in a sorted manner//

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                cnt += (mid - left + 1); // Modification 2
                right++;
            }
        }

        // if elements on the left half are still left //

        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        //  if elements on the right half are still left //
        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }

        return cnt; // Modification 3
    }

    long long int mergeSort(long long arr[], int low, int high)
    {
        long long int cnt = 0;
        if (low >= high)
            return cnt;
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);      // left half
        cnt += mergeSort(arr, mid + 1, high); // right half
        cnt += merge(arr, low, mid, high);    // merging sorted halves
        return cnt;
    }

    long long int inversionCount(long long arr[], int n)
    {
        return mergeSort(arr, 0, n - 1);
    }
};