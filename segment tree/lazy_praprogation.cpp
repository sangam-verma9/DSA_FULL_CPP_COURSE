// https://www.youtube.com/watch?v=xuoQdt5pHj0&ab_channel=TusharRoy-CodingMadeSimple
#include <bits/stdc++.h>
using namespace std;
void buildTree(int ind, int low, int high, int arr[], int seg[])
{
    if (low == high)
    {
        seg[ind] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    buildTree(2 * ind + 1, low, mid, arr, seg);
    buildTree(2 * ind + 2, mid + 1, high, arr, seg);
    int left = seg[ind * 2 + 1];
    int right = seg[ind * 2 + 2];
    seg[ind] = max(left, right);
}
void updateSegmentTreeLazy(int seg[], int lazy[], int srange, int erange, int delta, int low, int high, int position)
{
    if (low > high)
    {
        return;
    }
    // make sure all prapogation is done at position, If not update
    // tree at pos mark its children for lazy propogaion
    if (lazy[position] != 0)
    {
        seg[position] += lazy[position];
        if (low != high)
        { // not a leaf node
            lazy[2 * position + 1] += lazy[position];
            lazy[2 * position + 2] += lazy[position];
        }
        lazy[position] = 0;
    }

    // no overlapping
    if (srange > high || erange < low)
    {
        return;
    }

    // total overlap condition
    if (low >= srange && high <= erange)
    {
        seg[position] += delta;
        if (low != high)
        {
            lazy[2 * position + 1] += delta;
            lazy[2 * position + 2] += delta;
        }
        return;
    }
    // otherwise patial overlap so look both left and right
    int mid = (low + high) / 2;
    updateSegmentTreeLazy(seg, lazy, srange, erange, delta, low, mid, 2 * position + 1);
    updateSegmentTreeLazy(seg, lazy, srange, erange, delta, mid + 1, high, 2 * position + 2);
    seg[position] = min(seg[2 * position + 1], seg[2 * position + 2]);
}
int querySegmentTreeLazy(int seg[], int lazy[], int srange, int erange, int low, int high, int position)
{
    if (low > high)
    {
        return;
    }
    // make sure all prapogation is done at position, If not update
    // tree at pos mark its children for lazy propogaion
    if (lazy[position] != 0)
    {
        seg[position] += lazy[position];
        if (low != high)
        { // not a leaf node
            lazy[2 * position + 1] += lazy[position];
            lazy[2 * position + 2] += lazy[position];
        }
        lazy[position] = 0;
    }

    // no overlapping
    if (srange > high || erange < low)
    {
        return INT_MAX;
    }
    // completer overlapping
    if (low >= srange && high <= erange)
    {
        return seg[position];
    }
    // otherwise patial overlap so look both left and right
    int mid = (low + high) / 2;
    int left = querySegmentTreeLazy(seg, lazy, srange, erange, low, mid, position * 2 + 1);
    int right = querySegmentTreeLazy(seg, lazy, srange, erange, mid + 1, high, position * 2 + 2);
    return min(left, right);
}
int main()
{
    int n;
    cin >> n;
    int arr[10000], seg[4 * 100000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    buildTree(0, 0, n - 1,arr,seg);
    int lazy[4 * 100000] = {0};
    updateSegmentTreeLazy(seg, lazy, 2, 5, 10, 0, n - 1, 0);
    updateSegmentTreeLazy(seg, lazy, 3, 7, 10, 0, n - 1, 0);
    cout << querySegmentTreeLazy(seg, lazy, 2, 5, 0, n - 1, 0) << endl;

    return 0;
}