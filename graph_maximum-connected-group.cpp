/*
You are given an n x n binary grid. A grid is said to be binary if every value in grid is either 1 or 0.

You can change at most one cell in grid from 0 to 1.

You need to find the largest group of connected  1's.

Two cells are said to be connected if both are adjacent to each other and both have same value.
*/
#include <bits/stdc++.h>
using namespace std;
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
private:
    bool isvalid(int i, int j, int n)
    {
        return i >= 0 && i < n && j >= 0 && j < n;
    }

public:
    int MaxConnection(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size();
        Disjointset ds(n * n);

        // step 1 connect all componet which is alreay connected
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 0)
                    continue;
                int dr[] = {-1, 0, +1, 0};
                int dc[] = {0, 1, 0, -1};
                for (int i = 0; i < 4; i++)
                {
                    int newr = row + dr[i];
                    int newc = col + dc[i];
                    if (isvalid(newr, newc, n) && grid[newr][newc] == 1)
                    {
                        int nodeno = row * n + col;
                        int adjnodeno = newr * n + newc;
                        ds.unionBYSize(nodeno, adjnodeno);
                    }
                }
            }
        }

        // step2 now convert 0->1 now count the component
        int mx = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                    continue;
                int dr[] = {-1, 0, +1, 0};
                int dc[] = {0, 1, 0, -1};
                set<int> components;
                for (int i = 0; i < 4; i++)
                {
                    int newr = row + dr[i];
                    int newc = col + dc[i];
                    if (isvalid(newr, newc, n))
                    {
                        if (grid[newr][newc] == 1)
                        {
                            components.insert(ds.findUPar(newr * n + newc));
                        }
                    }
                }
                int sizet = 0;
                for (auto i : components)
                {
                    sizet += ds.size[i];
                }
                mx = max(mx, sizet + 1);
            }
        }
        // if there is alreay all cell have 1 so ->
        for (int i = 0; i < n * n; i++)
        {
            mx = max(mx, ds.size[ds.findUPar(i)]);
        }
        return mx;
    }
};
int main()
{

    return 0;
}
