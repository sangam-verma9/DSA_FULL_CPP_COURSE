#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, pair<int, int>>> pq;
        for (auto it : points)
        {
            int dis = it[0] * it[0] + it[1] * it[1];
            pq.push({dis, {it[0], it[1]}});
            if (pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while (!pq.empty())
        {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};
int main() {

return 0;
}