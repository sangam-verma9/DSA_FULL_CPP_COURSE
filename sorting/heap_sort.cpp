#include <bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = i * 2;
    int right = i * 2 + 1;
    if (left <= n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right <= n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void heapsort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}
int main()
{
    return 0;
}