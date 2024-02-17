// https://www.codingninjas.com/studio/problems/occurrence-of-x-in-a-sorted-array_630456
#include <bits/stdc++.h>
using namespace std;
int first_index(vector<int> &arr, int n, int key)
{
    int s = 0, e = n - 1;
    int mid = (s + e) / 2;
    int a = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            e = mid - 1;
            a = mid;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = (s + e) / 2;
    }
    return a;
}
int last_index(vector<int> &arr, int n, int key)
{
    int s = 0, e = n - 1;
    int mid = (s + e) / 2;
    int a = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            s = mid + 1;
            a = mid;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = (s + e) / 2;
    }
    return a;
}
int count(vector<int> &arr, int n, int x)
{
    // Write Your Code Here
    int a = first_index(arr, n, x);
    int b = last_index(arr, n, x);
    if (a == -1)
        return 0;
    return b - a + 1;
}

int main()
{

    return 0;
}