// https://www.codingninjas.com/studio/problems/row-of-a-matrix-with-maximum-ones_982768
#include <bits/stdc++.h>
using namespace std;
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int ind = -1, maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = m;
        int s = 0, e = m - 1, mid = 0;
        while (s <= e)
        {
            mid = (s + e) / 2;
            if (matrix[i][mid] == 0)
            {
                temp = m - mid - 1;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        if (temp > maxi)
        {
            ind = i;
            maxi = temp;
        }
    }
    return ind;
}
int main()
{

    return 0;
}