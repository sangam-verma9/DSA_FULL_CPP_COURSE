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