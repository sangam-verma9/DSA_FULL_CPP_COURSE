// https://www.codingninjas.com/studio/problems/kth-smallest-element_893056
#include<bits/stdc++.h>
using namespace std;
int kthSmallest(int n, int k, vector<int> nums)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(nums[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (nums[i] < pq.top())
        {
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}
int main(){

return 0;
}