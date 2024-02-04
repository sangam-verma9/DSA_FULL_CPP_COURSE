#include <bits/stdc++.h>
using namespace std;
// dfs algo
class Solution
{
public:
    bool dfs(int node, int visited[], int pathvisited[], vector<int> adj[])
    {
        visited[node] = 1;
        pathvisited[node] = 1;
        for (auto i : adj[node])
        {
            if (visited[i] == 0)
            {
                return dfs(i, visited, pathvisited, adj);
            }
            else if (pathvisited[i] == 1)
            {
                return true;
            }
        }
        pathvisited[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        int visited[V] = {0};
        int pathvisited[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                if (dfs(i, visited, pathvisited, adj) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// bfs method kans algo
class Solution
{
public:
    bool isCyclic(int V, vector<int> adj[])
    {
        int indegree[V] = {0};
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        int cnt = 0;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            cnt++;
            for (auto it : adj[front])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        if (cnt == V)
            return false;
        return true;
    }
};
int main()
{

    return 0;
}