// https://www.geeksforgeeks.org/problems/convert-min-heap-to-max-heap-1666385109/1
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void heapify(vector<int> &arr, int n, int i)
    {
        int largest = i;
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest])
        {
            largest = right;
        }
        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int N)
    {
        for (int i = N - 1; i >= 0; i--)
            heapify(arr, N, i);
    }
};
int main(){

return 0;
}