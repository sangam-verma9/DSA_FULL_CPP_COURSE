// https://leetcode.com/problems/critical-connections-in-a-network/
#include <bits/stdc++.h>
using namespace std;
// Bridge in a graph is a edge, after removing that graph is disconnected in two components
class Solution
{
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &visited, vector<int> &tin, vector<int> &low, vector<int> adj[], vector<vector<int>> &ans)
    {
        visited[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (visited[it] == 0)
            {
                dfs(it, node, visited, tin, low, adj, ans);
                low[node] = min(low[node], low[it]);
                if (low[it] > tin[node])
                {
                    ans.push_back({it, node});
                }
            }
            else
            {
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(n, 0);
        vector<int> tin(n, 0); // first time of insertion
        vector<int> low(n, 0); // lowest time of insertion apart from parent if any visited node is neighbor then take its minimum time of insertion
        vector<vector<int>> ans;
        dfs(0, -1, visited, tin, low, adj, ans);
        return ans;
    }
};
int main()
{

    return 0;
}