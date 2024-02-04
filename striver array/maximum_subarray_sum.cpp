// https://www.codingninjas.com/studio/problems/maximum-subarray-sum_630526
#include<bits/stdc++.h>
using namespace std;
// **** kadan's algorithm *** 
//(basically says is sum is -ve so does not carry becase it not maximize of sum to start at this as new sum=0)
long long maxSubarraySum(vector<int> arr, int n)
{
    long long maxsum = 0;
    long long sum = 0;
    for (auto i : arr)
    {
        if (sum + i < 0)
        {
            sum = 0;
        }
        else
        {
            sum += i;
            maxsum = max(maxsum, sum);
        }
    }
    return maxsum;
}
int main() {

return 0;
}