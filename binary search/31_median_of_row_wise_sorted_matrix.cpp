// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lesserthan(int mid, vector<vector<int>> &matrix, int R, int C) // this function finds no of lesser elements than mid
    {
        int t = 0;
        for (int i = 0; i < R; i++)
        {
            int ind = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            t += ind;
        }
        return t;
    }
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        int low = INT_MAX, high = INT_MIN;
        // median lies between minele and maxiele
        for (int i = 0; i < R; i++)
        {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][C - 1]);
        }
        // idea is that median is always greater than no of elements req((R*C)/2)
        int req = (R * C) / 2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (lesserthan(mid, matrix, R, C) <= req)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};
int main()
{

    return 0;
}