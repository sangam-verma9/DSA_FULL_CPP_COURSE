#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        vector<int> adj[N];
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        vector<int> dis(N, 1e9);
        dis[src] = 0;
        q.push(src);
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            for (auto i : adj[front])
            {
                if (dis[front] + 1 < dis[i])
                {
                    dis[i] = dis[front] + 1;
                    q.push(i);
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
int main()
{

    return 0;
}