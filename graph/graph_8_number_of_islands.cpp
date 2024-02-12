class Solution
{
public:
    void bfs(vector<vector<char>> &grid, int row, int col, vector<vector<bool>> &visited)
    {
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        q.push({row, col});
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            int nrow = p.first;
            int ncol = p.second;
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    int newrow = nrow + i;
                    int newcol = ncol + j;
                    if (newrow < n && newrow >= 0 && newcol < m && newcol >= 0 &&
                        visited[newrow][newcol] != 1 && grid[newrow][newcol] == '1')
                    {
                        visited[newrow][newcol] = 1;
                        q.push({newrow, newcol});
                    }
                }
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && visited[i][j] != 1)
                {
                    bfs(grid, i, j, visited);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};