#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Code here
        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(n + 1, 1e9);
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
        dis[1] = 0;
        pq.push({0, 1});
        while (!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();
            int nodeval = p.second;
            int nodedis = p.first;
            for (auto i : adj[nodeval])
            {
                int adjval = i.first;
                int adjw = i.second;
                if (adjw + nodedis < dis[adjval])
                {
                    dis[adjval] = adjw + nodedis;
                    pq.push({dis[adjval], adjval});
                    parent[adjval] = nodeval;
                }
            }
        }
        if (dis[n] == 1e9)
            return {-1};
        vector<int> path;
        int node = n;
        while (node != parent[node])
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};
int main()
{

    return 0;
}