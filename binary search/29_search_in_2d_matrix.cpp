// https://leetcode.com/problems/search-a-2d-matrix
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        int row = 0, col = cols - 1;
        while (row < rows && col >= 0)
        {
            int temp = matrix[row][col];
            if (temp == target)
                return true;
            else if (target > temp)
                row++;
            else
                col--;
        }
        return false;
    }
};
int main()
{

    return 0;
}