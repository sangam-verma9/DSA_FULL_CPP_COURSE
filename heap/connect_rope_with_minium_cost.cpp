#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }
        long long ans = 0;
        while (pq.size() > 1)
        {
            long long num1 = pq.top();
            pq.pop();
            long long num2 = pq.top();
            pq.pop();
            long long num = num1 + num2;
            ans += num;
            pq.push(num);
        }
        return ans;
    }
};
int main() {

return 0;
}