#include <bits/stdc++.h>
using namespace std;
class Disjointset
{
    vector<int> parent, rank;

public:
    Disjointset(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionBYRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
int main()
{
    Disjointset ds(7);
    ds.unionBYRank(1, 2);
    ds.unionBYRank(2, 3);
    ds.unionBYRank(4, 5);
    ds.unionBYRank(6, 7);
    ds.unionBYRank(5, 6);
    if (ds.findUPar(3) == ds.findUPar(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "not same" << endl;
    }
    ds.unionBYRank(3, 7);
    if (ds.findUPar(3) == ds.findUPar(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "not same" << endl;
    }
    return 0;
}