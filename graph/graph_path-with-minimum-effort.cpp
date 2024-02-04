#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int MinimumEffort(vector<vector<int>> &heights)
    {
        // Code here
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> diff(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        diff[0][0] = 0;
        pq.push({0, {0, 0}});
        int delx[] = {-1, 0, +1, 0};
        int dely[] = {0, +1, 0, -1};
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int nodediff = it.first;
            int nodex = it.second.first;
            int nodey = it.second.second;
            for (int i = 0; i < 4; i++)
            {
                int newx = nodex + delx[i];
                int newy = nodey + dely[i];
                if (newx >= 0 && newx < n & newy >= 0 && newy < m)
                {
                    int neweffort = max(abs(heights[newx][newy] - heights[nodex][nodey]), nodediff);
                    if (neweffort < diff[newx][newy])
                    {
                        diff[newx][newy] = neweffort;
                        pq.push({neweffort, {newx, newy}});
                    }
                }
            }
        }
        return diff[n - 1][m - 1];
    }
};
// same as upper but here we find solution when we reach our target node with mininmun diff
class Solution
{
public:
    int MinimumEffort(vector<vector<int>> &heights)
    {
        // Code here
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> diff(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        diff[0][0] = 0;
        pq.push({0, {0, 0}});
        int delx[] = {-1, 0, +1, 0};
        int dely[] = {0, +1, 0, -1};
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int nodediff = it.first;
            int nodex = it.second.first;
            int nodey = it.second.second;
            if (nodex == n - 1 && nodey == m - 1)
                return nodediff;
            for (int i = 0; i < 4; i++)
            {
                int newx = nodex + delx[i];
                int newy = nodey + dely[i];
                if (newx >= 0 && newx < n & newy >= 0 && newy < m)
                {
                    int neweffort = max(abs(heights[newx][newy] - heights[nodex][nodey]), nodediff);
                    if (neweffort < diff[newx][newy])
                    {
                        diff[newx][newy] = neweffort;
                        pq.push({neweffort, {newx, newy}});
                    }
                }
            }
        }
        return 0;
    }
};
int main()
{

    return 0;
}