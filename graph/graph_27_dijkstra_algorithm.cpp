// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(V, 1e9);
        dis[S] = 0;
        pq.push({0, S});
        while (!pq.empty())
        {
            int node = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            for (auto i : adj[node])
            {
                int adjnode = i[0];
                int adjw = i[1];
                if (adjw + weight < dis[adjnode])
                {
                    dis[adjnode] = adjw + weight;
                    pq.push({dis[adjnode], adjnode});
                }
            }
        }
        return dis;
    }
};
int main()
{

    return 0;
}