#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool search(vector<vector<int>> matrix, int n, int m, int x)
    {
        int row = 0, col = m - 1;
        bool f = false;
        while (row >= 0 && row < n && col >= 0 && col < m)
        {
            if (matrix[row][col] == x)
            {
                f = true;
                break;
            }
            else if (matrix[row][col] > x)
            {
                col--;
            }
            else
            {
                row++;
            }
        }
        return f;
    }
};
int main() {

return 0;
}