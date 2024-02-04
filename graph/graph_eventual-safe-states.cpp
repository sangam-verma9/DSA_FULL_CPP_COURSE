#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfs(int node, int visited[], vector<int> adj[], int pathvisited[], int count[])
    {
        visited[node] = 1;
        pathvisited[node] = 1;
        for (auto i : adj[node])
        {
            if (visited[i] == 0)
            {
                if (dfs(i, visited, adj, pathvisited, count) == true)
                {
                    return true;
                }
            }
            else if (pathvisited[i] == 1)
            {
                count[i] = 0;
                return true;
            }
        }
        count[node] = 1;
        pathvisited[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        int visited[V] = {0};
        int pathvisited[V] = {0};
        int count[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i, visited, adj, pathvisited, count);
            }
        }
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (count[i] != 0)
                ans.push_back(i);
        }
        return ans;
    }
};
int main()
{

    return 0;
}