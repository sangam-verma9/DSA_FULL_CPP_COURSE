// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
#include <bits/stdc++.h>
using namespace std;
/*
Here we suppose whole row as a node and whole column as a node so row no. remain same
and for col no. we need to suppose next no. which is maxrow+col+1. here we use stonenode
to store stone because all nodes (maxrow+maxcol+1) not storing stone to find main
connected components we have to use this.
*/
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
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        int maxrow = 0, maxcol = 0;
        for (auto i : stones)
        {
            maxrow = max(maxrow, i[0]);
            maxcol = max(maxcol, i[1]);
        }
        Disjointset ds(maxrow + maxcol + 1);
        unordered_map<int, int> stonenode;
        for (auto it : stones)
        {
            int noderow = it[0];
            int nodecol = it[1] + maxrow + 1;
            ds.unionBYSize(noderow, nodecol);
            stonenode[noderow] = 1;
            stonenode[nodecol] = 1;
        }
        int component = 0;
        for (auto it : stonenode)
        {
            if (ds.findUPar(it.first) == it.first)
                component++;
        }
        return n - component;
    }
};
int main()
{

    return 0;
}