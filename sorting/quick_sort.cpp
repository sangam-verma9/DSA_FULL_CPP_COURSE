#include <iostream>
using namespace std;
int pivote_element(int *arr, int s, int e)
{
    int pivote = s;
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] < arr[pivote])
        {
            count++;
        }
    }
    int index = s + count;
    swap(arr[index], arr[s]);
    int i = s, j = e;
    while (i < index && j > index)
    {
        while (arr[i] < arr[index])
        {
            i++;
        }
        while (arr[j] > arr[index])
        {
            j--;
        }
        if (i < index && j > index)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return index;
}
void quick_sort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = pivote_element(arr, s, e);
    quick_sort(arr, s, p - 1);
    quick_sort(arr, p + 1, e);
}
int main()
{
    int arr[] = {2, 34, 21, 45, 22, 5, 67, 87, 98};
    int n = sizeof(arr) / sizeof(int);
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}