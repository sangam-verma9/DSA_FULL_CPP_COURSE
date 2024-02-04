#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
    {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        dis[source.first][source.second] = 0;
        pq.push({0, {source.first, source.second}});
        vector<int> delx = {-1, 0, +1, 0};
        vector<int> dely = {0, +1, 0, -1};
        while (!pq.empty())
        {
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            int nodex = p.second.first;
            int nodey = p.second.second;
            int nodedis = p.first;
            for (int i = 0; i < 4; i++)
            {
                int newx = nodex + delx[i];
                int newy = nodey + dely[i];
                if (newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy] == 1 && (nodedis + 1) < dis[newx][newy])
                {
                    dis[newx][newy] = nodedis + 1;
                    pq.push({dis[newx][newy], {newx, newy}});
                }
            }
        }
        if (dis[destination.first][destination.second] == 1e9)
            return -1;
        return dis[destination.first][destination.second];
    }
};

// using queue because here we goning 1 step in each so no need to priority queue because already sorted
class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
    {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        queue<pair<int, pair<int, int>>> q;
        dis[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});
        vector<int> delx = {-1, 0, +1, 0};
        vector<int> dely = {0, +1, 0, -1};
        while (!q.empty())
        {
            pair<int, pair<int, int>> p = q.front();
            q.pop();
            int nodex = p.second.first;
            int nodey = p.second.second;
            int nodedis = p.first;
            for (int i = 0; i < 4; i++)
            {
                int newx = nodex + delx[i];
                int newy = nodey + dely[i];
                if (newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy] == 1 && (nodedis + 1) < dis[newx][newy])
                {
                    dis[newx][newy] = nodedis + 1;
                    q.push({dis[newx][newy], {newx, newy}});
                }
            }
        }
        if (dis[destination.first][destination.second] == 1e9)
            return -1;
        return dis[destination.first][destination.second];
    }
};
int main()
{

    return 0;
}