// https://practice.geeksforgeeks.org/contest/job-a-thon-31-hiring-challenge/problems
#include <bits/stdc++.h>
using namespace std;
/*
Geek, a devoted boyfriend, wants to surprise his girlfriend Geekina with a beautiful bouquet
 of roses. Geek has a rose garden with N roses , each of which has a certain value  associated 
 with it. However, Geek faces a unique challenge in choosing the roses for the bouquet. He
  must select a consecutive sequence of roses  in such a way that the greatest common divisor
  (GCD) of the values of all the chosen roses is less than or equal to a given number, K.

*/
class Solution
{
public:
    void build(vector<long long> &tree, int node, int l, int r, vector<long long> &arr)
    {
        if (l == r)
        {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        int left = 2 * node;
        int right = left + 1;
        build(tree, left, l, mid, arr);
        build(tree, right, mid + 1, r, arr);
        tree[node] = __gcd(tree[left], tree[right]);
    }

    long long query(int node, int start, int end, int l, int r, vector<long long> &tree)
    {
        if (end < l or r < start)
            return 0;
        if (start == end)
            return tree[node];
        else if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        auto leftans = query(2 * node, start, mid, l, r, tree);
        auto rightans = query(2 * node + 1, mid + 1, end, l, r, tree);
        return __gcd(leftans, rightans);
    }

    long long CountBouquets(int N, long long k, vector<long long> &arr)
    {
        vector<long long> tree(4 * N + 2);
        build(tree, 1, 0, N - 1, arr);
        int s = 0;
        int e = 0;
        long long r;
        long long ans = 0;
        /* Using two pointers, the code checks each possible subarray and counts how many
         have a GCD less than or equal to k.
         If the GCD is less than or equal to k, it means all subarrays starting from s
        to any position from e to N-1 will also satisfy the condition, so we increment
         the answer by N - e*/
        while (s <= N - 1 && e <= N - 1)
        {
            if (e >= s)
            {
                r = query(1, 0, N - 1, s, e, tree);
            }
            else
            {
                r = 1e9 + 1;
            }
            if (e < s)
            {
                e++;
            }
            else if (r <= k)
            {
                ans += N - e;
                s++;
            }
            else
            {
                e++;
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}