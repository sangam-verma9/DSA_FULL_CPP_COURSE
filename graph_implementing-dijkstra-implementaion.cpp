#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(V, 1e9);
        dis[S] = 0;
        pq.push({0, S});
        while (!pq.empty())
        {
            int node = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            for (auto i : adj[node])
            {
                int adjnode = i[0];
                int adjw = i[1];
                if (adjw + weight < dis[adjnode])
                {
                    dis[adjnode] = adjw + weight;
                    pq.push({dis[adjnode], adjnode});
                }
            }
        }
        return dis;
    }
};
// using set data structure
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
                    if (dis[adjnode] == 1e9) // if already present on set then erase it
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