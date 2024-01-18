#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int tspDP(int pos, int mask, const vector<vector<int>> &graph, vector<vector<int>> &dp)
{
    int n = graph.size();

    // Base case: if all cities have been visited
    if (mask == (1 << n) - 1)
    {
        return graph[pos][0]; // Return the distance to the starting city
    }

    // Check if the result is already computed
    if (dp[pos][mask] != -1)
    {
        return dp[pos][mask];
    }

    int minDistance = INF;

    // Try visiting each unvisited city
    for (int nextPos = 0; nextPos < n; ++nextPos)
    {
        if ((mask & (1 << nextPos)) == 0)
        { // Check if the next city is not visited
            int newMask = mask | (1 << nextPos);
            int newDistance = graph[pos][nextPos] + tspDP(nextPos, newMask, graph, dp);
            minDistance = min(minDistance, newDistance);
        }
    }

    // Memoize the result
    return dp[pos][mask] = minDistance;
}

int main()
{
    // Example graph representing distances between cities
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};
    int n = graph.size();
    // Initialize the DP table with -1
    vector<vector<int>> dp(n, vector<int>(1 << n, -1));
    // Start the TSP DP from the starting city (pos = 0) with an empty mask (mask = 1)
    int minDistance = tspDP(0, 1, graph, dp);

    cout << "Optimal Distance: " << minDistance << endl;

    return 0;
}
