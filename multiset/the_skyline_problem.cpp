// https://leetcode.com/problems/the-skyline-problem
// https://leetcode.com/problems/the-skyline-problem/solutions/2094329/c-easiest-explanation-ever-guaranteed-beginner-friendly-detailed-o-nlogn/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<vector<int>> ans;
        multiset<int> pq;
        pq.insert(0);
        vector<pair<int, int>> points;
        for (auto b : buildings)
        {
            points.push_back({b[0], -b[2]});
            points.push_back({b[1], b[2]});
        }
        sort(points.begin(), points.end());
        int onheight = 0;
        for (int i = 0; i < points.size(); i++)
        {
            int curpoint = points[i].first;
            int curheight = points[i].second;
            if (curheight < 0)
            {
                pq.insert(-curheight);
            }
            else
            {
                pq.erase(pq.find(curheight));
            }
            auto pqtop = *pq.rbegin();
            if (onheight != pqtop)
            {
                onheight = pqtop;
                ans.push_back({curpoint, onheight});
            }
        }
        return ans;
    }
};
int main(){

return 0;
}