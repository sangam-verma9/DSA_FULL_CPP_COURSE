// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int maxsum = 0;
        for (int i = 0; i < k; i++)
        {
            maxsum += cardPoints[i];
        }
        int cnt = 1;
        int sum = maxsum;
        for (int i = 0; i < k; i++)
        {
            sum = sum + cardPoints[n - cnt] - cardPoints[k - cnt];
            maxsum = max(maxsum, sum);
            cnt++;
        }
        return maxsum;
    }
};
int main(){

return 0;
}