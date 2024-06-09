#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st;
        vector<int> dis(V, 1e9);
        st.insert({0, S});
        dis[S] = 0;
        while (!st.empty())
        {
            pair<int, int> node = *(st.begin());
            st.erase(node);
            int nodeval = node.second;
            int nodedis = node.first;
            for (auto i : adj[nodeval])
            {
                int adjnode = i[0];
                int adjw = i[1];
                if (nodedis + adjw < dis[adjnode])
                {
                    if (dis[adjnode] == 1e9)
                    {
                        st.erase({dis[adjnode], adjnode});
                    }
                    dis[adjnode] = nodedis + adjw;
                    st.insert({dis[adjnode], adjnode});
                }
            }
        }
        return dis;
    }
};
int main()
{

    return 0;
}