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
int main()
{
    Disjointset ds(7);
    ds.unionBYSize(1, 2);
    ds.unionBYSize(2, 3);
    ds.unionBYSize(4, 5);
    ds.unionBYSize(6, 7);
    ds.unionBYSize(5, 6);
    if (ds.findUPar(3) == ds.findUPar(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "not same" << endl;
    }
    ds.unionBYSize(3, 7);
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