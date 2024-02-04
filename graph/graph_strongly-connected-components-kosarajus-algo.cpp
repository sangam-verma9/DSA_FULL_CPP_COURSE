#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfs(int i, vector<int> &visited, vector<vector<int>> &adj, stack<int> &st)
    {
        visited[i] = 1;
        for (auto it : adj[i])
        {
            if (!visited[it])
            {
                dfs(it, visited, adj, st);
            }
        }
        st.push(i);
    }
    void dfs2(int i, vector<int> &visited, vector<int> adjT[])
    {
        visited[i] = 1;
        for (auto it : adjT[i])
        {
            if (!visited[it])
            {
                dfs2(it, visited, adjT);
            }
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        // code here
        vector<int> visited(V, 0);
        // step1 store ele in stack in order of finishing time
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, adj, st);
            }
        }

        // reverse the graph edges
        vector<int> adjT[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = 0;
            for (auto it : adj[i])
            {
                adjT[it].push_back(i);
            }
        }

        // after reversing count the connected component according to stored stack
        int scc = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!visited[node])
            {
                scc++;
                dfs2(node, visited, adjT);
            }
        }
        return scc;
    }
};
int main()
{

    return 0;
}