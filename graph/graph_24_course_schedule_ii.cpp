// https://leetcode.com/problems/course-schedule-ii/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfs(int node, unordered_map<int, list<int>> &adj, vector<bool> &visited, vector<bool> pathvisited, stack<int> &s)
    {
        visited[node] = 1;
        pathvisited[node] = 1;
        for (auto it : adj[node])
        {
            if (visited[it] == 0)
            {
                if (dfs(it, adj, visited, pathvisited, s))
                    return true;
            }
            else if (pathvisited[it] == 1)
            {
                return true;
            }
        }
        s.push(node);
        pathvisited[node] = 0;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, list<int>> adj;
        for (auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> visited(numCourses, 0);
        vector<bool> pathvisited(numCourses, 0);
        stack<int> s;
        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] == 0)
            {
                if (dfs(i, adj, visited, pathvisited, s))
                {
                    return {};
                }
            }
        }
        vector<int> ans;
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
int main()
{

    return 0;
}