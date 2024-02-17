// Given an array of length ‘N’, where each element denotes the position of a stall. Now you have ‘N’ stalls and an integer ‘K’ which denotes the number of cows that are aggressive. To prevent the cows from hurting each other, you need to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. Return the largest minimum distance.
// https://www.codingninjas.com/studio/problems/aggressive-cows_1082559
#include <bits/stdc++.h>
using namespace std;
bool ispossible(int *stalls, int k, int mid, int n)
{
    int cow_count = 1;
    int lastpos = stalls[0];
    for (int i = 0; i < n; i++)
    {
        if (stalls[i] - lastpos >= mid)
        {
            cow_count++;
            if (cow_count == k)
            {
                return true;
            }
            lastpos = stalls[i];
        }
    }
    return false;
}
int aggressive_cow(int *stalls, int k, int n)
{
    int s = 0;
    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, stalls[i]);
    }
    int e = maxi;
    int ans = -1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (ispossible(stalls, k, mid, n))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    int stalls[] = {4, 2, 1, 3, 6};
    int n = sizeof(stalls) / sizeof(int);
    sort(stalls, stalls + n);
    int k = 2;
    cout << aggressive_cow(stalls, k, n);
    return 0;
}