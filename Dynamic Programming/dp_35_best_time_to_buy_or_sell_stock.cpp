#include <bits/stdc++.h>
using namespace std;
//*** brute force ***
int maximumProfit(vector<int> &prices)
{
    // Write your code here.
    int ans = 0;
    int n = prices.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int d = prices[j] - prices[i];
            if (d > ans)
            {
                ans = d;
            }
        }
    }
    return ans;
}
//*** good ***
int maximumProfit(vector<int> &p)
{
    // Write your code here.
    int n = p.size();
    int arr[n];
    arr[0] = p[0];
    int mini = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        arr[i] = min(p[i - 1], mini);
        if (mini > p[i - 1])
        {
            mini = p[i - 1];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, p[i] - arr[i]);
    }
    return ans;
}
int main()
{

    return 0;
}