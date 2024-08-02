#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    parent[1] = -1;
    key[1] = 0;

    // start algo
    for (int i = 1; i <= n; i++)
    {
        int mini = INT_MAX;
        int u;
        for (int j = 1; j <= n; j++)
        {
            if (mst[j] == false && key[j] < mini)
            {
                mini = key[j];
                u = j;
            }
        }

        // mark true of mininmum element
        mst[u] = true;

        // go for adjecent element of curr index
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && key[v] > w)
            {
                key[v] = w;
                parent[v] = u;
            }
        }
    }
    // now parent vector is ready to ans
    vector<pair<pair<int, int>, int>> ans;
    // here we not go from ind 1 because 1 parent is already -1
    for (int i = 2; i <= n; i++)
    {
        ans.push_back(make_pair(make_pair(parent[i], i), key[i]));
    }
    return ans;
}
int main()
{

    return 0;
}