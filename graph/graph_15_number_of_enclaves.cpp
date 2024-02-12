#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &mat, vector<int> &delr, vector<int> &delc, int &n, int &m)
    {
        mat[i][j] = 0;
        for (int k = 0; k < 4; k++)
        {
            int newr = i + delr[k];
            int newc = j + delc[k];
            if (newr < n && newr >= 0 && newc < m && newc >= 0 && mat[newr][newc] == 1)
            {
                dfs(newr, newc, mat, delr, delc, n, m);
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> mat = grid;
        vector<int> delr = {-1, 0, +1, 0};
        vector<int> delc = {0, +1, 0, -1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && mat[i][j] == 1)
                {
                    dfs(i, j, mat, delr, delc, n, m);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                    cnt++;
            }
        }
        return cnt;
    }
};
int main()
{

    return 0;
}