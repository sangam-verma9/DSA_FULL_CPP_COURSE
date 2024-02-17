// https://www.codingninjas.com/studio/problems/painter-s-partition-problem_1089557
#include <bits/stdc++.h>
using namespace std;
bool ispossible(long long mid, vector<int> &arr, int n, int m)
{
    int cnt = 1;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            return false;
        temp += arr[i];
        if (temp > mid)
        {
            cnt++;
            temp = arr[i];
        }
        if (cnt > m)
            return false;
    }
    return cnt <= m;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();
    long long sum = 0;
    for (auto i : boards)
        sum += i;
    long long s = 0, e = sum;
    long long ans = -1, mid = 0;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (ispossible(mid, boards, n, k))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}
int main()
{

    return 0;
}