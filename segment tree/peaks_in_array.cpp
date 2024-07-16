// https://leetcode.com/problems/peaks-in-array/
#include <bits/stdc++.h>
using namespace std;
class SegmentTree
{
public:
    vector<int> root;
    int n;
    vector<int> nums;

    SegmentTree(vector<int> &nums)
    {
        this->n = nums.size();
        this->nums = nums;
        root.resize(n * 4);
        build(0, 0, n - 1, nums);
    }

    void build(int i, int left, int right, vector<int> &nums)
    {
        if (left == right)
        {
            if (left == 0 || right == n - 1 || nums[left] <= nums[left - 1] || nums[left] <= nums[left + 1])
                root[i] = 0;
            else
                root[i] = 1;
            return;
        }
        int middle = left + (right - left) / 2;
        build(i * 2 + 1, left, middle, nums);
        build(i * 2 + 2, middle + 1, right, nums);
        root[i] = root[i * 2 + 1] + root[i * 2 + 2];
    }

    void update(int index, int val)
    {
        nums[index] = val;
        update(0, 0, n - 1, index, val);
    }

    void update(int i, int left, int right, int index, int val)
    {
        if (left == right)
        {
            if (left == 0 || right == n - 1 || nums[left] <= nums[left - 1] || nums[left] <= nums[left + 1])
                root[i] = 0;
            else
                root[i] = 1;
            return;
        }
        int middle = left + (right - left) / 2;
        if (index <= middle)
        {
            update(i * 2 + 1, left, middle, index, val);
        }
        else
        {
            update(i * 2 + 2, middle + 1, right, index, val);
        }
        root[i] = root[i * 2 + 1] + root[i * 2 + 2];
    }

    int get(int start, int end)
    {
        return get(0, 0, n - 1, start, end);
    }

    int get(int i, int left, int right, int start, int end)
    {
        if (start > right || end < left)
            return 0;
        if (left >= start && right <= end)
            return root[i];
        int middle = left + (right - left) / 2;
        int l = get(i * 2 + 1, left, middle, start, end);
        int r = get(i * 2 + 2, middle + 1, right, start, end);
        return l + r;
    }
};

class Solution
{
public:
    vector<int> countOfPeaks(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<int> res;
        SegmentTree root(nums);
        int n = nums.size();
        auto isPeak = [&](int i)
        {
            if (i == 0 || i == n - 1 || nums[i] <= nums[i - 1] || nums[i] <= nums[i + 1])
                return false;
            return true;
        };
        for (auto &q : queries)
        {
            int type = q[0], left = q[1], right = q[2];
            if (type == 1)
            {
                int ans = root.get(left, right) - isPeak(left) - isPeak(right); // remove the peaked element from the two end
                res.push_back(max(0, ans));
            }
            else
            {
                nums[left] = right;
                root.update(left, right);
                if (left > 0)
                    root.update(left - 1, nums[left - 1]); // update left element as well since it can be potential peak element
                if (left < n - 1)
                    root.update(left + 1, nums[left + 1]); // update right
            }
        }
        return res;
    }
};
int main()
{

    return 0;
}