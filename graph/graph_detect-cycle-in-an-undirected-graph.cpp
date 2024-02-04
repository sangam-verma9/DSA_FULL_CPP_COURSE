#include <bits/stdc++.h>
using namespace std;
// bfs solution
class Solution
{
public:
    bool detect(int src, vector<int> adj[], int visited[])
    {
        visited[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            int ele = p.first;
            int parent = p.second;
            q.pop();
            for (auto neighbour : adj[ele])
            {
                if (visited[neighbour] != 1)
                {
                    visited[neighbour] = 1;
                    q.push({neighbour, ele});
                }
                else if (parent != neighbour)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        int visited[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                if (detect(i, adj, visited))
                    return true;
            }
        }
        return false;
    }
};
// dfs solution
class Solution
{
public:
    bool detect(int src, int parent, vector<int> adj[], int visited[])
    {
        visited[src] = 1;
        for (auto neighbour : adj[src])
        {
            if (visited[neighbour] != 1)
            {
                if (detect(neighbour, src, adj, visited) == true)
                {
                    return true;
                }
            }
            else if (parent != neighbour)
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        int visited[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                if (detect(i, -1, adj, visited))
                    return true;
            }
        }
        return false;
    }
};
int main()
{

    return 0;
}