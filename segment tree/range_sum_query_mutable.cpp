// https://leetcode.com/problems/range-sum-query-mutable/
#include <bits/stdc++.h>
using namespace std;
class NumArray
{
public:
    int *seg;
    int n;
    void buildTree(vector<int> &nums, int ind, int low, int high)
    {
        if (low == high)
        {
            seg[ind] = nums[low];
            return;
        }
        int mid = (low + high) / 2;
        buildTree(nums, 2 * ind + 1, low, mid);
        buildTree(nums, 2 * ind + 2, mid + 1, high);
        int left = seg[ind * 2 + 1];
        int right = seg[ind * 2 + 2];
        seg[ind] = left + right;
    }
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        seg = new int[4 * n];
        buildTree(nums, 0, 0, n - 1);
    }
    void updateNode(int ind, int low, int high, int i, int val)
    {
        // no overlap
        if (i < low || i > high)
        {
            return;
        }
        // reached to leaf node
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        // i is lying in range low and high
        int mid = (low + high) / 2;
        updateNode(ind * 2 + 1, low, mid, i, val);
        updateNode(ind * 2 + 2, mid + 1, high, i, val);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }
    void update(int index, int val)
    {
        updateNode(0, 0, n - 1, index, val);
    }
    int query(int ind, int low, int high, int ql, int qr)
    {
        if (low >= ql && high <= qr)
        {
            return seg[ind];
        }
        if (qr < low || ql > high)
        {
            return 0;
        }
        int mid = (low + high) / 2;
        int left = query(ind * 2 + 1, low, mid, ql, qr);
        int right = query(ind * 2 + 2, mid + 1, high, ql, qr);
        return left + right;
    }
    int sumRange(int left, int right)
    {
        return query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
int main()
{

    return 0;
}