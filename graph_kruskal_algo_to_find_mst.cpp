#include <bits/stdc++.h>
using namespace std;
class Disjointset
{
    vector<int> parent, size;

public:
    Disjointset(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUPar(int node) // find ultimate parent
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionBYSize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int u = i;
                int v = it[0];
                int wt = it[1];
                edges.push_back({wt, {u, v}});
            }
        }
        sort(edges.begin(), edges.end());
        int sum = 0;
        Disjointset ds(V);
        for (auto i : edges)
        {
            int u = i.second.first;
            int v = i.second.second;
            int w = i.first;
            if (ds.findUPar(u) != ds.findUPar(v))
            {
                ds.unionBYSize(u, v);
                sum += w;
            }
        }
        return sum;
    }
};
int main()
{

    return 0;
}