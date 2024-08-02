#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        // code here
        if (start == end)
            return 0;
        queue<pair<int, int>> q;
        int mod = 100000;
        vector<int> steps(100000, 1e9); // steps[i]=steps to reach i
        steps[start] = 0;
        // pair of {steps,node}
        q.push({0, start});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int nodestep = it.first;
            int node = it.second;
            for (auto i : arr)
            {
                int newnode = (node * i) % mod;
                if (nodestep + 1 < steps[newnode])
                {
                    steps[newnode] = nodestep + 1;
                    if (newnode == end)
                        return steps[newnode];
                    q.push({steps[newnode], newnode});
                }
            }
        }
        return -1;
    }
};
int main()
{

    return 0;
}