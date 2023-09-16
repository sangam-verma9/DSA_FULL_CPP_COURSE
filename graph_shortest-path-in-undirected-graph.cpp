#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void toposort(int node, vector<pair<int, int>> adj[], stack<int> &st, int visited[])
    {
        visited[node] = 1;
        for (auto i : adj[node])
        {
            int v = i.first;
            if (visited[v] == 0)
            {
                toposort(v, adj, st, visited);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }
        stack<int> st;
        int visited[N] = {0};
        for (int i = 0; i < N; i++)
        {
            if (visited[i] == 0)
            {
                toposort(i, adj, st, visited);
            }
        }
        vector<int> dis(N, 1e9);
        dis[0] = 0;
        while (!st.empty())
        {
            int front = st.top();
            st.pop();
            for (auto i : adj[front])
            {
                if (dis[front] + i.second < dis[i.first])
                {
                    dis[i.first] = dis[front] + i.second;
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (dis[i] == 1e9)
            {
                dis[i] = -1;
            }
        }
        return dis;
    }
};
int main() {

return 0;
}