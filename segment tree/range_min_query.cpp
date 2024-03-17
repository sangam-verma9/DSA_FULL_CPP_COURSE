// https://www.geeksforgeeks.org/problems/range-minimum-query/1
#include <bits/stdc++.h>
using namespace std;
void buildTree(int *seg, int *arr, int index, int low, int high)
{
    if (low == high)
    {
        seg[index] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    buildTree(seg, arr, index * 2 + 1, low, mid);
    buildTree(seg, arr, index * 2 + 2, mid + 1, high);
    seg[index] = min(seg[index * 2 + 1], seg[index * 2 + 2]);
}
int *constructST(int arr[], int n)
{
    // Your code here
    int *seg = new int[4 * n];
    buildTree(seg, arr, 0, 0, n - 1);
    return seg;
}

/* The functions returns the
 min element in the range
 from a and b */
int query(int st[], int index, int low, int high, int rs, int re)
{
    if (re < low || rs > high)
    {
        return INT_MAX;
    }
    if (rs <= low && re >= high)
    {
        return st[index];
    }
    int mid = (low + high) / 2;
    int left = query(st, index * 2 + 1, low, mid, rs, re);
    int right = query(st, index * 2 + 2, mid + 1, high, rs, re);
    return min(left, right);
}
int RMQ(int st[], int n, int a, int b)
{
    // Your code here
    return query(st, 0, 0, n - 1, a, b);
}
int main()
{

    return 0;
}