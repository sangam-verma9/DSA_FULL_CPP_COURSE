// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
#include <bits/stdc++.h>
using namespace std;
/*
struct Item{
    int value;
    int weight;
};
*/
class Solution
{
public:
    bool static comp(pair<int, int> &x, pair<int, int> &y)
    {
        return ((1.0 * x.first) / x.second) >= ((1.0 * y.first) / y.second);
    }
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        // Your code here
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({arr[i].value, arr[i].weight});
        }
        sort(v.begin(), v.end(), comp);
        double ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i].second <= w)
            {
                ans += v[i].first;
                w -= v[i].second;
            }
            else
            {
                ans += ((1.0 * v[i].first) / v[i].second) * w;
                w = 0;
            }
            if (w == 0)
                break;
        }
        return ans;
    }
};
int main()
{

    return 0;
}