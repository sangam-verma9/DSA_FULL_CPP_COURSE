#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int node, int visited[], vector<int> adj[], stack<int> &st)
    {
        visited[node] = 1;
        for (auto i : adj[node])
        {
            if (visited[i] == 0)
            {
                dfs(i, visited, adj, st);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<int> adj[]) int visited[V] = {0};
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i, visited, adj, st);
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
};
int main()
{

    return 0;
}