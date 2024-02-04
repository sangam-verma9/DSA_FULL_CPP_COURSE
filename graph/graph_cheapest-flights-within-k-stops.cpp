#include <bits/stdc++.h>
using namespace std;
// here our first priority is number of stops so we use pairof {stops,{node,dis}}
class Solution
{
public:
    int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        // Code here
        vector<pair<int, int>> adj[n];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dis(n, 1e9);
        dis[src] = 0;
        queue<pair<int, pair<int, int>>> q;
        //{stops,{node,dis}}
        q.push({0, {src, 0}});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int nodedis = it.second.second;
            if (stops > K) // stops become more than K
                continue;
            for (auto i : adj[node])
            {
                int adjnode = i.first;
                int adjdis = i.second;
                if (nodedis + adjdis < dis[adjnode])
                {
                    dis[adjnode] = nodedis + adjdis;
                    q.push({stops + 1, {adjnode, dis[adjnode]}});
                }
            }
        }
        if (dis[dst] == 1e9)
            return -1;
        return dis[dst];
    }
};
int main()
{

    return 0;
}