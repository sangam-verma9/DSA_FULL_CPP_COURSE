// heap is data structure which is complete binary tree and comes with a specific property of heap
// maxheap - each ele of heap is greater than his child node
// minheap - each node's value is less than his child node's value
#include <bits/stdc++.h>
using namespace std;
class heap
{
public:
    int arr[100];
    int size = 0;
    heap()
    {
        arr[0] = -1;
    }
    void insert(int val)
    {
        size = size + 1;
        arr[size] = val;
        int index = size;
        while (index > 1)
        {
            if (arr[index] > arr[index / 2])
            {
                swap(arr[index], arr[index / 2]);
                index = index / 2;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    // delete first node
    void deleteforheap()
    {
        if (size == 0)
        {
            return;
        }
        int i = 1;
        arr[1] = arr[size];
        size--;

        while (i < size)
        {
            int leftindex = i * 2;
            int rightindex = i * 2 + 1;
            if (leftindex < size && arr[i] < arr[leftindex])
            {
                swap(arr[i], arr[leftindex]);
                i = leftindex;
            }
            else if (rightindex < size && arr[i] < arr[rightindex])
            {
                swap(arr[i], arr[rightindex]);
                i = rightindex;
            }
            else
            {
                return;
            }
        }
    }
};
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
    heap h;
    h.insert(50);
    h.insert(40);
    h.insert(46);
    h.insert(55);
    h.insert(60);
    h.insert(67);
    h.insert(45);
    h.print();
    h.deleteforheap();
    h.print();

    // int arr[7]={-1,5,1,1,2,0,0};
    // int n=6;
    // for(int i=n/2;i>0;i--){
    //     cout<<i<<" ";
    //     heapify(arr,n,i);
    // }
    // cout<<"printing the array"<<endl;
    // for(int i=1;i<=n; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // heapsort(arr,n);
    // cout<<"printing after sorting"<<endl;
    // for(int i=1;i<=n; i++){
    //     cout<<arr[i]<<" ";
    // }

    return 0;
}