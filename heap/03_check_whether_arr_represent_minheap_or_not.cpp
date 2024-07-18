// https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        for (int i = 0; i < n; i++)
        {
            int l = i * 2 + 1;
            int r = i * 2 + 2;
            if ((l < n && arr[i] < arr[l]) || (r < n && arr[i] < arr[r]))
                return false;
        }
        return true;
    }
};
int main()
{

    return 0;
}