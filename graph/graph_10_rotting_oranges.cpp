class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited = grid;
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                }
            }
        }
        int tt = 0;
        vector<int> delr = {-1, 0, +1, 0};
        vector<int> delc = {0, +1, 0, -1};
        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tt = max(tt, t);
            for (int i = 0; i < 4; i++)
            {
                int newr = row + delr[i];
                int newc = col + delc[i];
                if (newr < n && newr >= 0 && newc < m && newc >= 0 && visited[newr][newc] == 1)
                {
                    visited[newr][newc] = 2;
                    q.push({{newr, newc}, t + 1});
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return tt;
    }
};