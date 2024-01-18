#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < vec.size(); i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        pair<int, int> p1 = make_pair(u, w);
        pair<int, int> p2 = make_pair(v, w);
        adj[u].push_back(p2);
        adj[v].push_back(p1);
    }
    vector<int> sortdis(vertices, INT_MAX);

    // creation of set on basis of distance and node
    set<pair<int, int>> st;
    sortdis[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        auto top = *(st.begin());
        int nodedis = top.first;
        int topnode = top.second;

        // remove top record
        st.erase(st.begin());
        // traverse on neighbour
        for (auto neighbour : adj[topnode])
        {
            if ((nodedis + neighbour.second) < sortdis[neighbour.first])
            {
                auto record = st.find(make_pair(sortdis[neighbour.first], neighbour.first));
                if (record != st.end())
                {
                    st.erase(record);
                }
                // distance update
                sortdis[neighbour.first] = nodedis + neighbour.second;
                // record push in set
                st.insert(make_pair(sortdis[neighbour.first], neighbour.first));
            }
        }
    }
    return sortdis;
}

int main()
{

    return 0;
}