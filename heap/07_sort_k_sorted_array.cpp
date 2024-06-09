// https://www.codingninjas.com/studio/problems/nearly-sorted_982937
#include<bits/stdc++.h>
using namespace std;
vector<int> nearlySorted(vector<int> array, int n, int k)
{
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(array[i]);
    }
    for (int i = k; i < n; i++)
    {
        pq.push(array[i]);
        ans.push_back(pq.top());
        pq.pop();
    }
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
int main(){

return 0;
}