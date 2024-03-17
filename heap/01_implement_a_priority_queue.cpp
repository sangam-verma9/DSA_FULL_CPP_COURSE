// https://www.codingninjas.com/studio/problems/implement-a-priority-queue-_1743878
#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int> &heap, int i, int n)
{
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    if (left < n && heap[left] > heap[largest])
    {
        largest = left;
    }
    if (right < n && heap[right] > heap[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(heap[largest], heap[i]);
        heapify(heap, largest, n);
    }
}
int pop(vector<int> &heap)
{
    // Write you code here.
    int n = heap.size();
    if (n == 0)
        return -1;
    else if (n == 1)
    {
        int ans = heap[0];
        heap.pop_back();
        return ans;
    }
    else
    {
        int ans = heap[0];
        swap(heap[0], heap[n - 1]);
        heap.pop_back();
        int t = n - 1;
        while (t >= 0)
        {
            heapify(heap, 0, n - 1);
            t--;
        }
        return ans;
    }
}

// Code Snippet of the push function:

// void push(vector<int> &heap, int x)
// {
//       heap.push_back(x);

//        // Posistion of the current inserted element.
//        int pos=heap.size()-1;

//        // Shifting the element up until it reaches the top most node if it is larger than its parent.
//        while(pos>0)
//        {
//            int parent = (pos-1)/2;
//            if(heap[pos] > heap[parent])
//            {
//                swap(heap[parent],heap[pos]);
//                pos=parent;
//           }
//          else
//          {
//              // As parent is larger the element now is in its correct position.
//              break;
//          }
//      }
//  }
int main()
{

    return 0;
}