#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        for (auto i : arr)
        {
            if (pq.size() > k)
            {
                pq.pop();
            }
            pq.push({abs(x - i), i});
        }
        if (pq.size() > k)
            pq.pop();
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        // sort(ans.begin(), ans.end());
        return ans;
    }
};
int main() {

return 0;
}