class Solution
{
public:
    void dfs(int i, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
    {
        visited[i] = 1;
        for (auto j : adj[i])
        {
            if (!visited[j])
            {
                dfs(j, adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        unordered_map<int, list<int>> adj;
        unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    adj[i + 1].push_back(j + 1);
                    adj[j + 1].push_back(i + 1);
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited);
                cnt++;
            }
        }
        return cnt;
    }
};