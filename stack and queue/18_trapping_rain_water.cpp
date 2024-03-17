// https://leetcode.com/problems/trapping-rain-water
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> mr(n);
        vector<int> ml(n);
        int temp = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            mr[i] = temp;
            temp = max(temp, height[i]);
        }
        temp = 0;
        for (int i = 0; i < n; i++)
        {
            ml[i] = temp;
            temp = max(temp, height[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int a = min(mr[i], ml[i]);
            int b = a - height[i];
            if (b > 0)
                ans += b;
        }
        return ans;
    }
};
int main(){

return 0;
}