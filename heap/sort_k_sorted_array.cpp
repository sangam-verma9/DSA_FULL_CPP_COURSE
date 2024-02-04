#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nearlySorted(int arr[], int num, int K)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ans;
        for (int i = 0; i < num; i++)
        {
            if (pq.size() > K)
            {
                ans.push_back(pq.top());
                pq.pop();
            }
            pq.push(arr[i]);
        }
        while (!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
int main() {

return 0;
}