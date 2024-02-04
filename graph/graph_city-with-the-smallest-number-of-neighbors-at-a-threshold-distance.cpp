#include <bits/stdc++.h>
using namespace std;
/*There are n cities numbered from 0 to n-1. Given the array
 edges where edges[i] = [fromi , toi ,weighti]  represents a
bidirectional and weighted edge between cities fromi and toi,
and given the integer distance Threshold. You need to find out
a city with the smallest number of cities that are reachable through
some path and whose distance is at most Threshold Distance, If there
are multiple such cities, our answer will be the city with the greatest number.
*/

class Solution
{
public:
    int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        for (auto i : edges)
        {
            dis[i[0]][i[1]] = i[2];
            dis[i[1]][i[0]] = i[2];
        }
        for (int i = 0; i < n; i++)
            dis[i][i] = 0;
        // now floyed warshall
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dis[i][k] + dis[k][j] < dis[i][j])
                    {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }
        // now find city which has min city which is at most threshold dis
        int city = 0, mincnt = n;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (dis[i][j] <= distanceThreshold)
                {
                    cnt++;
                }
            }
            if (cnt <= mincnt)
            {
                mincnt = cnt;
                city = i;
            }
        }
        return city;
    }
};
int main()
{

    return 0;
}