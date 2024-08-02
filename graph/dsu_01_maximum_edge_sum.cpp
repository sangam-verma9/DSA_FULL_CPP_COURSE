#include <bits/stdc++.h>
/*
    You are given an undirected tree of n nodes and  n-1 weighted edges. where edges[i] = {u, v, w}, w is the weight of the edge between node u and node v.
    You have to find the sum of the maximum weighted edge in all unordered paths in the tree, which have at least one edge.
    Unordered path means path from u to v and v to u considered same.
*/
using namespace std;

class Solution
{
public:
    int findpar(int x, vector<int> &par)
    {
        vector<int> st;
        while (x != par[x])
        {
            st.push_back(x);
            x = par[x];
        }
        while (!st.empty())
        {
            par[st.back()] = x;
            st.pop_back();
        }
        return x;
    }

    pair<int, int> unionNodes(int x, int y, vector<int> &par, vector<int> &size)
    {
        int px = findpar(x, par);
        int py = findpar(y, par);
        int sx = size[px], sy = size[py];
        if (sx >= sy)
        {
            par[py] = px;
            size[px] += size[py];
        }
        else
        {
            par[px] = py;
            size[py] += size[px];
        }
        return {sx, sy};
    }

    long long maxEdgeSum(int n, vector<vector<int>> &edges)
    {
        vector<int> par(n + 1);
        vector<int> size(n + 1, 1);
        for (int i = 0; i <= n; ++i)
        {
            par[i] = i;
        }
        sort(edges.begin(), edges.end(),
             [](const vector<int> &a, const vector<int> &b)
             { return a[2] < b[2]; });
        long long ans = 0;
        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            pair<int, int> p = unionNodes(u, v, par, size);
            ans += (long long)p.first * (long long)p.second * (long long)w;
        }
        return ans;
    }
};

int main()
{

    return 0;
}