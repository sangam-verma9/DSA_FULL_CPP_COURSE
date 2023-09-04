#include <bits/stdc++.h>
using namespace std;
// bfs
class Solution
{
public:
    bool bfs(int start, vector<int> adj[], int col[])
    {
        col[start] = 0;
        queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            for (auto i : adj[front])
            {
                if (col[i] == -1)
                {
                    col[i] = !col[front];
                    q.push(i);
                }
                else if (col[i] == col[front])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<int> adj[])
    {
        int col[V];
        for (int i = 0; i < V; i++)
            col[i] = -1;
        for (int i = 0; i < V; i++)
        {
            if (col[i] == -1)
            {
                if (bfs(i, adj, col) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// dfs
class Solution
{
public:
    bool dfs(int start, vector<int> adj[], int col[], int docol)
    {
        col[start] = docol;
        for (auto it : adj[start])
        {
            if (col[it] == -1)
            {
                if (dfs(it, adj, col, !docol) == false)
                {
                    return false;
                }
            }
            else if (col[it] == col[start])
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<int> adj[])
    {
        int col[V];
        int docol = 0;
        for (int i = 0; i < V; i++)
            col[i] = -1;
        for (int i = 0; i < V; i++)
        {
            if (col[i] == -1)
            {
                if (dfs(i, adj, col, docol) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{

    return 0;
}