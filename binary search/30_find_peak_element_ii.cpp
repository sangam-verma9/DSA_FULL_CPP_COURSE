// https://leetcode.com/problems/find-a-peak-element-ii/
#include <bits/stdc++.h>
using namespace std;
//**** approach - 1 ***
class Solution
{
public:
    bool ispossible(int i, int j, int n, int m)
    {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        int row = 0, col = 0;
        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};
        while (row < n && col < m)
        {
            bool f = false;
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if (ispossible(nrow, ncol, n, m) && mat[row][col] < mat[nrow][ncol])
                {
                    row = nrow;
                    col = ncol;
                    f = true;
                    break;
                }
            }
            if (f == false)
                return {row, col};
        }
        return {0, 0};
    }
};
//**** approach - 2 (striver) ****
class Solution
{
public:
    int findlargestind(int col, vector<vector<int>> &mat)
    {
        int n = mat.size();
        int ind = -1, ele = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][col] > ele)
            {
                ele = mat[i][col];
                ind = i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int m = mat[0].size();
        int s = 0, e = m - 1;
        int mid = 0;
        while (s <= e)
        {
            mid = (s + e) / 2;
            int row = findlargestind(mid, mat);
            int col = mid;
            int leftele = col - 1 >= 0 ? mat[row][col - 1] : -1;
            int rightele = col + 1 < m ? mat[row][col + 1] : -1;
            if (leftele < mat[row][col] && rightele < mat[row][col])
            {
                return {row, col};
            }
            else if (leftele > mat[row][col])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return {0, 0};
    }
};
//******
int main()
{

    return 0;
}