#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &visited, vector<vector<int>> &grid, vector<pair<int, int>> &vec, int initi, int initj)
    {
        visited[i][j] = 1;
        vec.push_back({i - initi, j - initj});
        int n = grid.size();
        int m = grid[0].size();
        vector<int> delr = {-1, 0, +1, 0};
        vector<int> delc = {0, +1, 0, -1};
        for (int k = 0; k < 4; k++)
        {
            int newr = i + delr[k];
            int newc = j + delc[k];
            if (newr < n && newr >= 0 && newc < m && newc >= 0 && visited[newr][newc] == 0 && grid[newr][newc] == 1)
            {
                dfs(newr, newc, visited, grid, vec, initi, initj);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> s; // for storing distinct sizes of land
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] == 0 && grid[i][j] == 1)
                {
                    vector<pair<int, int>> vec;
                    dfs(i, j, visited, grid, vec, i, j);
                    s.insert(vec);
                }
            }
        }
        return s.size();
    }
};
int main()
{

    return 0;
}