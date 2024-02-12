// https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }
        vector<int> delr = {-1, 0, +1, 0};
        vector<int> delc = {0, +1, 0, -1};
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            ans[r][c] = dis;
            for (int i = 0; i < 4; i++)
            {
                int newr = r + delr[i];
                int newc = c + delc[i];
                if (newr < n && newr >= 0 && newc < m && newc >= 0 && visited[newr][newc] != 1)
                {
                    visited[newr][newc] = 1;
                    q.push({{newr, newc}, dis + 1});
                }
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}