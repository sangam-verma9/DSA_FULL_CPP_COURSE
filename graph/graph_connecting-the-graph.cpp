#include <bits/stdc++.h>
using namespace std;
/*You are given a graph with n vertices and m edges.

You can remove one edge from anywhere and add that edge between any two vertices in one operation.

Find the minimum number of operations that will be required to make the graph connected.

If it is not possible to make the graph connected, return -1.*/
class Disjointset
{
public:
    vector<int> parent, size;
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
    int Solve(int n, vector<vector<int>> &edge)
    {
        // code here
        Disjointset ds(n);
        int extraedge = 0;
        for (auto i : edge)
        {
            int u = i[0];
            int v = i[1];
            if (ds.findUPar(u) == ds.findUPar(v))
            {
                extraedge++;
            }
            else
            {
                ds.unionBYSize(u, v);
            }
        }
        int connc = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
                connc++;
        }
        int ans = connc - 1;
        // cout<<extraedge<<" "<<connc<<" ";
        if (extraedge >= ans)
        {
            return ans;
        }
        return -1;
    }
};
int main()
{

    return 0;
}