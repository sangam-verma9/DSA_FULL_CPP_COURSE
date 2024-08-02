#include <bits/stdc++.h>
using namespace std;
// some mistake
class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        // code here
        int mod = 1000000007;
        vector<pair<int, int>> adj[n];
        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<pair<int, int>> dis(n, {1e9, 0});
        // pair of {dis,no of path}
        dis[0] = {0, 1};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // pair of {dis,node}
        pq.push({0, 0});
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int nodedis = it.first;
            int node = it.second;
            for (auto i : adj[node])
            {
                int newnode = i.first;
                int newdis = i.second;
                if (nodedis + newdis < dis[newnode].first)
                {
                    dis[newnode].first = nodedis + newdis;
                    dis[newnode].second = 1;
                    pq.push({dis[newnode].first, newnode});
                }
                else if (nodedis + newdis == dis[newnode].first)
                {
                    // cout<<node<<"hi"<<" ";
                    dis[newnode].second = (dis[newnode].second + dis[node].second) % mod;
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<dis[i].second<<" ";
        // }cout<<endl;
        return dis[n - 1].second;
    }
};
//
int main()
{

    return 0;
}