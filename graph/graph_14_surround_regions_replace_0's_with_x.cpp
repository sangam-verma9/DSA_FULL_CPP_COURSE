// https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int i, int j, vector<vector<char>> &mat, vector<int> &delr, vector<int> &delc, int n, int m)
    {
        mat[i][j] = '&';
        for (int k = 0; k < 4; k++)
        {
            int newr = i + delr[k];
            int newc = j + delc[k];
            if (newr < n && newr >= 0 && newc < m && newc >= 0 && mat[newr][newc] == 'O')
            {
                dfs(newr, newc, mat, delr, delc, n, m);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<int> delr = {-1, 0, +1, 0};
        vector<int> delc = {0, +1, 0, -1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && mat[i][j] == 'O')
                {
                    dfs(i, j, mat, delr, delc, n, m);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == '&')
                    mat[i][j] = 'O';
                else if (mat[i][j] == 'O')
                    mat[i][j] = 'X';
            }
        }
        return mat;
    }
};
int main() {

return 0;
}