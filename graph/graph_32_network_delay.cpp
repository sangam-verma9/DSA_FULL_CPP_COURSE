// https://leetcode.com/problems/network-delay-time/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        unordered_map<int, list<pair<int, int>>> adj;
        for (auto it : times)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }
        vector<int> dis(n + 1, 1e6);
        dis[k] = 0;
        priority_queue<pair<int, int>> pq; // dis ,node
        pq.push({0, k});
        while (!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            int node = p.second;
            int nodedis = p.first;
            for (auto it : adj[node])
            {
                if (it.second + nodedis < dis[it.first])
                {
                    dis[it.first] = it.second + nodedis;
                    pq.push({dis[it.first], it.first});
                }
            }
        }
        int maxi = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dis[i] == 1e6)
                return -1;
            else
                maxi = max(maxi, dis[i]);
        }
        return maxi;
    }
};
int main()
{

    return 0;
}