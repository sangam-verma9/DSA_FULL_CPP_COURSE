#include <bits/stdc++.h>
using namespace std;
bool is_safe(vector<vector<int>> m, int n, int x, int y, vector<vector<int>> visited)
{
    if (x <= n - 1 && y <= n - 1 && visited[x][y] == 0 && m[x][y] == 1)
    {
        return true;
    }
    return false;
}
void rat_in_maze(vector<vector<int>> m, int n, string path, int x, int y, vector<vector<int>> visited, vector<string> &ans)
{
    // base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;
    // 4 ways to move
    // down
    int newx = x + 1;
    int newy = y;
    if (is_safe(m, n, newx, newy, visited))
    {
        path.push_back('D');
        rat_in_maze(m, n, path, newx, newy, visited, ans);
        path.pop_back();
    }
    // right
    newx = x;
    newy = y + 1;
    if (is_safe(m, n, newx, newy, visited))
    {
        path.push_back('R');
        rat_in_maze(m, n, path, newx, newy, visited, ans);
        path.pop_back();
    }
    // up
    newx = x - 1;
    newy = y;
    if (is_safe(m, n, newx, newy, visited))
    {
        path.push_back('U');
        rat_in_maze(m, n, path, newx, newy, visited, ans);
        path.pop_back();
    }
    // left
    newx = x;
    newy = y - 1;
    if (is_safe(m, n, newx, newy, visited))
    {
        path.push_back('L');
        rat_in_maze(m, n, path, newx, newy, visited, ans);
        path.pop_back();
    }

    visited[x][y] = 0;
}
int main()
{
    int n = 4;
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};
    vector<string> ans;
    string path = "";
    int sindx = 0;
    int sindy = 0;
    vector<vector<int>> visited=m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
    rat_in_maze(m, n, path, sindx, sindy, visited, ans);
    // output
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}