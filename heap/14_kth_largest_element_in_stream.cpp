// https://leetcode.com/problems/kth-largest-element-in-a-stream
#include <bits/stdc++.h>
using namespace std;
class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (auto i : nums)
        {
            if (pq.size() >= k)
            {
                pq.push(i);
                pq.pop();
            }
            else
            {
                pq.push(i);
            }
        }
    }

    int add(int val)
    {
        if (pq.size() < k)
        {
            pq.push(val);
            return pq.top();
        }
        pq.push(val);
        pq.pop();
        return pq.top();
    }
};

int main()
{

    return 0;
}