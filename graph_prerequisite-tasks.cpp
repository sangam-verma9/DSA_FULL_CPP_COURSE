#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
    {
        vector<int> adj[N];
        for (auto it : prerequisites)
        {
            adj[it.first].push_back(it.second);
        }
        int indegree[N] = {0};
        for (int i = 0; i < N; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < N; i++)
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
        if (cnt == N)
            return true;
        return false;
    }
};
int main()
{

    return 0;
}