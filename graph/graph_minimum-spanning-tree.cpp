#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> visited(V, 0);
        pq.push({0, 0});
        // pair of {wt,node}
        int sum = 0;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            if (visited[node] == 1)
                continue;
            visited[node] = 1;
            sum += wt;
            for (auto i : adj[node])
            {
                int adjnode = i[0];
                int adjwt = i[1];
                if (visited[adjnode] == 0)
                {
                    pq.push({adjwt, adjnode});
                }
            }
        }
        return sum;
    }
};
int main()
{

    return 0;
}