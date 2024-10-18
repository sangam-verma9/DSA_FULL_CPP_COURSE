// https://www.geeksforgeeks.org/problems/articulation-point-1/1
#include<bits/stdc++.h>
using namespace std;
// ArticulationPoint in a graph is a node after removing that node
// graph disconnected in more than one components
class Solution
{
private:
    int time = 0;
    void dfs(int node, int parent, vector<int> adj[], int tin[], int low[], vector<int> &vis, vector<int> &mark)
    {
        vis[node] = 1;
        tin[node] = low[node] = time;
        time++;
        int child = 0;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (!vis[it])
            {
                dfs(it, node, adj, tin, low, vis, mark);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1)
                {
                    mark[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && parent == -1)
        {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        // Code here
        vector<int> vis(V, 0);
        int tin[V]; // time of intersection
        int low[V]; // lowest time of intersection if any node is neighbor and alredy visited apart form parent then take min of min (node,tin neighbor not min neighbor as in bridges)
        vector<int> mark(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, adj, tin, low, vis, mark);
            }
        }
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (mark[i] == 1)
                ans.push_back(i);
        }
        if (ans.size() == 0)
            return {-1};
        return ans;
    }
};
int main(){

return 0;
}